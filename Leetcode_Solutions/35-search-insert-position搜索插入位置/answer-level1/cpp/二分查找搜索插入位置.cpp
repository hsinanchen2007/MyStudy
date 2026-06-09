### 解题思路
采用二分查找的思想，找出大于target的最小秩r。
然后验证向量中是否存在和target相等的元素，此时需分类讨论：
1.r=0,不存在，插入位置为0，此时不能验证r-1号元素是否与target相等，否则会超出维度报错（不存在nums[-1]）；
2.r>0,验证nums[r-1]是否等于target，若等于则存在该元素，返回r-1，若不等返回r。

### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
    int hi = nums.size();
    int lo = 0;
    while(lo<hi)
    {
        int mi=(lo+hi)>>1;
        (target<nums[mi])?hi=mi:lo=mi+1;
    }
    if(lo==0)return lo;
    else return (target==nums[lo-1])?lo-1:lo;
 
    }
};
```