## 思路：

滑动窗口 + 哈希

每次取10个字符记录下来，然后记录个数

时间复杂度：$O(n)$

```python [1]
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        from collections import defaultdict
        visited = set()
        res = set()
        for i in range(0, len(s) - 9):
            tmp = s[i:i+10]
            if tmp in visited:
                res.add(tmp)
            visited.add(tmp)
        return list(res)          
```



```java [1]
class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        Set visited = new HashSet(), res = new HashSet();
        for (int i = 0; i + 10 <= s.length(); i++) {
            String tmp = s.substring(i, i + 10);
            if (visited.contains(tmp)) {
                res.add(tmp);
            } else visited.add(tmp);
            

        }
        return new ArrayList<>(res);
    }
}
```



