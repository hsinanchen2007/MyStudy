### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int t = x^y;
        int ret = 0;
        while (t) {
            t &= (t-1); //消去最后一位1
            ++ret;
        }
        return ret;
    }
};
```