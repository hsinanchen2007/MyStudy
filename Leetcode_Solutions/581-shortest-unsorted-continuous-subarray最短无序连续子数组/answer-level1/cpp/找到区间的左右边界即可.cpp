首先分析需查找的区间边界特点。

以左边界为例，由于左边界的值存在逆序，所以该值一定比它右侧最小的元素大。从右向左扫描，记录扫描过程中的最小值（anchor），如果遇到比 anchor 大的数，则更新左边界，否则更新最小值。这样下来，一次遍历就能确定左边界，时间复杂度 $O(n)$。

如果上述扫描后，左边界没有被更新，说明数组本身有序，可直接返回0，无需再查找右边界。

查找右边界与左边界的逻辑一样，从左往右一次遍历即可。

方法跟官解5一样，整体时间 $O(n)$，空间 $O(1)$，代码简洁一点，少两次遍历，如下：

```
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l=-1, r;
        int n = nums.size();        
        // find left boundary
        int anchor = nums[n-1]+1;
        for(int i=n-1; i>=0; i--){
            if(nums[i]>anchor) l=i;
            else anchor = nums[i];
        }
        if(l<0) return 0; // already ordered        
        // find right boundary
        anchor = nums[0]-1;
        for(int i=0; i<n; i++){
            if(nums[i]<anchor) r=i;
            else anchor = nums[i];
        }
        return r-l+1;
    }
};
```