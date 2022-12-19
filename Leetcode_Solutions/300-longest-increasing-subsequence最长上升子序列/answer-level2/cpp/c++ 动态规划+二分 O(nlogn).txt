
//注意：代码中tail[i] 的含义为：在长度为(i+1) 的的所有最长上升子序列中，末尾元素最小的序列 的末尾元素。 

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tail(nums.size(),0);
        int indexTail=0;
        int lo, hi, mi;
        for(int i=0; i<nums.size(); i++){
            if(!indexTail || nums[i]>tail[indexTail-1])
                tail[indexTail++]=nums[i];
            else{
                lo=0, hi=indexTail;
                while(lo<hi){
                    mi=(lo+hi)>>1;
                    if(tail[mi]>=nums[i])
                        hi=mi;
                    else
                        lo=mi+1;
                }
                tail[lo]=nums[i];
            }
        }
        return indexTail;
    }
};
```
