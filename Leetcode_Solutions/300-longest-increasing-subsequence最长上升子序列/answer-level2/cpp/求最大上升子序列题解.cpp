### 解题思路
1、从后往前记录每个元素的最长子序列
2、求数组中最长的子序列
3、动态规划的思想，每个元素的最长上升子序列是后面元素比当前元素最大的值得上升子序列

### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        vector<int> vec;
        for(int i=0;i<nums.size();i++){
            vec.push_back(1);
        }
        int len = nums.size();
        int tempmax = 0;
        for(int i=len-2; i>=0; i--){
            tempmax = 0;
            for(int j = i+1;j < len;j++){
                if(nums[j] > nums[i]){
                    if(vec[j] > tempmax){
                        tempmax = vec[j];
                    }
                }
            }
            if(tempmax != 0){
                vec[i] = 1 + tempmax;
            }
        }
        
        sort(vec.begin(), vec.end());

        return vec[len-1];
    }
};
```