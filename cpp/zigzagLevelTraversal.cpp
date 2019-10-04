#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


struct Node {
    int level;
    TreeNode *node;
    Node(int level, TreeNode *node) {
        this->level = level;
        this->node = node;
    }
};

class Solution {
public:
    int max(int a, int b) {
        return (a > b) ? a : b;
    }
    int height(TreeNode *root) {
        if(root == NULL) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int h = height(root);
        bool flag = false;
        if(h == 0) return vector<vector<int>>();
        queue <Node*> nodeQueue;
        vector<vector<int>> res(h);
        stack<int> tmpStack;
        int curr_level = 1;

        nodeQueue.push(new Node(1, root));

        while(nodeQueue.empty() == false) {
            Node* qNode = nodeQueue.front();
            nodeQueue.pop();
            if(qNode->level == curr_level + 1) tmpStack.push(qNode->node->val);
            else {
                if(tmpStack.size() > 0) {
                    int tmp_size = tmpStack.size();
                    for(int j = 0; j < tmp_size; j++) {
                        res[curr_level].push_back(tmpStack.top());
                        tmpStack.pop();
                    }
                    curr_level = qNode->level;
                }
                res[qNode->level - 1].push_back(qNode->node->val);
            }
            if(qNode->node->left != NULL) nodeQueue.push(new Node(qNode->level + 1, qNode->node->left));
            if(qNode->node->right != NULL) nodeQueue.push(new Node(qNode->level + 1, qNode->node->right));
        }
        if(tmpStack.size() > 0) {
            int tmp_size = tmpStack.size();
            for(int j = 0; j < tmp_size; j++) {
                res[curr_level].push_back(tmpStack.top());
                tmpStack.pop();
            }
        }
        return res;
    }
};
int main() {
    // write driver code here

    return 0;
}