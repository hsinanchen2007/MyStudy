### 解题思路
此处撰写解题思路
//主要在于处理找到的重复数据，找到了重复数据2边都查找
### 代码

```cpp
class Solution {
public:
    int nStartIndex;
    int nEndIndex;
    void find(vector<int>& nums, int target,int nStart,int nEnd)
    {
        if(nStart>nEnd)
        {
            return;
        }
        int nMiddle=(nStart+nEnd)/2;
        if(nums[nMiddle]==target)
        {
            if(nStartIndex>nMiddle)
            {
                nStartIndex=nMiddle;
            }
            if(nEndIndex<nMiddle)
            {
                nEndIndex=nMiddle;
            }
            //两边都要进行查找
            find(nums,target,nStart,nMiddle-1);
            find(nums,target,nMiddle+1,nEnd);
            return ;
        }
        if(nums[nMiddle]<target)
        {
            //往右边找
            find(nums,target,nMiddle+1,nEnd);
        }
        else 
        {
            //往左边找
            find(nums,target,0,nMiddle-1);
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        //折半查找
        int nSize=nums.size();
        if(nSize<=0)
        {
            return {-1,-1};
        }
        nStartIndex=nSize;
        nEndIndex=-1;
        find(nums,target,0,nSize-1);
        if(nStartIndex<=nEndIndex)
        {
            return {nStartIndex,nEndIndex};
        }
        return {-1,-1};
    }
};
```