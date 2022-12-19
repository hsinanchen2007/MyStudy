### 解题思路
动态规划的区间划分，在当前位置的可到达范围区间内搜索能跳跃到最远的方案，循环到最后能跳出该数组最大处之外

### 代码

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        
        int stepCounter = 0;
        int *firstPos = nums.data();
        int posOffset = 0;
        
        for (;;) {
            // 循环到最后能跳出该数组最大处之外
            if (firstPos[posOffset] >= nums.size() - 1 - posOffset) {
                stepCounter++;
                break;
            } else {
                int mostFar = 0;
                int newPosOffet;
                // 在当前位置的可到达范围区间内搜索能跳跃到最远的方案
                for (int i = posOffset + 1; i <= posOffset + firstPos[posOffset]; i++) {
                    int newFar = i + firstPos[i];
                    if (newFar >= mostFar) {
                        mostFar = newFar;
                        newPosOffet = i;
                    }
                }
                posOffset = newPosOffet;
                stepCounter++;
            }
        }

        return stepCounter;
    }
};
```