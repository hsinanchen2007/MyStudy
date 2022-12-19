### 解题思路
把每位都按倒序输出
![批注 2020-04-09 103030.png](https://pic.leetcode-cn.com/d614ea1a68f17cba4e27fad636a783157a35bfc2691373f79abf2086d68999b3-%E6%89%B9%E6%B3%A8%202020-04-09%20103030.png)
又快又小😄
### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
        int c = 0, m = 1, out = 0;
        int f = 1;
        if (x < 0) {
            f = -1;
        }
        while(x!=0) {
            c = x % 10;
            if((out>214748364||out==214748364&&c>7)||(out<-214748364||out==-214748364&&c<-8)){
                return 0;
            }
            out *= 10;
            out += c;
            x /= 10;
        }
        return out;
        
    }
};
```