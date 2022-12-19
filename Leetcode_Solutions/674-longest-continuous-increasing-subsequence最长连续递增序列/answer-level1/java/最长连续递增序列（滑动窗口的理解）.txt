解题思路：
1. 数组长度小于1返回0
2. 三个变量分别用来记录递增序列开始的下标、结束的下标以及递增长度。
3. 遍历数组（从0到len-1），每次比较两个元素。
    nums[i] < nums[i+1]时更新结束下标；
    nums[i] == nums[i+1]时更新开始下标；
    nums[i] > nums[i+1]时开始和结束下标均需要更新；
    更新递增长度。
时间复杂度：O(n);空间复杂度：O(1)。
```
class Solution {
    public int findLengthOfLCIS(int[] nums) {
        int len = nums.length;
        if(len < 1)
            return 0;
        int startIndex = 0;//连续递增开始的下标
        int endIndex = 0;//连续递增结束的下标
        int increaseLen = 1;//递增长度
        for(int i = 0;i < len - 1;i ++){
            if(nums[i] < nums[i+1]){
                endIndex = i+1;
            }else if(nums[i] == nums[i+1]){
                startIndex = i+1;
            }else{                
                startIndex = i+1;
                endIndex = i+1;
            }
            increaseLen = Math.max(endIndex - startIndex + 1,increaseLen);
        }
        return increaseLen;
    }
}
```
