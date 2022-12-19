```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int>mp;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {//遍历整个nums
            int number = target - nums[i];
            //计算nums[i]的另一半
            if (mp[number] == 0) {//另一半没出现过
                mp[nums[i]] = i + 1;//把num[i]的下标放到mp中
            }
            else {//另一半出现了，匹配成功
                return {mp[number] - 1, i};
            }
        }
        return {0, 0};
    }
};
```