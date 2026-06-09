### 解题思路
- 核心要点：二分查找的思想，设置两个int标记left和right，注意检测中点值条件**nums[m]<=target**时，left=m+1，这样的迭代并跳出循环时，**left一定指向排序数组中数字I的最右端下一个数**；同理，第二次迭代检测**nums[m]>=target**，right=m-1，最终**right指向排序数组中数字I的最左端前一个数**，相减后再减1即得结果。
- 执行用时：28 ms, 在所有 C++ 提交中击败了6.26%的用户
- 内存消耗：13.1 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)return 0;
        int m;
        int left=0,right=nums.size()-1;     

        while(left<=right){
            m=(left+right)/2;
            if(nums[m]<=target){
                left=m+1;
            }
            else{
                right=m-1;
            }
        }
        int rb=left;

        left=0,right=nums.size()-1;  
        while(left<=right){
            m=(left+right)/2;
            if(nums[m]>=target){
                right=m-1;
            }
            else{
                left=m+1;
            }
        }
        int lb=right;

        return rb-lb-1;
    }

};
```