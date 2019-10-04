##include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int min(int a, int b) {
        return (a < b) ? a : b;
    }
    int coinChange(vector<int>& coins, int amount) {
        int *dp = (int *) malloc( (amount + 1) * sizeof(int));
        for(int i = 0; i <= amount; i++) dp[i] = INT_MAX;
        dp[0] = 0;
        sort(coins.begin(), coins.end());

        for(int i = 1; i <= amount; i++) {
            for(int j = 0; j < coins.size(); j++) {
                if(i >= coins[j]) {
                    int sub_res = dp[i - coins[j]];
                    if(sub_res != INT_MAX and sub_res + 1 < dp[i]) dp[i] = sub_res + 1;
                }
            }
        }
        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};

int main() {

    // driver code here.
    return 0;
}