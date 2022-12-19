### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int countSubstrings(string s) {

        int len=s.length();
        int sum=0;
        vector<vector<int>> dp(len,vector<int>(len));
        for(int i=0;i<len;i++){
            dp[i][i]=1;
            sum++;
            if(i+1<len&&s[i]==s[i+1]){
                dp[i][i+1]=1;
                sum++;
            }
        }
        for(int l=3;l<=len;l++){//外循环控制长度，注意可以等于len
            for(int i=0;i+l-1<len;i++){//内循环控制固定窗口滑动
                int j=i+l-1;
                if(s[i]==s[j]&&dp[i+1][j-1]==1){
                    dp[i][j]=1;
                    sum++;
                }
            }
        }
        return sum;
    }
};
```