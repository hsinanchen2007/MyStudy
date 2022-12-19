执行用时 :1 ms, 在所有 Java 提交中击败了90.51% 的用户
内存消耗 :36.8 MB, 在所有 Java 提交中击败了5.27%的用户
```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] res = new int[num_people];
        int cur = 1;
        while (candies >= cur) {
            res[(cur-1) % num_people] += cur;
            candies -= cur++;
        }
        res[(cur-1) % num_people] += candies;
        return res;
    }
}
```