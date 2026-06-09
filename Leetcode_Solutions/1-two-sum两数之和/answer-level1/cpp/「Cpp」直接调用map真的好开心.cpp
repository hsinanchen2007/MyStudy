### 解题思路

之前用C，只能自己手撸哈希表，强行给自己加难度。现在用Cpp，直接调用容器的`unordered_map`真的好开心。

尤其是赋值语法`x[key] = value`，简洁又容易阅读

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> idx_map;
        vector<int> result = {0,0};
        for ( int i = 0; i < nums.size(); i++){
            if (idx_map.count(target - nums[i]) > 0){
                result[0] = i;
                result[1] = idx_map[target-nums[i]];
                break;
            } else{
                idx_map[nums[i]] = i;
            }
        }
        return result;

        
    }
};
```