#### 方法一：暴力解法【超出时间限制】

**思路和算法**

在 `S` 上遍历每个 `word`，首先找到第一个字母 `word[0]`，然后接着找第二个字母 `word[1]`，以此类推，直到在 `S` 中找到 `word` 的全部字母为止。

```java [solution1-Java]
class Solution {
    char[] ca, cb;
    public int numMatchingSubseq(String S, String[] words) {
        int ans = 0;
        ca = S.toCharArray();
        for (String word: words)
            if (subseq(word)) ans++;
        return ans;
    }

    public boolean subseq(String word) {
        int i = 0;
        cb = word.toCharArray();
        for (char c: ca) {
            if (i < cb.length && c == cb[i]) i++;
        }
        return (i == cb.length);
    }
}
```

```python [solution1-Python]
class Solution(object):
    def numMatchingSubseq(self, S, words):
        def subseq(word):
           it = iter(S)
           return all(x in it for x in word)

        return sum(subseq(word) for word in words)
```

**复杂度分析**

* 时间复杂度：$O(\text{words.length} * S\text{.length} + \sum_i \text{words[i].length})$，`subseq` 在 `S` 上遍历每个 `word[i]` 的时间复杂度为 $O(S\text{.length} + \text{words[i].length})$。

* 空间复杂度：$O(1)$。在 Java 中空间复杂度为 $O(S\text{.length} + \text{max(words[i].length)})$，但是如果使用指针可以实现 $O(1)$ 的空间复杂度。

#### 方法二：指向下一个字母的指针【通过】

**思路**

因为 `S` 很长，所以寻找一种只需遍历一次 `S` 的方法，避免暴力解法的多次遍历。

将所有单词根据首字母不同放入不同的桶中。例如当 `words = ['dog', 'cat', 'cop']`，根据首字母不同可以分为 `'c' : ('cat', 'cop'), 'd' : ('dog',)`。换句话说，每个桶中的单词就是该单词正在等待匹配的下一个字母。在遍历 `S` 的同时，将匹配到单词根据下一个需要匹配的字母移动到不同的桶中。

例如，有字符串 `S = 'dcaog'`：

* 初始化 `heads = 'c' : ('cat', 'cop'), 'd' : ('dog',)`；
* 遍历 `S[0] = 'd'` 后，`heads = 'c' : ('cat', 'cop'), 'o' : ('og',)`； 
* 遍历 `S[1] = 'c'` 后，`heads = 'a' : ('at',), 'o' : ('og', 'op')`；
* 遍历 `S[2] = 'a'` 后，`heads = 'o' : ('og', 'op'), 't': ('t',)` ;
* 遍历 `S[3] = 'o'` 后，`heads = 'g' : ('g',), 'p': ('p',), 't': ('t',)`；
* 遍历 `S[0] = 'g'` 后，`heads = 'p': ('p',), 't': ('t',)`。

**算法**

使用长度为 `26` 的数组 `heads` 做桶，每个字母对应一个桶。访问 `S` 中的每个字母时，将该字母对应桶中的所有单词，根据下一个等待匹配字母放入到不同的桶中。如果已经匹配到单词的最后一个字母，那么子序列单词数加 1。

```java [solution2-Java]
class Solution {
    public int numMatchingSubseq(String S, String[] words) {
        int ans = 0;
        ArrayList<Node>[] heads = new ArrayList[26];
        for (int i = 0; i < 26; ++i)
            heads[i] = new ArrayList<Node>();

        for (String word: words)
            heads[word.charAt(0) - 'a'].add(new Node(word, 0));

        for (char c: S.toCharArray()) {
            ArrayList<Node> old_bucket = heads[c - 'a'];
            heads[c - 'a'] = new ArrayList<Node>();

            for (Node node: old_bucket) {
                node.index++;
                if (node.index == node.word.length()) {
                    ans++;
                } else {
                    heads[node.word.charAt(node.index) - 'a'].add(node);
                }
            }
            old_bucket.clear();
        }
        return ans;
    }

}

class Node {
    String word;
    int index;
    public Node(String w, int i) {
        word = w;
        index = i;
    }
}
```

```python [solution2-Python]
class Solution(object):
    def numMatchingSubseq(self, S, words):
        ans = 0
        heads = [[] for _ in xrange(26)]
        for word in words:
            it = iter(word)
            heads[ord(next(it)) - ord('a')].append(it)

        for letter in S:
            letter_index = ord(letter) - ord('a')
            old_bucket = heads[letter_index]
            heads[letter_index] = []

            while old_bucket:
                it = old_bucket.pop()
                nxt = next(it, None)
                if nxt:
                    heads[ord(nxt) - ord('a')].append(it)
                else:
                    ans += 1

        return ans
```

**复杂度分析**

* 时间复杂度：$O(S\text{.length} + \sum_i \text{words[i].length})$。

* 空间复杂度：$O(\text{words.length})$。在 Java 中使用的额外空间为 $O(\sum_i \text{words[i].length})$，但是如果使用指针可以实现 $O(\text{words.length})$ 的空间复杂度。