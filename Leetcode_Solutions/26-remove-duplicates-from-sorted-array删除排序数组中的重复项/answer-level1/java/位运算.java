### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums == null || nums.length <= 1){
            return nums == null ? 0 : nums.length;
        }
        int i = 0, j = 0;
        for(; j < nums.length - 1; j++){
            int num = nums[j] ^ nums[j + 1];
            if(num != 0){
                nums[i++] = nums[j];
            }
        }
        //最后一位和倒数第二位，不论是否相等，都放入数组中
        nums[i++] = nums[j];
        return i;
    }
}
```