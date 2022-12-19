[lo,hi]为搜索区间且lo,hi皆为偶数
mi为不超过区间中点的第一个偶数，写作mi=((lo+hi)>>2)<<1 （mi=((lo+hi)/4)*2）
根据奇偶性，目标左边(不含)a[n]、a[n+1] (n为偶数)为两个一组的相同数字，目标右边则不同。
以此为依据减半搜索区间，直到区间长度退化为1
细节处可以修改，如前后都判断，可能可以提前找到该元素。
时间复杂度O(log n)
空间复杂度O(1)

注意:
防止数组越界，mi-1小于0或mi+1不小于nums,size()时越界，如下写法条件下不会导致越界，因为若越界，条件hi<=nums.size()-1,mi<=hi,mi>=nums.size()-1同时成立,得mi==hi,即lo==mi==hi,长度会退化为1，不进入循环。
 
代码如下，欢迎提出建议：
```
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo=0,hi=nums.size()-1,mi=((lo+hi)>>2)<<1;
        while(hi-lo){
            if(nums[mi]<nums[mi+1]) hi=mi;//mi在目标右边
            else lo=mi+2;                 //mi在目标左边（不含）
            mi=((lo+hi)>>2)<<1;
        }
        return nums[mi];
    }
};
```
