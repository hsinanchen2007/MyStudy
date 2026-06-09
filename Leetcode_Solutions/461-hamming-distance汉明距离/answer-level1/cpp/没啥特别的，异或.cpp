### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int count = 0;

        while(z != 0)
        {
            int is = (z % 2 != 0) ? 1 : 0;
            count += is;
            z = z >> 1;
        }

        return count;
    }
};
```