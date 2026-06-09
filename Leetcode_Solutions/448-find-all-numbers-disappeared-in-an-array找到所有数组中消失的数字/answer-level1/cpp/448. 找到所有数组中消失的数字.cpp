## 鸽巢理论
**将每个鸽子与其对应的巢里的另一个鸽子交换，最后查看哪些鸽子和巢不匹配**
```cpp
class Solution {
public: 
    // 鸽巢理论：我们要想办法将鸽子放到对应的窝里，nums[index] 的鸽子应该在 nums[index] - 1 下标的窝里；
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int len = nums.size();
        for(int i=0; i<len; i++){
            while(nums[i] != i+1 && nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }
            fun(nums, i);
        }
        for(int i=0; i<len; i++){
            if(nums[i]!=i+1){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
```