和精选题解的算法一样，使用的是Cpp实现。
如果单纯的暴力求解那么就会用$O(N^3)$时间复杂度，即三次for循环遍历。
使用排序+头尾双指针查找则减少了一层遍历，时间复杂度为$$O(NlogN)+O(N^2)=O(N^2)$

如果tmp值比target值小，那将头指针即start指针后移
如果tmp值比target值大，则将尾指针即end指针前移

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // STL sort
        sort(nums.begin(),nums.end());
        int ans=nums[0]+nums[1]+nums[2],tmp,end,start;
        for(unsigned i=0;i<nums.size()-2;i++){
            start=i+1;
            end=nums.size()-1;
            while(start<end){
                tmp=nums[i]+nums[start]+nums[end];
                if(tmp>target){
                    end--;
                }else if(tmp<target){
                    start++;
                }else{
                    return target;
                }
                if(abs(tmp-target)<abs(ans-target))ans=tmp;
            }
        }
        return ans;
    }
};
```