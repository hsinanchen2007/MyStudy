### 解题思路
动态规划  dp(n) = dp(n-1) + dp(n-2);
特殊0的处理 10 20 等能组合的 dp(n) = dp(n-2); else return 0;

### 代码

```cpp
class Solution {
public:
    int numDecodings(string s) {
        ios::sync_with_stdio(false);
        vector<int> cnt(s.size()+1,0);   //第一个为0
        if(s[0]=='0'||s.size()==0) return 0;
        cnt[0] = 1;
        cnt[1] = 1;
        for(int i=1;i<s.size();i++)
        {
            int temp = ((int)(s[i-1]-'0'))*10 + (int)(s[i]-'0');
            cout << "num" <<i <<" : " <<temp <<endl;
            if(s[i]!='0')
            {
                //非0 能合并
                if(temp>10&&temp<=26) cnt[i+1] = cnt[i]+cnt[i-1];
                //非0 不能合并
                else cnt[i+1] = cnt[i];
            }
            // s[i] == '0'
            else
            {
                if(temp == 0 || temp>20) return 0;
                else if(temp==10||temp==20) cnt[i+1] = cnt[i-1]; 
            } 
        }
        return cnt[s.size()];
    }
};
```