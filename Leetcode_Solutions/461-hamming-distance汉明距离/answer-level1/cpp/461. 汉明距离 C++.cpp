### 解题思路
1.汉明距离值两个数字的对应二进制不同的个数，因此就是将两个数做异或运算取1的个数即为汉明距离。

### 代码

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int distance = x^y;
        int count = 0;
        while(distance)
        {
            if(distance & 1) count++;
            distance >>= 1;
        }
        return count;
    }
};
```