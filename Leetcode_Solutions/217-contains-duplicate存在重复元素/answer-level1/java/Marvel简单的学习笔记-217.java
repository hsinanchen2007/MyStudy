### 解题思路
利用HashSet的去重功能，若有重复元素，则HashSet.size()<nums.length。
时间复杂度：O(n)。要遍历数组检查重复元素。
空间复杂度：O(n)。最坏情况下HashSet需要存储n个元素。

### 代码

```java
class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> set=new HashSet<Integer>();
        for(int i: nums)
            set.add(i);
        return set.size()<nums.length;
    }
}
```