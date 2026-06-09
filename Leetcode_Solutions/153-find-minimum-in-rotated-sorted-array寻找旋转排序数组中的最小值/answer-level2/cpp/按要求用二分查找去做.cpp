常规遍历当然简单啊，但要求是用二分查找，二分法优势在于缩减了时间复杂度，题目是排除了重复元素的情况，所以重复情况也没有讨论了
```
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left =0;
        int right = nums.size()-1;
        if(right==0){
            return nums[left];
        }
        while(left<right){
            int mid = (left+right)/2;
            if(nums[left]==nums[mid]){
                if(nums[left]<nums[right]){
                    right--;
                }
                else{
                    left++;
                }
            }
            else if(nums[left]<nums[mid]){
                if(nums[left]<nums[right]){
                    right = mid-1;
                }
                else{
                    left =mid+1;
                }
            }
            else{
                right =mid;
            }
        }
        return nums[left];
    }
};//分好类就行，比较常规，这里题目给了严格单调，没有继续考虑非严格的情况
```
