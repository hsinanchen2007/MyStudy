仅仅通过一个很简单的做法实现
```
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       vector<int> result;
       int len = nums.size();
       if(len < 2) return nums; 

        // sort
        sort(nums.begin(),nums.end());

        int temp = 0; // 防止>=3个相同的数存在
        bool status = false; // 防止第一位置的数字为0
        int i = 0;
        while(i < len){
            if(i + 1 < len){
                if(nums[i] == nums[i+1]){
                    status = true;  
                    temp  = nums[i];
                    i++;
                    continue;
                }
            }
            if(!status){
                result.push_back(nums[i]);
                i++;
                continue;
            }
            if(temp != nums[i]){
                result.push_back(nums[i]);
            }
            i++;
        }
        return result;
    }
};
```
