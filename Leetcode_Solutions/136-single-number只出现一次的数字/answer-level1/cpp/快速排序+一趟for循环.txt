1.时间复杂度O(nlogn)
2.空间复杂度O(1)
3.这种做法效率还是很低，比暴力破解时间上快一些
4.**执行用时 :52 ms, 在所有 C++ 提交中击败了5.38%的用户**
**内存消耗 :11.7 MB, 在所有 C++ 提交中击败了5.21%的用户**

```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int len=nums.size();
       for(int i=0;i<len;i=i+2)
       {
           if(i==len-1)
            return nums[i];
           if(nums[i]!=nums[i+1])
           {
               return nums[i];
           }
       }
       return -1;
    }
};
```
