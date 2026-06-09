### 解题思路
这是一个非常简单的组合数学问题： 通过逆序数序列恢复原排列。"Recover the permutation from an inversion sequence"
- 逆序数"inversion number"和“逆序对”的定义非常像：
    - 对于排列a1, a2,...,an中的某个元素ai, 他的逆序数aj等于排列中范围[a1,...,ai-1]里**大于ai的数的个数**，逆序数衡量了**这个元素**在**这个排列**中的乱序程度。
    - 逆序数取值范围为0...某个正整数
    - 根据这个题目我们可以将**定义扩展**为"大于等于ai的数的个数"，那么给定输入就等价于一个 **[高度值,逆序数]** 数组。 
- 恢复原排列： 只需按逆序数序列以原排列数从大到小顺序构建原排列即可
    - 例： 对于{1, 2, 3, 4, 5, 6, 7, 8}的逆序数序列{5, 3, 4, 0, 2, 1, 1, 0}。 我们可以这样恢复原排列：
    - 
![Screen Shot 2020-02-25 at 15.45.15.png](https://pic.leetcode-cn.com/40dec0eabd05f728f734210dd724116040cecd4bcf474196859f4b5592d5d0bc-Screen%20Shot%202020-02-25%20at%2015.45.15.png)
- 在本题中如何恢复原排列：
    -  先按高度降序排序，同高度按逆序数升序排序。
    -  按定义，将每个元素插入到逆序数位置即可

### 代码

```java
public class Solution {
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people, (a, b) -> a[0] != b[0] ? b[0] - a[0] : a[1] - b[1]);
        List<int[]> res = new LinkedList<>();
        for(int[] cur : people) res.add(cur[1],cur);       
        return res.toArray(new int[people.length][]);
    }
}
```
### 复杂度
时间复杂度取决于排序 O(nlogn) 空间复杂度O(n)
### 参考
Richard A. Brualdi - Introductory Combinatorics 5th Edition Chapter 4.2 Inversions in Permutations