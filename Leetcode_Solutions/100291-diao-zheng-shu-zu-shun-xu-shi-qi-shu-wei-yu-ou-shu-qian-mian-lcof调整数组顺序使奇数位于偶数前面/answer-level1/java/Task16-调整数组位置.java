### 解题思路
利用快速排序即可。

### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
        // 双指针算法
        int start = 0;
        int end = nums.length - 1;

        while(start < end) {
            if (nums[start] % 2 == 0 && nums[end] % 2 == 0) {
                end--;
            } else if (nums[start] % 2 == 0 && nums[end] % 2 == 1) {
                int temp = nums[start];
                nums[start]= nums[end];
                nums[end] = temp;                
                start++;
                end--;
            } else if (nums[start] % 2 == 1 && nums[end] % 2 == 0) {
                start++;
                end--;
            } else {
                start++;
            }
        }

        return nums;
    }
}
```