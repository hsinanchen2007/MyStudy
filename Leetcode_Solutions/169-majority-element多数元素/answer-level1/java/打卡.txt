### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        int count = 1;
        int res = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (res == nums[i] || count == 0) {
                res = nums[i];
                count++;
            } else {
                count--;
            }
        }
        return res;
    }
}
```