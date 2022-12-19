### 解题思路
枚举法&动态规划

### 代码

```java []
class Solution {
    public int numDecodings(String ss) {
        // 枚举dp
        int N = ss.length();
        // f[i]: 前i个字符的解法数量
        // case I: 考虑最后一位
        // case II: 考虑最后两位
        long []f = new long[N+1];
        f[0] = 1;
        int P = (int)Math.pow(10, 9)+7;
        char []s = ss.toCharArray();
        for(int i=1; i<=N; ++i){
            long cnt = getCnt(s[i-1]);
            f[i] += cnt*f[i-1];
            if(i > 1){
                cnt = getCnt2(s[i-2], s[i-1]);
                f[i] += cnt * f[i-2];
            }
            f[i] = f[i]%P;
        }
        return (int)f[N];
    }

    // 一个字符的情况
    long getCnt(char c){
        switch(c){
            case '0': return 0;
            case '*': return 9;
            default : return 1;
        }
    }

    // 二个字符的情况
    long getCnt2(char c2, char c1){
        if(c2 == '0' || (c2>='3' && c2<='9')){
            return 0;
        }
        if(c2 == '1'){
            if(c1 == '*')
                return 9;
            else
                return 1;
        }
        if(c2 == '2'){
            if(c1 == '*')
                return 6;
            else if(c1>='0' && c1<='6')
                return 1;
            else
                return 0;
        }
        if(c2 == '*'){
            if(c1 == '*')
                return 15;
            else if(c1>='0' && c1<='6')
                return 2;
            else
                return 1;
        }
        return 0;
    }
}
```
```python []
class Solution:
    def numDecodings(self, s: str) -> int:
        N = len(s)
        f = [0 for _ in range(N+1)]
        f[0] = 1
        P = 10**9+7
        for i in range(N+1):
            cnt = self.getCnt(s[i-1])
            f[i] += cnt*f[i-1]
            if i > 1:
                cnt = self.getCnt2(s[i-2], s[i-1])
                f[i] += cnt*f[i-2]

        return f[N]%P

    def getCnt(self, c):
        if c == '0':
            return 0
        elif c == '*':
            return 9
        else:
            return 1

    def getCnt2(self, c2, c1):
        if c2 == '0' or ('3'<=c2 and c2<='9'):
            return 0
        elif c2 == '1':
            if c1 == '*':
                return 9
            else:
                return 1
        elif c2 == '2':
            if c1 == '*':
                return 6
            elif '0'<=c1 and c1<='6':
                return 1
            else:
                return 0
        
        elif c2 == '*':
            if c1 == '*':
                return 15
            elif '0'<=c1 and c1<='6':
                return 2
            else:
                return 1


        return 0
```
```c++ []
typedef long long ll;
class Solution {
public:
    int numDecodings(string s) {
        // 相比较Decode Ways I, 多了*号
        // case I
        // f[i]定义数字串前i个数字的解法方式有i种
        // case I: 最后一个字符翻译成字母
        // S[i-1] = '0', 不能翻译为字母
        // S[i-1] \in {1~9},  翻译方式有1种, 共有f[i-1]种方式
        // S[i-1]='*', 9种可能的翻译方式, 共有9*f[i-1]种方式
        
        // case II: 最后两个字符
        // S[i-2] = '0'
        const int P = pow(10, 9)+7;
        int N = s.size();
        ll cnt;
        vector<ll> f = vector<ll>(N+1, 0);
        f[0] = 1;
        for(int i=1; i<=N; ++i){
            f[i] = 0;
            cnt = getCnt(s[i-1]);
            f[i] += cnt*f[i-1];
            if(i > 1){
                cnt = getCnt2(s[i-2], s[i-1]);
                f[i] += cnt*f[i-2];
            }
            f[i] = f[i] % P;
        }

        return f[N];        
    }

private:
    ll getCnt(char c){
        switch(c){
            case '0': return 0;
            case '*': return 9;
            default : return 1; 
        }
    }

    ll getCnt2(char c2, char c1){
        if(c2 == '0' || (c2 >= '3' && c2 <= '9'))
            return 0;

        if(c2 == '1'){
            if(c1 == '*')
                return 9;
            else
                return 1;
        }

        if(c2 == '2'){
            if(c1 == '*')
                return 6;
            else if(c1 >= '0' && c1<='6')
                return 1;
            else
                return 0;
        }

        if(c2 == '*'){
            if(c1 >='0' && c1<='6')
                return 2;
            else if(c1>='7' && c1<='9')
                return 1;
            else
                return 15;
        }
        return 0;
    }
};
```