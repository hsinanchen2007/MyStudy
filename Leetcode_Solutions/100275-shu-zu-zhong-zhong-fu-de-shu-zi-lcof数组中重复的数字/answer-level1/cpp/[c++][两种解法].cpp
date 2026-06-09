### 解题思路


### 代码
解法一
```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> st;
        for(auto num:nums){
            if(st.count(num)){
                return num;
            }
            st.insert(num);
        }
        return -1;
    }
};
```

解法二
```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(i==nums[i]) continue;
            if(nums[i]==nums[nums[i]]) return nums[i];
            while(nums[i]!=nums[nums[i]]) swap(nums[i],nums[nums[i]]);
        }
        return -1;
    }
};
```