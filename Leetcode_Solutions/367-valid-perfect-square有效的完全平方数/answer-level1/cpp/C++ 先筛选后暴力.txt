### 解题思路
1.  num对10取余，若余数为2、3、7、8的数则不是平方数
2.  接下来暴力

4ms, 63.84%
8.1MB, 50.49%

### 代码

```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true; 
        if(num % 10 == 2 || num % 10 == 3 || num % 10 == 7 || num % 10 == 8) return false;
        for(int i = 0; i < 46341; i++)
            if(i*i == num) return true;
        return false;
    }
};
```