### 解题思路
参考[@xue-xi-test](/u/xue-xi-test/)的[思路](https://leetcode-cn.com/problems/beautiful-array/solution/fen-zhi-fa-by-xue-xi-test/)，递归实现

### 代码

```cpp
class Solution {
public:
    vector<int> helper(vector<int> nums, int left, int right){
        if(right-left <= 2){
            return nums;
        }
            
        else{
            vector<int> left_temp, right_temp, left_result, right_result;
            for(int i=left;i<right;i+=2){
                left_temp.push_back(nums[i]);
            }
            left_result = helper(left_temp, 0, left_temp.size());
            for(int i=left+1;i<right;i+=2){
                right_temp.push_back(nums[i]);
            }
            right_result = helper(right_temp, 0, right_temp.size());
            nums.clear();
            nums.insert(nums.end(), left_result.begin(), left_result.end());
            nums.insert(nums.end(), right_result.begin(), right_result.end());
            return nums;
        }
    }


    vector<int> beautifulArray(int N) {
        vector<int> nums;
        for(int i=1;i<=N;i++){
            nums.push_back(i);
        }
        auto res = helper(nums, 0, nums.size());
        return res;
    }    
};
```