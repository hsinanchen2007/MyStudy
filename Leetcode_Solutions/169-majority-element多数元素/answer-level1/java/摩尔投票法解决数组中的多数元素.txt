### 解题思路
原理就是用大部分数消去小部分数，因为众数占多半，所以最后剩下的肯定就是众数

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        int count = 0;
        Integer value = null;
        /*
         投票法是遇到相同元素票数 + 1，遇到不同元素则票数 - 1。
        多数元素”的个数 - 其余元素的个数总和 >= 1。
        最后剩下的就是众数
         */
        for(int i = 0; i < nums.length; i++){
            if(count == 0)
                value = nums[i];
            count += nums[i] == value ? 1 : -1;
        }
        return value;
    }
}
```