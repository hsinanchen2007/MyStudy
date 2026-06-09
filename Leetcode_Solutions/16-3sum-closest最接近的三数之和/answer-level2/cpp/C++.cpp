### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int nSize=nums.size();
        sort(nums.begin(),nums.end());
        int add;
        int distance(INT_MAX);//将差距初始化为大指
        for(int i=0;i<nSize-2;i++){
            int l=i+1;
            int r=nSize-1;
            while(l<r){
                add=(nums[i]+nums[l]+nums[r]);
                if (add>target){
                    --r;
                    if(add-target<abs(distance))
                        distance=add-target;
                }
                else if (add<target){
                    ++l;
                    if(target-add<abs(distance))
                        distance=add-target;//小于时，distance也为负
                }
                else 
                    return add;
            }   
        }
        return target+distance;
    }
};
```