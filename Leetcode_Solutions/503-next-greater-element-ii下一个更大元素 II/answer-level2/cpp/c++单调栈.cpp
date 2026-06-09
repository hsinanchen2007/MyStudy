


```c++ []
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size());
        int stack[2*nums.size()+2],sz = 0;
        for(int i = nums.size()-1; i >= 0; i--){
            while(nums[i] > stack[sz] && sz >= 1) sz--;
            stack[++sz] = nums[i];
        }
        for(int i = nums.size()-1; i >= 0; i--){
            while(nums[i] >= stack[sz] && sz >= 1) sz--;
            if(sz == 0){
                res[i] = -1;
                stack[++sz] = nums[i];
            }
            else{
                res[i] = stack[sz];
                stack[++sz] = nums[i];
            }
        }
        return res;
    }
};
```
