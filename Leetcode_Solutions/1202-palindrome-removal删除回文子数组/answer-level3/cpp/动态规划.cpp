第三题：这个题太难了，逐行看别人的代码，才理解如何动态规划，具体看注释

执行用时 : 148 ms, 在所有 C++ 提交中击败了66.67%的用户
内存消耗 : 11.4 MB, 在所有 C++ 提交中击败了38.89%的用户

class Solution {
public:
    int minimumMoves(vector<int>& arr)
    {
        int dp[101][101]; //dp[i][j]表示位置i到j需要的删除次数
        int lenArr = arr.size();

        //计算长度为1的子串的删除次数
        for (int i = 0; i < lenArr; i++) {
            dp[i][i] = 1;
        }

        //计算长度为2的子串的删除次数
        for (int i = 0; i < lenArr - 1; i++) {
            if(arr[i] == arr[i + 1]) {
                dp[i][i + 1] = 1;
            } else {
                dp[i][i + 1] = 2;
            }
        }

        //计算长度大于等于3的子串的删除次数
        for (int len = 3; len <= lenArr; len++) {
            for (int i = 0; i < lenArr - len + 1; i++) {
                int idxEnd = i + len - 1;
                
                //检查回文条件
                if (arr[i] == arr[idxEnd]) {
                    dp[i][idxEnd] = dp[i + 1][idxEnd - 1];
                    continue;
                }
                
                //初始赋为最大值len
                dp[i][idxEnd] = len;
                //把i~idxEnd分为两段: i~(i+j)和(i+j+1)~idxEnd分为两段，看看删除次数是否能缩小
                for (int j = 0; j < (len - 1) ; j++) {
                    if (dp[i][idxEnd] > dp[i][i + j] + dp[i + j + 1][idxEnd]) {
                        dp[i][idxEnd] = dp[i][i + j] + dp[i + j + 1][idxEnd];
                    }
                }
            }
        }

        return dp[0][lenArr - 1];
    }
};
