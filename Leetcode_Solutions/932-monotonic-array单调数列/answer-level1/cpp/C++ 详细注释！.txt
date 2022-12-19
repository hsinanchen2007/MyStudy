### 解题思路
一次遍历，每次计算上一步和当前步的增量乘积，如果单调则乘积大于 0，否则小于 0。

### 代码

```cpp
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        // 1. 上一步的增量 A[i] - A[i - 1]
        int pre_delta = 0;
        
        // 2. 当前步增量 A[i + 1] - A[i] 
        int cur_delta = 0;

        for (int i = 0; i < A.size() - 1; i++) {
            // 3. 相同元素不计算增量
            if (A[i] == A[i + 1]) 
                continue;

            if (A[i] != A[i + 1]) {
                // 4. 计算当前增量
                cur_delta = A[i + 1] - A[i];
                
                // 单调递增：pre_delta > 0，cur_delta > 0，两者相乘仍然 > 0
                // 单调递减：pre_delta < 0，cur_delta < 0，两者相乘仍然 > 0
                // 所以如果两个增量相乘 < 0，则说明数组不单调
                if (pre_delta * cur_delta < 0)
                    return false;
                
                // 5. 更新上一步增量，为下次计算做准备
                pre_delta = cur_delta;
            }
        }

        // 6. 每次增量相乘都 > 0，说明数组单调
        return true;
    }
};
```