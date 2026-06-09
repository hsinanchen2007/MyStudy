# 思路
遍历数组，在第 i 位放数字 i 。

若当前第 i 位数字 num 不为 i ，则将 num 与 nums[num] 交换，使得第 num 位数字为 num ，循环直到第 i 位数字为 i 。

之后再有 nums[i] == nums[nums[i]] 时即为重复数字。
# 复杂度
时间O(n)

空间O(1)
# 代码
```
class Solution {
    public int findRepeatNumber(int[] nums) {
        for(int i = 0; i < nums.length; i++){
            while(i != nums[i]){
                if(nums[i] == nums[nums[i]]){
                    return nums[i];
                }
                int temp = nums[i];
                nums[i] = nums[temp];
                nums[temp] = temp;
            }
        }
        return -1;
    }
}
```