### 解题思路
找出两个小数 然后找一个比这个数的大的即可

### 代码

```java
class Solution {
    public boolean increasingTriplet(int[] nums) {
        //bad-case
        if (nums.length < 2) {
            return false;
        }

        //双指针+一个变量
        int min1 = Integer.MAX_VALUE;
        int min2 = Integer.MAX_VALUE;

        for (int num : nums) {
            if (min1 >= num) {
                min1 = num;
            } else if (min2 >= num) {
                min2 = num;
            } else {
                return true;
            }
        }

        return false;
    }
}
```