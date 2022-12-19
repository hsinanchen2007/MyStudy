### 解题思路

1. 将区间分为左右，分别找到左右区间中的众数mode
2. 当区间内，只有一个数时，则返回这个数
3. 如果左右区间的mode为同一个数，就返回左区间或右区间的mode
4. 如果不为同一个数，则分别计算左右区间mode个数，返回个数更多的一个

### 代码

```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        return FindMode(nums,low,high);
    }

    int CountInRange(vector<int>& nums,int mode,int low,int high){    ////区间内mode的count
        int count=0;
        for(int i=low;i<=high;++i){
            if(nums[i]==mode)
                ++count;
        }
        return count;
    }

    int FindMode(vector<int>& nums,int low,int high){    ////找mode
        if(low==high)
            return nums[high];
        int mid=(high-low)/2+low;

        int LeftMode=FindMode(nums,low,mid);        
        int RightMode=FindMode(nums,mid+1,high);
        if(LeftMode==RightMode)
            return LeftMode;

        int LeftCount=CountInRange(nums,LeftMode,low,mid);
        int RightCount=CountInRange(nums,RightMode,mid+1,high);
        return LeftCount > RightCount ? LeftMode : RightMode;
        
    }
};
```