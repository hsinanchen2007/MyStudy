![image.png](https://pic.leetcode-cn.com/0786dc585f2251480ca24d6ac7d98074c4b42228ef53d9e6e95ee529ef9523cb-image.png)
思路很简单，先排序数组，先保证循环不越界，当 i == nums.length 就说明数组正整数部分是完全有序的，跳出并返回值。 如果数字为负数就跳过，当数字为正且从1开始连续 （此处连续用双指针甄别 ），当nums[i]为1也就是最小的正数时j开始与其同步自增，如果数组的正整数部分是连续的[....1,2,3,4,5]的话 nums[i] == nums[i-1] 就会一直成立，那么就是扫描一遍直到nums.length，返回結果。如果不成立那就説明找到了结果，返回结果。
```
class Solution {
    public int firstMissingPositive(int[] nums) {
        Arrays.sort(nums);
        int i = 0,j = 1;
        while(true){
            if(i == nums.length){
                return j;
            }
            if(nums[i]<=0){
                i++;
                continue;
            }
            if(i>0 && nums[i] == nums[i-1]){
                i++;
                continue;
            }  
            if(nums[i] == j){
                i++;
                j++;
                continue;
            }
            return j;
        }
    }
}
```

