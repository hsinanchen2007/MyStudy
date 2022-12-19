### 解题思路
简单题，第一次100%所以写一下：
1）计算机存储整数是补码的形式，所以32位整数真值范围是-2147483648~2147483647
2）注意越界的界定，乘10前要检测下，乘10后加上的一位也要检测下
### 代码

```cpp
class Solution {
public:
     int reverse(int x) {
        int re(0);
        if(x==0) return 0;
        if(x<0){
            while(x){
                if(-re>INT_MAX/10||(-re==INT_MAX/10&&-x%10>8)) return 0;
                re=re*10+x%10;
                x=x/10;
            }
            return re;
        }
        while(x){
            if(re>INT_MAX/10||(re==INT_MAX/10&&x%10>7)) return 0;
            re=re*10+x%10;
            x=x/10;
        }
        return re;
    }
};
```