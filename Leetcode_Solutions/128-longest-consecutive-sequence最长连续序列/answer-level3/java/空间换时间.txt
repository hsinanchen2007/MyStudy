这道题目最开始大家想的肯定是sort，然后计数计算最长序列。但是要求时间复杂度为：o(n)，就不能用sort了。一般在leetcode中，**对时间复杂度有要求，就用空间来换，对空间复杂度有要求，就用时间来换。**

基于这种思路我们就想要求最长的，就是要记录下有没有相邻的元素，比如遍历到100这个元素，我们需要查看[99, 101]这两个元素在不在序列中，这样去更新最大长度。而记录元素有没有这个事我们太熟悉了，用set这种数据结构，而set这种数据结构是需要o(n)的空间来换取的，这就是我们刚才说的用空间来换时间。

```java
class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> numsSet = new HashSet<>();
        for (Integer num : nums) {
            numsSet.add(num);
        }
        int longest = 0;
        for (Integer num : nums) {
            if (numsSet.remove(num)) {
                // 向当前元素的左边搜索,eg: 当前为100, 搜索：99，98，97,...
                int currentLongest = 1;
                int current = num;
                while (numsSet.remove(current - 1)) current--;
                currentLongest += (num - current);
		// 向当前元素的右边搜索,eg: 当前为100, 搜索：101，102，103,...
                current = num;
                while(numsSet.remove(current + 1)) current++;
                currentLongest += (current - num);
        	// 搜索完后更新longest.
                longest = Math.max(longest, currentLongest);
            }
        }
        return longest;
    }
}
```

欢迎大家关注我的公众号：**Leetcode名企之路**，每天更新一道算法题。