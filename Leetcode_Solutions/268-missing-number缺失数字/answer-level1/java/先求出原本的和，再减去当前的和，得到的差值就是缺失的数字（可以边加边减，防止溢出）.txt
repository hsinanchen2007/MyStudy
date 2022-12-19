### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        int len = nums.length, sum = 0, i = 0;
        while (i < len){
            i++;
            sum = sum + i - nums[i - 1];
        }
        return sum;
    }
}
```