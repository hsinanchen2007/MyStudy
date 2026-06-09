看着挺唬人，最后结果一位数的话，一定是mod 9的余数

代码：
```
class Solution {
public:
    int addDigits(int num) {
        if(num)
            return num % 9 == 0 ? 9 : num % 9;
        return 0;
    }
};
```
