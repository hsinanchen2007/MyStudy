执行用时 :2 ms, 在所有 java 提交中击败了100.00%的用户    
内存消耗 :39.3 MB, 在所有 java 提交中击败了97.75%的用户     
```
class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int len = nums.length;
        int max = nums[0];
        int min = nums[len-1];
        int l = 0, r = -1;
        for(int i=0;i<len;i++){
            if(max>nums[i]){
                r = i;
            }else{
                max = nums[i];
            }
            if(min<nums[len-i-1]){
                l = len-i-1;
            }else{
                min = nums[len-i-1];
            }
        }
        return r-l+1;
    }
}
```
同时从前往后和从后往前遍历，分别得到要排序数组的右边界和左边界；  
**寻找右边界：**    
从前往后遍历的过程中，用**max记录遍历过的最大值**，如果max大于当前的nums[i]，说明nums[i]的位置不正确，属于需要排序的数组，因此将右边界更新为i，然后更新max；这样最终可以找到需要排序的数组的右边界，右边界之后的元素都大于max；  
**寻找左边界：**    
从后往前遍历的过程中，用**min记录遍历过的最小值**，如果min小于当前的nums[j]，说明nums[j]的位置不正确，应该属于需要排序的数组，因此将左边界更新为j，然后更新min；这样最终可以找到需要排序的数组的左边界，左边界之前的元素都小于min；
（从前往后遍历和从后往前遍历两个过程可以分两次循环完成，也可以放一起完成，这样的话就有：j=len-i-1）