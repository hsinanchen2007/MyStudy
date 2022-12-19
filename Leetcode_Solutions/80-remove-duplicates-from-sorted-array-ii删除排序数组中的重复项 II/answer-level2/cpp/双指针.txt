一个指针指向正确位置，另一个指针遍历数组，在p<2的时候直接写，不用考虑，另一个条件是如果遍历到某一个数到3次，那么他跟p-2位置上的数应该是一样的，不做任何操作继续遍历


```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p = 0;
        
        for(int i=0; i<nums.size(); i++){
            if (p<2 || nums[i]!=nums[p-2]){
                nums[p++] = nums[i];
            }     
        }
        
        return p;
        
    }
};
```
