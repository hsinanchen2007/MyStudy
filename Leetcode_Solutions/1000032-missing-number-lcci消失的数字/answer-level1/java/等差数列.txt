### 解题思路


### 代码

```java
class Solution {
  public int missingNumber(int[] nums)
    {
        int sum = (nums.length+1)*(nums.length)/2;
        for (int num : nums) {
            sum -= num;
        }
        return sum;
    }
}
```