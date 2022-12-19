#### 方法 1：暴力

**算法**

解决此题最简单的方法是使用回溯。为了找到解，我们检查字符串（$s$）的所有可能前缀是否在字典中，如果在（比方说 $s1$ ），那么调用回溯函数并检查剩余部分的字符串。
如果剩余部分可以形成有效拆分，这个函数返回前缀 $s1$ ，并将回溯调用的剩余结果（即 $s-s1$）跟在 $s1$ 的后面。否则，返回空列表。

```Java []
public class Solution {
    public List<String> wordBreak(String s, Set<String> wordDict) {
        return word_Break(s, wordDict, 0);
    }
    public List<String> word_Break(String s, Set<String> wordDict, int start) {
        LinkedList<String> res = new LinkedList<>();
        if (start == s.length()) {
            res.add("");
        }
        for (int end = start + 1; end <= s.length(); end++) {
            if (wordDict.contains(s.substring(start, end))) {
                List<String> list = word_Break(s, wordDict, end);
                for (String l : list) {
                    res.add(s.substring(start, end) + (l.equals("") ? "" : " ") + l);
                }
            }
        }
        return res;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n^n)$，考虑最坏情况 $s$ = "$\text{aaaaaaa}$"，$s$ 的每一个前缀都在字典中，回溯树的大小会达到  $n^n$ 。

* 空间复杂度：$O(n^3)$，最坏情况下，回溯的深度可以达到 $n$ 层，每层可能包含 $n$ 个字符串，且每个字符串的长度都为 $n$ 。

<br />
#### 方法 2：记忆化回溯

**算法**

在之前的方法中，我们可以看出许多子问题的求解都是冗余的，也就是我们对于相同的子串调用了函数多次。

为了避免这种情况，我们使用记忆化的方法，我们使用一个 $key:value$ 这样的哈希表来进行优化。在哈希表中， $key$ 是当前考虑字符串的开始下标， $value$ 包含了所有从头开始的所有可行句子。下次我们遇到相同位置开始的调用时，我们可以直接从哈希表里返回结果，而不需要重新计算结果。

通过记忆化的方法，许多冗余的子问题都可以被省去，回溯树得到了剪枝，所以极大程度降低了时间复杂度。

```Java []
public class Solution {

    public List<String> wordBreak(String s, Set<String> wordDict) {
        return word_Break(s, wordDict, 0);
    }
    HashMap<Integer, List<String>> map = new HashMap<>();

    public List<String> word_Break(String s, Set<String> wordDict, int start) {
        if (map.containsKey(start)) {
            return map.get(start);
        }
        LinkedList<String> res = new LinkedList<>();
        if (start == s.length()) {
            res.add("");
        }
        for (int end = start + 1; end <= s.length(); end++) {
            if (wordDict.contains(s.substring(start, end))) {
                List<String> list = word_Break(s, wordDict, end);
                for (String l : list) {
                    res.add(s.substring(start, end) + (l.equals("") ? "" : " ") + l);
                }
            }
        }
        map.put(start, res);
        return res;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n^3)$ 。回溯树的大小最多 $n^2$ 。创建列表需要 $n$ 的时间。

<br />
#### 方法 3：使用动态规划

**算法**

这个方法背后的想法是对于给定的问题（$s$），它可以被拆分成子问题 $s1$ 和 $s2$ 。如果这些子问题分别都能满足条件，那么整个文字 $s$ 也可以满足。比方说， "$\text{catsanddog}$" 可以被拆分成子字符串 "$\text{catsand}$" 和 "$\text{dog}$" 。子问题 "$\text{catsand}$" 进一步可以被拆分成 "\text{cats}" 和 "\text{and}" ，它们分别都是字典的一部分，所以 "$\text{catsand}$" 也是满足条件的。递归回来，因为 "$\text{catsand}$" 和 "$\text{dog}$" 分别都满足要求，所以原字符串 "$\text{catsanddog}$" 也符合要求。

现在，我们来考虑 $\text{dp}$ 数组如何求出。我们使用长度为 $n+1$ 的数组 $\text{dp}$ ，其中 $n$ 是给定字符串的长度。 $\text{dp}[k]$ 被用来存储用 $s[0:k-1]$ 可被拆分成合法单词的句子。我们同事用两个指针 $i$ 和 $j$ ，其中 $i$ 表示子字符串 $s'$ 的长度（$s'$ 是 $s$ 的一个前缀）， $j$ 表示 $s'$ 的拆分位置，即拆分成 $s'(0,j)$ 和 $s'(j+1,i)$ 。

为了求出 $\text{dp}$ 数组，我们将 $\text{dp}[0]$ 初始化为空串。我们以 $i$ 为结尾表示的子字符串的所有前缀，通过指针 $j$ 将 $s$ 拆分成 $s1'$ 和 $s2'$ 。为了求出$\text{dp}[i]$ ，我们检查所有 $\text{dp}[j]$ 包含的所有非空字符串，也就是所有能形成 $s1'$ 的句子。如果存在，我们进一步检查 $s2'$ 是否在字典里，如果两个条件都满足，我们将子字符串 $s2'$ 添加到所有 $s1'$ 的句子的后面（这些句子已经保存在了 $dp[j]$ 里面），并将这些新形成的句子保存进（$\text{dp}[i]$）。最终， $\text{dp}[n]$ （$n$ 是给定字符串 $s$ 的长度）里面保存了所有可以得到完整字符串 $s$ 的所有句子。

 ```Java []
 public class Solution {
    public List<String> wordBreak(String s, Set<String> wordDict) {
        LinkedList<String>[] dp = new LinkedList[s.length() + 1];
        LinkedList<String> initial = new LinkedList<>();
        initial.add("");
        dp[0] = initial;
        for (int i = 1; i <= s.length(); i++) {
            LinkedList<String> list = new LinkedList<>();
            for (int j = 0; j < i; j++) {
                if (dp[j].size() > 0 && wordDict.contains(s.substring(j, i))) {
                    for (String l : dp[j]) {
                        list.add(l + (l.equals("") ? "" : " ") + s.substring(j, i));
                    }
                }
            }
            dp[i] = list;
        }
        return dp[s.length()];
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n^3)$，求 $\text{dp}$ 需要两重循环，添加一个新的列表需要额外一重循环。

* 空间复杂度：$O(n^3)$，$\text{dp}$ 数组的长度是$n$ ， $\text{dp}$ 数组里保存了数组，数组里是一些字符串，也就是每个 $\text{dp}$ 元素需要 $n^2$ 的空间。