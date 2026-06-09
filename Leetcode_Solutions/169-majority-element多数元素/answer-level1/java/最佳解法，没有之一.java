思路是摩尔投票的思路，初始化major为数组第一个数，遍历数组，如果当前元素跟major相同，count++， 如果不同，count--，count为0时用当前数字赋值给major，因为存在元素数量大于数组长度的一半，所以最终count肯定会大于等于1，最终的major即为数组中的多数元素。

```java
class Solution {
    public int majorityElement(int[] nums) {
        // 摩尔投票
        int count = 0, major = 0;
        for (int i: nums){
            if(count == 0) major = i;
            if (i != major) count--;
            else count++;
        }
        return major;
    }
}
```