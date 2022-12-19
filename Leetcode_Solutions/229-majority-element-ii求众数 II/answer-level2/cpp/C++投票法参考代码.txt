![image.png](https://pic.leetcode-cn.com/7b42c846b0dc0006f633b3abfdee3837f1abb0fb0bf747e78347f0130416c2a3-image.png)
```
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int lens = nums.size();
        vector<int> res;
        if(!lens)   return res;
        if(lens == 1)   return nums;
        int  time1 = 0, time2 = 0, temp1, temp2;
        for(int i = 0; i < lens; i++){
            if(!time1 && temp2 != nums[i]){
                temp1 = nums[i];
                time1 = 1;
            }
            else if(!time2 && time1 && temp1 != nums[i]){
                temp2 = nums[i];
                time2 = 1;
            }
            else if(nums[i] == temp1)
                time1++;
            else if(nums[i] == temp2)
                time2++;
            else{
                time1--;
                time2--;
            }
        }
        time1 = time2 = 0;
        for(auto i:nums){
            if(i == temp1)
                time1++;
            if(i == temp2)
                time2++;
        }
        if(time1 > lens/3) res.push_back(temp1);
        if(temp2 != temp1 && time2 > lens/3)  res.push_back(temp2);
        return res;
    }
};
```
