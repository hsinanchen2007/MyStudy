### 解题思路
A^A^B^C^C=B,可知对一串数字连续异或运算可消除成对的数字,此法无论有序无序都可用,只要是偶数倍

### 代码

```java
class Solution {
    public int singleNonDuplicate(int[] nums) {
        int first=nums[0];
        for (int i = 1; i < nums.length; i++) {
            first=first^nums[i];
        }
        return  first;
    }
}
```