### 解题思路
这个题考虑0的位置太烦了；
主要动态规划公式是 dp[i]=dp[i-1]+dp[i-2]，但是根据不同情况，进行判断修正：

 k = 10 * (s[N-1] - '0') + (s[N] - '0').
（1）k == 0，那么说明第N-1位和第N位为'00'。因为第'A'-'Z'无法与'00'对应，故f(N) = 0, 并返回f(N);
（2）0 < k && k < 10，那么说明第N-1位为'0'，第N位为'1'-'9'。此时f(N) = f(N-1);
（3）k == 10 && k == 20，那么说明第N-1位为'1'或'2'，第N位为'0'。此时f(N) = f(N-2);
（4）10 < k && k <= 26 && k != 20，那么此时f(N) = f(N-1) + f(N-2);
（5）k > 26 && s[N] == '0'，此时无法编码，f(N) = 0，并返回f(N);
（6）k > 26 && s[N] != '0'，此时f(N) = f(N-1)。


### 代码

```cpp
class Solution {
public:
    int numDecodings(string s) {
        int len=s.size();
        if(len==0||s[0]=='0') return 0;
        vector<int> dp(len,0);
        for(int i=0;i<len;i++){
            if(i==0){
                dp[0]=1;
            } 
            else if(i==1){
                int c=s[i]-'0';                   //本位
                int t=s[i-1]-'0';                 //上一位
                int k=t*10+c;                     //最近两位组成的数
                if(k>26&&c==0) return 0;
                if(k==10||k==20) dp[1]=dp[0];
                else if(k<=26) dp[1]=dp[0]+1;
                else if(k>26) dp[1]=dp[0];
            }else {
                int c=s[i]-'0';                   //本位
                int t=s[i-1]-'0';                 //上一位
                int k=t*10+c;                     //最近两位组成的数
                if(k>26&&c==0||k==0) return 0;
                if(k==10||k==20) dp[i]=dp[i-2];
                else if(k<=26&&k>10) dp[i]=dp[i-1]+dp[i-2];
                else if(k<10||k>26) dp[i]=dp[i-1];
            }
        }
        return dp[len-1];
    }
};
```


好吧，是我太菜了；为什么要算出26去比较，还去看0
```cpp
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int pre = 1, curr = 1;//dp[-1] = dp[0] = 1
        for (int i = 1; i < s.size(); i++) {
            int tmp = curr;
            if (s[i] == '0')
                if (s[i - 1] == '1' || s[i - 1] == '2') curr = pre;
                else return 0;
            else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))
                curr = curr + pre;
            pre = tmp;
        }
        return curr;
    }
};
```
