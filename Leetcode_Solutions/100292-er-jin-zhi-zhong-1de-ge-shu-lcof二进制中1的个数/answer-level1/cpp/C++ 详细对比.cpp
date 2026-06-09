### 解题思路


### 代码

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        //注意点1 移位操作要比除法的效率高很多
        //注意点2 把一个整数减去1，再和原整数做与运算，就会把该整数最右边的一个1变成0
        int num=0;
        while(n>0){  //有几个1就循环几次，比移位循环快
            num++;
            n=n&(n-1);
        }
        return num;
    }
};
```