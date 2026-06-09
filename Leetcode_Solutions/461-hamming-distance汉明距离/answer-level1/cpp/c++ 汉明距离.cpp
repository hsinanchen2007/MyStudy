### 解题思路
按位异或（^）:00001001^00000101=00001100 1^1=0 0^0=0 0^1=1
移位操作（<< >>）:<<左移 >>右移 整体左右移 不要用反
按位与（&）: 1&1=1 1&0=0 0&0=1
### 代码

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int dis = x^y;
        int cnt = 0;
        while(dis)
        {
            if(dis & 1) cnt++;
            dis >>= 1;
        }
        return cnt;
    }
};
```