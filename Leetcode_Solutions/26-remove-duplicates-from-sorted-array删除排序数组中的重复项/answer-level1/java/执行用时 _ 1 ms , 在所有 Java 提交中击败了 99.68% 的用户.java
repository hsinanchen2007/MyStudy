### 解题思路
以原数组空间重写新数组，因为数组是有序的，以指针记录当前已写入的数组下表位置，跳过重复的值

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length == 0){
            return 0;
        }
        int left = 0;
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] == nums[left]) {
                continue;
            } else {
                nums[left + 1] = nums[i];
                left++;
            }
        }
        return left + 1;
    }
}
```