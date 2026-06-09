### 解题思路
   * 摩尔投票法，相等+1，不相等-1
    * 摩尔投票算法是基于这个事实：每次从序列里选择两个不相同的数字删除掉（或称为“抵消”），最后剩下一个数字或几个相同的数字，就是出现次数大于总数一半的那个。
    * 本质：！！对拼消耗！！

### 代码

```java
class Solution {

    /**
    * 摩尔投票法，相等+1，不相等-1
    * 摩尔投票算法是基于这个事实：每次从序列里选择两个不相同的数字删除掉（或称为“抵消”），最后剩下一个数字或几个相同的数字，就是出现次数大于总数一半的那个。
    * 本质：！！对拼消耗！！
    **/ 
    public int majorityElement(int[] nums) {
        int count = 0;
        int res = 0;
        for (int i = 0, len = nums.length; i < len; i++) {
            if (count == 0) {
                res = nums[i];
            }
            count += res == nums[i] ? 1 : -1;
        }
        return res;
    }
}
```