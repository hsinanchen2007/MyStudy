- 求和相减
```java
class Solution {
    public int missingNumber(int[] nums) {
        int sum = 0;
        for (int i = 0;i < nums.length;i++){
            sum = sum + i - nums[i];
        }
        return sum + nums.length;
    }
}
```
- 数学公式
```java
class Solution {
    public int missingNumber(int[] nums) {
        int sum = 0;
        for (int i = 0;i < nums.length;i++){
            sum += nums[i];
        }
        return (nums.length*(nums.length+1))/2 - sum;
    }
}
```
异或
```java
class Solution {
    public int missingNumber(int[] nums) {
        int sum = 0;
        for (int i = 0;i < nums.length;i++){
            sum ^ = i ^nums[i];
        }
        return sum ^ nums.length;
    }
}
```