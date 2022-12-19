```
class Solution {
public:
    bool valid(int n, int target) {
        if (target % 2 == 1) {
            return n % 4 == 1 || n % 4 == 2;
        }
        return n % 4 == 0 || n % 4 == 3;
    }
    int reachNumber(int target) {
        target = abs(target);
        int n = int(sqrt(2 * target));
        while (n * (n + 1) / 2 < target || !valid(n, target)) ++n;
        return n;
    }
};
```
![image.png](https://pic.leetcode-cn.com/91748328b4711732390dd3f4cf87ff421de0a96ac4f5181525e6a101e27cc4a4-image.png)
