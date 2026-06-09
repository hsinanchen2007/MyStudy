### 解题思路
接231题，在判断是2的n次方的基础上，进一步判断二进制表示的1是不是在奇数位上

### 代码

```cpp
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<0) return false;
        return (num&(num-1))==0&&(num&0b01010101010101010101010101010101)!=0;
    }
};
```