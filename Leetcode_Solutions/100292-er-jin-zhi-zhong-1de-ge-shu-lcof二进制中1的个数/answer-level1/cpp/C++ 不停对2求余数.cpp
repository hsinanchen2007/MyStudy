### 解题思路
关注微信公众号'码农黑板报' 获取更多题解
![image.png](https://pic.leetcode-cn.com/41f00f007b09bcdbfa5e96f9673e58d13069ccf2a1260e9c4a90a954e15d5812-image.png)


### 代码

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n) {
            if (n % 2 == 1) {
                count++;
            }
            n = n/2;
        }
        return count;
    }
};
```