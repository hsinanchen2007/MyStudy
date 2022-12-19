### 解题思路
small初始化为1,big初始化为2,如果从small到big的序列和大于target，则可以从序列和中减去较小值，`sequenceSum -= small`,`small`加一。如果small到big的序列和小于target，则可以从序列和中加上较大值`sequenceSum += big`,`big`加一。如果`sequenceSum == target`那么将当前序列加到结果中。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        if(target < 3) return res;

        int small = 1;  // 连续序列的左端点
        int big = 2;    // 连续序列的右端点
        int mid = (1 + target) / 2; // 因为至少有两个数，small的最大值为mid
        int sequenceSum = small + big;  // 序列和
        

        while(small < mid){
            if(sequenceSum == target){
                // 如果当前序列和等于目标值，那么将当前序列存放到结果中
                res.emplace_back(endToSequence(small, big));
            }
            while(sequenceSum > target && small < mid){
                // 如果当前序列和比目标值大，通过增加small来减小序列和
                sequenceSum -= small;   // 当前序列和减small
                ++small;    // small值加一

                if(sequenceSum == target){
                    // 检查当前序列值和是否与目标值相等
                    res.emplace_back(endToSequence(small, big));
                }   
            }
            // 如果当前序列和比目标值小，通过增加big来增大序列和
            ++big;  
            sequenceSum += big;
        }
        return res;
    }

    vector<int> endToSequence(int small, int big){
        // 给定起始点，生成连续序列
        vector<int> s;
        for(int i = small; i <= big; ++i){
            s.emplace_back(i);
        }
        return s;
    }
};
```