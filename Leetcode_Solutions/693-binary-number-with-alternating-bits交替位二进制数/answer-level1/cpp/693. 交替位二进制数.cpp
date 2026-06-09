每次递归都将数据右移1位，然后利用位运算判断最后两位是否都是0或都是1。

``` c++ []
class Solution {
public:
    bool hasAlternatingBits(int n) {
        if(n <= 2) return true;
        else{
            if((n & 3) == 3 || ((~n) & 3) == 3) return false;
            else return hasAlternatingBits(n>>1);
        }
    }
};
```