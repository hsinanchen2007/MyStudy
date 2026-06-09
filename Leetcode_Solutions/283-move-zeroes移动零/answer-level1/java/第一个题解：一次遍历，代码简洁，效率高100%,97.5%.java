解题思路：统计0的个数，如果count大于0，将非0元素直接移到当前位置减去0元素个数的位置上，将当前元素用0填充。

```
class Solution {
    public void moveZeroes(int[] nums) {
        int count = 0;
        for(int i = 0 ; i < nums.length ; i++){
            if(nums[i] == 0)
                count++;
            else if(count >0){
                nums[i-count] = nums[i];
                nums[i] = 0;
            }
        }
    }
}
```
