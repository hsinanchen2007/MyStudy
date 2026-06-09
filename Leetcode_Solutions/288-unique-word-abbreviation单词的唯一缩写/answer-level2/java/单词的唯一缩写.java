#### 方法 1： 暴力

我们从在构造器里把字典排序开始。为了判断一个单词的缩写在字典里是否是唯一的，我们判断它跟字典里所有其他单词是否满足如下所有条件：

1. 它们不是同一个单词
2. 它们有相同的长度
3. 它们开始字母和结束字母相同

注意条件 1 是隐含的，因为从题目描述中：

>一个单词的缩写是唯一的当且仅当没有 ***其他的*** 字典中的单词与它有相同的缩写。

```Java []
public class ValidWordAbbr {
    private final String[] dict;

    public ValidWordAbbr(String[] dictionary) {
        dict = dictionary;
    }

    public boolean isUnique(String word) {
        int n = word.length();
        for (String s : dict) {
            if (word.equals(s)) {
                continue;
            }
            int m = s.length();
            if (m == n
                && s.charAt(0) == word.charAt(0)
                && s.charAt(m - 1) == word.charAt(n - 1)) {
                return false;
            }
        }
        return true;
    }
}
```

**复杂度分析**

* 时间复杂度：每一次调用都是 $O(n)$ 的。

    假设 $n$ 是词典中单词的数目，每一次 `isUnique` 函数调用都需要 $O(n)$ 的时间。

#### 方法 2：哈希表

注意到 `isUnique` 对同样集合的单词每次调用都要重新计算，我们可以预处理字典来加速。

理想状态下，哈希表支持常数时间的查找，那么键值对应该是怎样的呢？

其实想法就是把相同缩写的单词分成同一组。对于值，我们建立一个 `Set` 而不是一个 `List` 来保证唯一性。

`isUnique(word)` 的逻辑是十分技巧性的。你需要考虑下面的情况：

1. 单词的缩写是否在字典中出现过？如果没有，它就是唯一的。
2. 如果上述答案是出现过，它是唯一的条件是这个组里除了它本身 *word* 以外没有其他任何单词。

```Java []
public class ValidWordAbbr {
    private final Map<String, Set<String>> abbrDict = new HashMap<>();

    public ValidWordAbbr(String[] dictionary) {
        for (String s : dictionary) {
            String abbr = toAbbr(s);
            Set<String> words = abbrDict.containsKey(abbr)
                ? abbrDict.get(abbr) : new HashSet<>();
            words.add(s);
            abbrDict.put(abbr, words);
        }
    }

    public boolean isUnique(String word) {
        String abbr = toAbbr(word);
        Set<String> words = abbrDict.get(abbr);
        return words == null || (words.size() == 1 && words.contains(word));
    }

    private String toAbbr(String s) {
        int n = s.length();
        if (n <= 2) {
            return s;
        }
        return s.charAt(0) + Integer.toString(n - 2) + s.charAt(n - 1);
    }
}
```

#### 方法 3：哈希表

让我们考虑另一种方法，我们使用一个计数器作为表的值。比方说，假设字典为 `["door", "deer"]`，我们可以得到映射 `{"d2r" -> 2}` 。然而，这个映射是不够的，因为我们需要考虑每个单词是否有其他相同的单词出现在字典里。这个通过把整个字典插入一个 set 里可以轻松判断。

当一个缩写出现的次数超过一次，我们知道这个缩写肯定不是唯一的，因为至少有两个不一样的额单词有同样的缩写。因此，我们进一步可以把计数器变成一个 boolean 值变量。

```Java []
public class ValidWordAbbr {
    private final Map<String, Boolean> abbrDict = new HashMap<>();
    private final Set<String> dict;

    public ValidWordAbbr(String[] dictionary) {
        dict = new HashSet<>(Arrays.asList(dictionary));
        for (String s : dict) {
            String abbr = toAbbr(s);
            abbrDict.put(abbr, !abbrDict.containsKey(abbr));
        }
    }

    public boolean isUnique(String word) {
        String abbr = toAbbr(word);
        Boolean hasAbbr = abbrDict.get(abbr);
        return hasAbbr == null || (hasAbbr && dict.contains(word));
    }

    private String toAbbr(String s) {
        int n = s.length();
        if (n <= 2) {
            return s;
        }
        return s.charAt(0) + Integer.toString(n - 2) + s.charAt(n - 1);
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n)$ 的预处理，每次调用 `isUnique` 函数 $O(1)$ 。
**方法 2** 和**方法 3** 都需要 $O(n)$ 时间的预处理。但是**方法 3** 在 `isUnique` 被多次重复调用的时候表现更好。

* 空间复杂度：$O(n)$ 。我们使用额外的 $O(n)$ 的空间保存哈希表来减少 `isUnique` 被调用时的时间复杂度。
