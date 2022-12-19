### 解题思路

审题，

1. 取值范围是 [-1e7, 1e7] 。 那么就可以不用考虑INT的最大值和最小值了。
2. 要注意负值
3. 由于我的退出循环是>0,因此要特别关照0.

### 代码

```cpp
class Solution {
public:
    string convertToBase7(int num) {
        
        if ( num == 0) return "0";

        string s;
        int flag = 0;
        if (num < 0 ){
            flag = 1;
            num = - num;
        } 
        
        char rest;
        while ( num > 0){
            rest = num % 7 + '0';
            num = num / 7;
            s = rest + s;
        }
        if (flag) s = '-' + s;
        return s;
        
    }
};
```