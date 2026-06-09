### 解题思路
1. 对10取余，将每一位分别取出
2. 每次*10 将每一位前移
3. t/10 依次取位
4. 将i,t分别设为long 是防止溢位，为了便于后面使用if语句判断是否会溢出
5. INT_MAX = 2^31 − 1
### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
        long i = 0;
        long t = x;
        while(t)
        {
            i = i*10 + t%10;
            t = t/10;
        }
        if (i>INT_MAX || i<INT_MIN)
            return 0;
        else
            return i;
    }
};
```