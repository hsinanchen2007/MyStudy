### 解题思路
此处撰写解题思路
执行用时 :
2 ms
, 在所有 Java 提交中击败了
77.57%
的用户
内存消耗 :
42.7 MB
, 在所有 Java 提交中击败了
100.00%
的用户
### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length / 2];
    }
}
```