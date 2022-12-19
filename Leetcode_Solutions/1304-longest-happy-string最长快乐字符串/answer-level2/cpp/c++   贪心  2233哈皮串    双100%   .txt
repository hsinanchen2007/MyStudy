### 解题思路
此题思路很简单，利用贪心策略，简单来说就是在不构成'aaa'样式的同时，每次拿剩余个数最多的那一个，直至满足终止条件
**步骤**：
如果a+b+c<2,**直接返回结果**(因为总数小于2的话，后面不好处理，所以拿出来特判，直接返回)
**否则**：
1. **如果a最大**
    1. 如果字符串后两个不全是'a',则直接选择a
    2. 如果字符串后两个全是'a'，则选择b和c中较大的那一个
2. **如果b最大**
    1. 如果字符串后两个不全是'b',则直接选择b
    2. 如果字符串后两个全是'b'，则选择a和c中较大的那一个
3. **如果c最大**
    1. 如果字符串后两个不全是'c',则直接选择c
    2. 如果字符串后两个全是' c'，则选择a和b中较大的那一个

**终止条件**：
1. a=b=c=0
2. a=b=0并且字符串最后两个都为'c'
3. a=c=0并且字符串最后两个都为'b'
4. b=c=0并且字符串最后两个都为'a'


![QQ图片20200405130935.png](https://pic.leetcode-cn.com/6c17c88d58ebe22a0c3cc48360785fc428a9d331189640adb96351465a365a80-QQ%E5%9B%BE%E7%89%8720200405130935.png)



### 代码

```cpp
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string s = "";
        if(a+b+c<2) {
            if(a) s+='a';
            else if(b) s+'b';
            else if(c) s+'c';
            return s;
        }
        while(1) {
            int n = s.length();
            //终止条件
            if(a==0 && b==0 && c==0)
                break;
            else if(a==0 && b==0 && s[n-1]==s[n-2] && s[n-1]=='c')
                break;
            else if(b==0 && c==0 && s[n-1]==s[n-2] && s[n-1]=='a')
                break;
            else if(a==0 && c==0 && s[n-1]==s[n-2] && s[n-1]=='b')
                break;
            
 
            if(a >= b && a >= c && a>0) {
                if(n < 2 || s[n-1] != 'a' || s[n-2] != 'a')
                {   s += 'a'; a--; }
                else if(b>=c && b>0)
                { s += 'b'; b--; }
                else if(c>0)
                { s += 'c'; c--; }
            }
            else if(b >= c && b >= a && b>0) {
                if(n < 2 || s[n-1] != 'b' || s[n-2] != 'b')
                { s += 'b';  b--; }
                else if(a >= c && a>0)
                { s += 'a';  a--; }
                else if(c>0)
                {  s += 'c'; c--; }
            }
            else if(c>=a && c>=b && c>0) {
                if(n < 2 || s[n-1] != 'c' || s[n-2] != 'c')
                { s += 'c'; c--; }
                else if(a>=b && a>0)
                { s += 'a'; a--; }
                else if(b>0)
                { s += 'b'; b--; }
            }
        }
        return s;
    }
};
```