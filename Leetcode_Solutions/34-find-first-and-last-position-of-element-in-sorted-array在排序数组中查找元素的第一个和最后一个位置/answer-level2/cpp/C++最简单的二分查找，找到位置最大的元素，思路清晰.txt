### 解题思路
这里使用的其实是邓公的数据结构中的二分查找版本C。书中给出了严谨的证明，在这里我先给出结论。

我们在区间```[lo,hi)```中查找，本算法均是**左闭右开**区间。

在查找完成时，lo=hi,而```nums[lo-1]```就是原向量中不大于```target```的最后一个元素，所以最后的结果无论查找成功还是失败，返回的都是最大位置。
我们找到最大位置之后，沿着这个位置往前搜索即可。


### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1,-1};

        int lo=0,hi=nums.size();
        while(lo<hi)//每部迭代做一次判断
        {
            int mi=(lo+hi)>>1;//中点作为轴点
            target<nums[mi]?hi=mi:lo=mi+1;//比较后，选择深入[lo,mi)还是(mi,hi)
        }
        
        if(--lo<0||nums[lo]!=target) return {-1,-1};//为了防止向量越界先判断--lo的大小。再判断我们查找成功还是失败
        int max=lo;//如果查找成功，就可以从查找到的位置开始往前搜索
        if(lo-1>=0)//防止越界
        {
            while(nums[lo]==nums[lo-1])
            {
                lo--;
                if(lo==0)//防止越界
                    break;
            }
        }
        return {lo,max};
        
    }
};
```