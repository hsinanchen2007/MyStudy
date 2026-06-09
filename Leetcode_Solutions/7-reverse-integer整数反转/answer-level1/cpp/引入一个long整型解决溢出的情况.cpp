### 解题思路
首先对于翻转之后不会溢出的整数用循环的方法，
遍历x的每一位数；
对于溢出的情况最后加判断即可。

时空复杂度均为100%
### 代码

```cpp
class Solution {
public:
int reverse(int x) {        
    long out = 0;
    while(x != 0){
        out = 10*out + x%10;
        x = (x - x%10)/10;
    }
    return (out > INT32_MAX || out < INT32_MIN) ? \
                0 : out;
}
};
```