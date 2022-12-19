### 解题思路
1、方法1：暴力法（知识点为集合去重）
2、方法2：排序 + 双指针

### 代码

```cpp
// 排序 + 双指针
// 难点: 去重操作
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        // 如果数组nums中的元素个数小于3个，结果为空
        if(nums.size() < 3)
            return res;

        // less<int>表示升序排序
        // greater<int>表示降序排序
        sort(nums.begin(), nums.end(), less<int>());


        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > 0)
                break;
            if(i > 0) {
                if(nums[i] == nums[i-1])
                    continue;
            }
            for(int j=i+1, k=nums.size()-1; j<k; ) {
                int temp = nums[j] + nums[k];
                if(temp > (-nums[i])) {
                    k--;
                }
                else if(temp < (-nums[i])) {
                    j++;
                }
                else {
                    vector<int> temp_res = {nums[i], nums[j], nums[k]};
                    res.push_back(temp_res);
                    // 注意：这里要加上去重操作
                    int left_num = nums[j], right_num = nums[k];
                    while(j < k && nums[j] == left_num)
                        j++;
                    while(j < k && nums[k] == right_num)
                        k--;
                }
            }
        }
        return res;
    }
};
```