```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
```
摩尔投票法
```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //if(nums.size() == 1) return nums[0];
       int count=1;
       int result = nums[0];
       for(int i=1; i<nums.size(); i++)
       {
           if(count == 0) result = nums[i];
           if(nums[i] == result) count++;
           else
                count--;
       }
       return result;
    }
};
```
