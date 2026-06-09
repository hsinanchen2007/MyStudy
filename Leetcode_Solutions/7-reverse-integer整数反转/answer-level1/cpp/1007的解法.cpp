### 解题思路
此处撰写解题思路
很简单的C++代码，用long型存储y值，应为long型是8字节，64位的，而因为给定的输入是int类型，对于long型来说不会超出大小，所以也没用到数组。比较巧合，毕竟x给定的是Int类型
### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
        long y = 0;
        while(x){
            y = y*10 + x%10;
            x = x / 10;
        }
        if(y > pow(2, 31)-1 || y < -1*pow(2, 31))
            return 0;
        return y;
    }
};
```