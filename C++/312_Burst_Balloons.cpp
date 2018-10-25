// https://leetcode.com/problems/burst-balloons/description/

//Complexity of O(n^3) & O(n^2) - fastest solution possible *dabs*

class Solution {
public:
    int maxCoins(vector<int>& inums)
    {
        int nums[inums.size() + 2];
        int n = 1;
        for(int x : inums)
            if (x > 0)
                nums[n++] = x;

        nums[0] = nums[n++] = 1;

        int dp[n][n] = {};

        for(int k = 2; k < n; k++)
        {
            for(int left = 0; left < n - k; left++)
            {
                int right = left + k;

                for (int i = left + 1; i < right; i++)
                    dp[left][right] = max(dp[left][right], nums[left] * nums[i] * nums[right] + dp[left][i] + dp[i][right]);
            }
        }

        return dp[0][n-1];
    }
};
