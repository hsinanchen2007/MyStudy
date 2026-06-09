#### 方法一：双映射表

我们可以用两个映射表（map）存储字母到字母的映射关系，第一个映射表保证一个字母不会映射到两个字母，第二个映射表保证不会有两个字母映射到同一个字母。例如 `word` 为 `a`，`pattern` 为 `x`，那么第一个映射表存储 `a -> x`，第二个映射表存储 `x -> a`。

```Java [sol1]
class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> ans = new ArrayList();
        for (String word: words)
            if (match(word, pattern))
                ans.add(word);
        return ans;
    }

    public boolean match(String word, String pattern) {
        Map<Character, Character> m1 = new HashMap();
        Map<Character, Character> m2 = new HashMap();

        for (int i = 0; i < word.length(); ++i) {
            char w = word.charAt(i);
            char p = pattern.charAt(i);
            if (!m1.containsKey(w)) m1.put(w, p);
            if (!m2.containsKey(p)) m2.put(p, w);
            if (m1.get(w) != p || m2.get(p) != w)
                return false;
        }

        return true;
    }
}
```

```Python [sol1]
class Solution(object):
    def findAndReplacePattern(self, words, pattern):
        def match(word):
            m1, m2 = {}, {}
            for w, p in zip(word, pattern):
                if w not in m1: m1[w] = p
                if p not in m2: m2[p] = w
                if (m1[w], m2[p]) != (p, w):
                    return False
            return True

        return filter(match, words)
```

**复杂度分析**

* 时间复杂度：$O(N * K)$，其中 $N$ 是数组 `words` 的长度，$K$ 是每个单词的长度。

* 空间复杂度：$O(N * K)$。

#### 方法二：单映射表

我们可以删去方法一中的第二个映射表，改成在添加完所有映射关系后，遍历第一个映射表并使用一个数组记录每个值出现的次数。如果某个值出现了超过一次，就说明有两个字母映射到同一个字母，否则映射就是合法的。

```Java [sol2]
class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> ans = new ArrayList();
        for (String word: words)
            if (match(word, pattern))
                ans.add(word);
        return ans;
    }

    public boolean match(String word, String pattern) {
        Map<Character, Character> M = new HashMap();
        for (int i = 0; i < word.length(); ++i) {
            char w = word.charAt(i);
            char p = pattern.charAt(i);
            if (!M.containsKey(w)) M.put(w, p);
            if (M.get(w) != p) return false;
        }

        boolean[] seen = new boolean[26];
        for (char p: M.values()) {
            if (seen[p - 'a']) return false;
            seen[p - 'a'] = true;
        }
        return true;
    }
}
```

```Python [sol2]
class Solution(object):
    def findAndReplacePattern(self, words, pattern):
        def match(word):
            P = {}
            for x, y in zip(pattern, word):
                if P.setdefault(x, y) != y:
                    return False
            return len(set(P.values())) == len(P.values())

        return filter(match, words)
```

**复杂度分析**

* 时间复杂度：$O(N * K)$，其中 $N$ 是数组 `words` 的长度，$K$ 是每个单词的长度。

* 空间复杂度：$O(N * K)$。