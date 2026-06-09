#### 方法一： 暴力法 【通过】

**思路和算法**

遍历每块石头，检查是不是宝石。检查步骤用简单的线性搜索来实现。

```java [solution1-Java]
class Solution {
    public int numJewelsInStones(String J, String S) {
        int ans = 0;
        for (char s: S.toCharArray()) // For each stone...
            for (char j: J.toCharArray()) // For each jewel...
                if (j == s) {  // If the stone is a jewel...
                    ans++;
                    break; // Stop searching whether this stone 's' is a jewel
                }
        return ans;
    }
}
```

```python [solution1-Python]
class Solution(object):
    def numJewelsInStones(self, J, S):
        return sum(s in J for s in S)
```


**复杂度分析**

* 时间复杂度：$O(J.length * S.length))$。

* 空间复杂度：在 Python 实现中，空间复杂度为 $O(1)$。在 Java 实现中，空间复杂度为 $O(J.length * S.length))$。

#### 方法二： 哈希集合 【通过】

**思路和算法**

遍历每块石头，检查是不是宝石。检查步骤用 *哈希集合* 来高效完成。

```java [solution2-Java]
class Solution {
    public int numJewelsInStones(String J, String S) {
        Set<Character> Jset = new HashSet();
        for (char j: J.toCharArray())
            Jset.add(j);

        int ans = 0;
        for (char s: S.toCharArray())
            if (Jset.contains(s))
                ans++;
        return ans;
    }
}
```

```python [solution2-Python]
class Solution(object):
    def numJewelsInStones(self, J, S):
        Jset = set(J)
        return sum(s in Jset for s in S)
```

**复杂度分析**

* 时间复杂度：$O(J.length + S.length))$。$O(J.length})$ 这部分来自于创建 `J`，$O(S.length)$ 这部分来自于搜索 `S`。

* 空间复杂度：$O(J.length)$。