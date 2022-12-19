### 解题思路
如果当前位置的数字与下标不同，则把它换到正确的位置上去，最后位置不对的那个就是缺的数字

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        if (nums == null) {
            return -1;
        }

        for (int i = 0; i < nums.length; i ++) {
            while (nums[i] != i && nums[i] < nums.length) {
                int temp = nums[i];
                nums[i] = nums[temp];
                nums[temp] = temp;
            }
        }

        for (int i = 0; i < nums.length; i ++) {
            if (nums[i] != i) {
                return i;
            }
        }

        return nums.length;
    }
}
```