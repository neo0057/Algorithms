##include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root->val == p->val || root->val == q->val) return root;
        TreeNode *leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightLCA = lowestCommonAncestor(root->right, p, q);
        if(leftLCA and rightLCA) return root;
        return (leftLCA) ? leftLCA : rightLCA;
    }
};

int main() {

    // driver code here.
    return 0;
}