### 解题思路
时间复杂度O(logn)
空间复杂度O(1)

### 代码

```cpp
class Solution {
public:
    int numberOfSteps (int num) {
        int step = 0;
        while (num) {
            if (num % 2 == 0) {
                num /= 2;
                ++step;
            }
            else {
                --num;
                ++step;
            }
        }
        return step;
    }
};
```