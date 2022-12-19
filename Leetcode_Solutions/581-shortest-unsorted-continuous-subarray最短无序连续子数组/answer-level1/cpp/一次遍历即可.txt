```c++
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int size=nums.size();
        int i=0,j=size-1;
        int prev_max=nums[i],back_min=nums[j];
        int l=0,r=0;
        while (i<size){
            int c=nums[i];
// 遍历:左 --> 右
//prev_max：i之前的最大值，prev_max > 当前值，说明nums[:i]非递增，记录右边界i
            if (c<prev_max)
                r=i;
            else
                prev_max=c;
            int b=nums[size-i-1];
// 遍历:右 --> 左
//back_min:i之后的最小值，back_min < 当前值,说明nums[i:]非递增，记录左边界i
            if (b>back_min)
                l=size-i-1;
            else
                back_min=b;
            i+=1;
        }
        return l==r?0:r-l+1;
    }
};
```
