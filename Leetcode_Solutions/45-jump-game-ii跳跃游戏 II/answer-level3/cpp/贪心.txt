### 解题思路


### 代码

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int start=0,last=nums[0],end=nums.size()-1,time,max;
        if(nums.size()==1)
         time=0;
         else time=1;
         
        while(last<end){
            
            max=0;
            while(start<last){
                start++;
                max=max>start+nums[start]? max:start+nums[start];
            }
            last=max;
            
            
            time++;

        }
        return time;

    }
};
```