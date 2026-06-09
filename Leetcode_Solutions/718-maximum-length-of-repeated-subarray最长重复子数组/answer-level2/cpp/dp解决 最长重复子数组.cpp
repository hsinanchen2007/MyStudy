### 解题思路
    做个总结，便于自己的复习。
    感谢大佬们的思路方法 ~ ~ ~
### 代码

```cpp
/*暴力解法：超时*/
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int lenA = A.size(),lenB = B.size(),maxlen = 0;
        int i,j,k,m;
        for(i = 0;i < lenB;i++){
            for(j = 0;j < lenA;j++){
                if(A[i] != B[j]) continue;
                k = i,m = j;    //记录此刻i,j的位置（便于回退）
                while(k < lenB && m < lenA && A[k] == B[m]) k++,m++;
                maxlen = max(maxlen,k - i);
            }
        }
        return maxlen;
    }
};

/*二维dp*/
class Solution{
public:
    int findLength(vector<int>& A,vector<int>& B){
        int maxlen = 0,m = A.size(),n = B.size();
        vector<vector<int>> dp(m + 1,vector<int>(n + 1,0));
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(A[i] == B[j])
                    dp[i+1][j+1] = dp[i][j] + 1;
                maxlen = max(maxlen,dp[i+1][j+1]);
            }
        }
        return maxlen;
    }
};



/*这是看的大佬的思路和代码，链接如下：
https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/solution/c-dp-by-yuexiwen-2/

定义dp[i][j]标识分别以A[i]和B[j]结尾的最长相等子数组长度
如果A[i] != B[j] 则dp[i][j] = 0;
如果A[i] == B[j] 则dp[i][j] = dp[i-1][j-1] + 1;
由于dp[i][j]只与上一行的dp[i-1][j-1]相关，因此，从后向前迭代j时，可以将二维数组简化到1维
*/

/*优化后的一维dp*/
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int maxlen = 0,m = A.size(),n = B.size();
        vector<int> dp(n+1, 0);
        for (int i = 0; i < m; i++) {
            for (int j = n-1; j >= 0; j--) {
                dp[j+1] = A[i] == B[j] ? dp[j] + 1 : 0;
                maxlen = max(maxlen, dp[j+1]);
            }
        }
        return maxlen;
    }
};
```