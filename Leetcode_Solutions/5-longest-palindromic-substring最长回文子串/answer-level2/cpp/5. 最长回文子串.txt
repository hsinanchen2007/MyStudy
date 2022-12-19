中心扩散法就不说了，本质上就是遍历所有元素，以它为中心向两边扩散。但是扩散的时候需注意要用两种方式扩散，分别是最终为奇数的扩散和最终为偶数的扩散；

这道题的DP解法和中心扩散没有半毛钱关系，不能通过空间换时间使中心扩散法速度加快，等于说这道题的DP并不是中心扩散法的改进，而是暴力搜索的改进。最关键的其实就是状态转移方程和初始状态了，不过也很简单，
1. 状态转移方程：如果s[i]==s[j]且dp[i+1][j-1]=1的话，说明dp[i][j]=1即[i,j]区间是回文子串
2. 初始状态：有两个，分别是子串为奇数时和子串为偶数时
3. 从初始状态开始，往上长就行了

这道题里，不知道是我DP写的不够好还是怎么的，中心扩散法用了几十毫秒，但是DP用了三百多毫秒。我跑了别人的DP代码用时也是这个量级。

这道题怎么说呢，DP的空间换时间，体现在它可以比暴力搜索更快，但是真不一定比中心扩散更快。


```cpp []
//DP
class Solution {
public:
    string longestPalindrome(string s) {
        int N = s.size();
        if(N<2)
            return s;
        int maxLen(0), maxLeft;
        vector<vector<int>> dp(N,vector<int>(N,0));
        for(int len = 1;len<=N;len++){//子串长度从1开始长到N
            for(int i =0; i + len -1 < N; i++){//遍历从i开始，长度为len的子串
                if(len==1){
                    dp[i][i+len-1]=1;
                    maxLen = len;
                    maxLeft = i;
                    continue;
                }
                if(len==2){
                    if(s[i]==s[i+len-1]){
                        dp[i][i+len-1]=1;
                        maxLen = len;
                        maxLeft = i;
                        continue;
                    }
                }
                if(s[i]==s[i+len-1] && dp[i+1][i+len-1-1] ){
                    dp[i][i+len-1]=1;
                    maxLen = len;
                    maxLeft = i;
                }
            }
        }

        return s.substr(maxLeft,maxLen);
    }
};
```
```cpp []
//中心扩散
class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0;
        int maxLeft = 0;
        int maxRight = 0;
        int left, right, curLen;
        int N = s.size();

        if(N<2)
            return s;        

        for(int i = 0;i<s.size();i++){
            left = i;//子串长度为偶数
            right = i+1;
            while(left >=0 && right <N){
                curLen = right - left+1;
                if(s[left] != s[right])
                    break;
                if( curLen > maxLen){
                    maxLen = curLen;
                    maxLeft = left;
                    maxRight = right;
                }
                left--;
                right++;    
            }

            left = i;//子串长度为奇数
            right = i;
            while(left >=0 && right <N){
                curLen = right - left+1;
                if(s[left] != s[right])
                    break;
                if( curLen > maxLen){
                    maxLen = curLen;
                    maxLeft = left;
                    maxRight = right;
                }
                left--;
                right++;    
            }
        }

        return s.substr(maxLeft,maxLen);
    }
};
```