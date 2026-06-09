### 解题思路
这里其实用的是将x先反向输出，然后看这一个反向输出和原来的数是不是一致的。

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        long long t=0;//t里存反向输出的值
        int y=x;//y存原有的值
        if(x<0) return false;//如果是负数直接报错
        while(x){
            t=10*t+x%10;
            x/=10;
        }
        if(t==y) return true;
        else return false;
    }
};
```