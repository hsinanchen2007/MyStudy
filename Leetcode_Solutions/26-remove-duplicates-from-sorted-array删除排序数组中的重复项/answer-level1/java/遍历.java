### 解题思路
index指向该插入的位置，当nums[i]和其前一个值不等时，将nums[i]插入到index的位置，然后index++；如果nums[i]和其前一个值相等，继续遍历下一个。

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int index = 1;
        for (int i=1; i<nums.length; i++) {
            if (nums[i] != nums[i-1]) {
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
}
```