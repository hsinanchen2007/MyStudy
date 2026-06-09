#### 方法一：暴力解法【超出时间限制】

我们在 $HashMap$ 中以 $(sentence_i, times_i)$ 的形式表示每条句子，其中 $times_i$ 表示句子 $sentence_i$ 出现的次数。

`AutocompleteSystem`：根据数组 $sentences$ 和 $times$ 将每条句子和它出现的次数存储到 $HashMap$ 中。

`input(c)`：使用变量 $cur\underline{}sent$ 记录当前正在输入的句子。对于每次输入的字符 $c$，先把它添加到  $cur\underline{}sent$ 的末尾，然后遍历 $HashMap$，如果存在句子的前缀为 $cur\underline{}sent$，就把该句子添加到 $list$ 中。最后根据每个句子出现的次数和 ASCII 码排序，返回前三个句子。

```java [solution1-Java]
public class AutocompleteSystem {
    HashMap < String, Integer > map = new HashMap < > ();
    class Node {
        Node(String st, int t) {
            sentence = st;
            times = t;
        }
        String sentence;
        int times;
    }
    public AutocompleteSystem(String[] sentences, int[] times) {
        for (int i = 0; i < sentences.length; i++)
            map.put(sentences[i], times[i]);
    }
    String cur_sent = "";
    public List < String > input(char c) {
        List < String > res = new ArrayList < > ();
        if (c == '#') {
            map.put(cur_sent, map.getOrDefault(cur_sent, 0) + 1);
            cur_sent = "";
        } else {
            List < Node > list = new ArrayList < > ();
            cur_sent += c;
            for (String key: map.keySet())
                if (key.indexOf(cur_sent) == 0) {
                    list.add(new Node(key, map.get(key)));
                }
            Collections.sort(list, (a, b) -> a.times == b.times ? a.sentence.compareTo(b.sentence) : b.times - a.times);
            for (int i = 0; i < Math.min(3, list.size()); i++)
                res.add(list.get(i).sentence);
        }
        return res;
    }
}

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * List<String> param_1 = obj.input(c);
 */
```

**性能分析**

* `AutocompleteSystem()` 的时间复杂度为 $O(k*l)$。在 $HashMap$ 中插入一条句子的时间为 $O(1)$。插入一条平均长度为 $k$ 的句子，需要扫描一次，一共有 $l$ 条句子，因此时间复杂度为 $O(k*l)$。

* `input()` 的时间复杂度为 $O\big(n+mlog(m)\big)$。遍历 $HashMap$ 中的 $n$ 条句子需要时间 $O(n)$，对长度为 $m$ 的 $list$ 排序需要 $O\big(mlog(m)\big)$ 的时间。


#### 方法二：使用一层索引【通过】

本方法与 *方法一* 类似，但是本方法中使用两层 $HashMap$ 存储句子和出现的次数。

使用数组 $arr$ 存储所有的句子和出现的次数，数组的每一项都是一个 $HashMap$，每个 $HashMap$ 存储相同首字母的所有句子。例如 $arr[0]$ 表示所有以 'a' 开头的所有句子的 $HashMap$。

在 `AutocompleteSystem` 中添加句子和查找句子的方法与 *方法一* 类似，只是本方法先使用第一层索引 $arr$ 找出对应首字母的 $HashMap$。

```java [solution2-Java]
public class AutocompleteSystem {
    HashMap < String, Integer > [] arr;
    class Node {
        Node(String st, int t) {
            sentence = st;
            times = t;
        }
        String sentence;
        int times;
    }
    public AutocompleteSystem(String[] sentences, int[] times) {
        arr = new HashMap[26];
        for (int i = 0; i < 26; i++)
            arr[i] = new HashMap < String, Integer > ();
        for (int i = 0; i < sentences.length; i++)
            arr[sentences[i].charAt(0) - 'a'].put(sentences[i], times[i]);
    }
    String cur_sent = "";
    public List < String > input(char c) {
        List < String > res = new ArrayList < > ();
        if (c == '#') {
            arr[cur_sent.charAt(0) - 'a'].put(cur_sent, arr[cur_sent.charAt(0) - 'a'].getOrDefault(cur_sent, 0) + 1);
            cur_sent = "";
        } else {
            List < Node > list = new ArrayList < > ();
            cur_sent += c;
            for (String key: arr[cur_sent.charAt(0) - 'a'].keySet()) {
                if (key.indexOf(cur_sent) == 0) {
                    list.add(new Node(key, arr[cur_sent.charAt(0) - 'a'].get(key)));
                }
            }
            Collections.sort(list, (a, b) -> a.times == b.times ? a.sentence.compareTo(b.sentence) : b.times - a.times);
            for (int i = 0; i < Math.min(3, list.size()); i++)
                res.add(list.get(i).sentence);
        }
        return res;
    }
}
```

**性能分析**

* `AutocompleteSystem()` 的时间复杂度为 $O(k*l+26)$。在 $HashMap$ 中插入一条记录的时间为 $O(1)$。插入一条平均长度为 $k$ 的句子，需要扫描一次，一共有 $l$ 条句子，因此时间复杂度为 $O(k*l)$。

* `input()` 的时间复杂度为 $O\big(s+mlog(m)\big)$。本方法需要遍历一个与当前句子首字母对应的 $HashMap$，再对长度为 $m$ 的 $list$ 排序需要时间 $O\big(mlog(m)\big)$。


#### 方法三：单词查找树【通过】

单词查找树包含节点和边，可以像树一样存储字符串。每个节点最多有 26 个子节点和边，边用于连接父节点和子节点，26 条边对应 26 个英文字母。

根据字符串中每个位置出现的字符，从上到下存储字符串。第一层存储字符串中出现的所有首字母，第二层存储字符串中第二个位置出现的所有字母。

单词查找树常用于存储字典中的所有单词。数的每一个层表示字符串对应位置上的字符。从词根开始到一个叶节点，就是一个单词。

修改单词查找树的结构，为每个单词增加访问次数标记 $times$，它存储在对应单词的叶节点。

在方法 `AutoComplete` 中，将  $sentences$ 数组中所有句子插入到单词查找树中，并在叶节点上添加每个句子出现的次数 $times$。

下图句子 `"A","to", "tea", "ted", "ten", "i", "in"`，每个句子出现次数为 `15, 7, 3, 4, 12, 11, 5, 9` 的单词查找树。

![](https://pic.leetcode-cn.com/Figures/642/642_Trie.PNG)

在方法 `input(c)` 中，对于每个输入的字符 `c`，首先将其添加到 $cur\underline{}sent$ 中。然后遍历当前单词查找树，直到当前单词 $cur\underline{}sent$ 所有的字符都已经查找到为止。

从 $cur\underline{}sent$ 中最后一个字符对应的节点开始，遍历该节点所有的分支，将每个分支对应的单词和它们出现的次数存储在 $list$ 中，然后根据出现次数和 ASCII 码大小排序，找出符合要求的前三个单词。

下面动画展示了单词查找树的一次插入过程。

<![1000](https://pic.leetcode-cn.com/Figures/642/642_Design_AutocompleteSlide1.PNG),![1000](https://pic.leetcode-cn.com/Figures/642/642_Design_AutocompleteSlide2.PNG),![1000](https://pic.leetcode-cn.com/Figures/642/642_Design_AutocompleteSlide3.PNG),![1000](https://pic.leetcode-cn.com/Figures/642/642_Design_AutocompleteSlide4.PNG),![1000](https://pic.leetcode-cn.com/Figures/642/642_Design_AutocompleteSlide5.PNG),![1000](https://pic.leetcode-cn.com/Figures/642/642_Design_AutocompleteSlide6.PNG),![1000](https://pic.leetcode-cn.com/Figures/642/642_Design_AutocompleteSlide7.PNG),![1000](https://pic.leetcode-cn.com/Figures/642/642_Design_AutocompleteSlide8.PNG),![1000](https://pic.leetcode-cn.com/Figures/642/642_Design_AutocompleteSlide9.PNG),![1000](https://pic.leetcode-cn.com/Figures/642/642_Design_AutocompleteSlide10.PNG),![1000](https://pic.leetcode-cn.com/Figures/642/642_Design_AutocompleteSlide11.PNG),![1000](https://pic.leetcode-cn.com/Figures/642/642_Design_AutocompleteSlide12.PNG),![1000](https://pic.leetcode-cn.com/Figures/642/642_Design_AutocompleteSlide13.PNG),![1000](https://pic.leetcode-cn.com/Figures/642/642_Design_AutocompleteSlide14.PNG)>

```java [solution3-Java]
public class AutocompleteSystem {
    class Node {
        Node(String st, int t) {
            sentence = st;
            times = t;
        }
        String sentence;
        int times;
    }
    class Trie {
        int times;
        Trie[] branches = new Trie[27];
    }
    public int int_(char c) {
        return c == ' ' ? 26 : c - 'a';
    }
    public void insert(Trie t, String s, int times) {
        for (int i = 0; i < s.length(); i++) {
            if (t.branches[int_(s.charAt(i))] == null)
                t.branches[int_(s.charAt(i))] = new Trie();
            t = t.branches[int_(s.charAt(i))];
        }
        t.times += times;
    }
    public List < Node > lookup(Trie t, String s) {
        List < Node > list = new ArrayList < > ();
        for (int i = 0; i < s.length(); i++) {
            if (t.branches[int_(s.charAt(i))] == null)
                return new ArrayList < Node > ();
            t = t.branches[int_(s.charAt(i))];
        }
        traverse(s, t, list);
        return list;
    }
    public void traverse(String s, Trie t, List < Node > list) {
        if (t.times > 0)
            list.add(new Node(s, t.times));
        for (char i = 'a'; i <= 'z'; i++) {
            if (t.branches[i - 'a'] != null)
                traverse(s + i, t.branches[i - 'a'], list);
        }
        if (t.branches[26] != null)
            traverse(s + ' ', t.branches[26], list);
    }
    Trie root;
    public AutocompleteSystem(String[] sentences, int[] times) {
        root = new Trie();
        for (int i = 0; i < sentences.length; i++) {
            insert(root, sentences[i], times[i]);
        }
    }
    String cur_sent = "";
    public List < String > input(char c) {
        List < String > res = new ArrayList < > ();
        if (c == '#') { 
            insert(root, cur_sent, 1);
            cur_sent = "";
        } else {
            cur_sent += c;
            List < Node > list = lookup(root, cur_sent);
            Collections.sort(list, (a, b) -> a.times == b.times ? a.sentence.compareTo(b.sentence) : b.times - a.times);
            for (int i = 0; i < Math.min(3, list.size()); i++)
                res.add(list.get(i).sentence);
        }
        return res;
    }
} 
```

**性能分析**

* `AutocompleteSystem()` 方法的时间复杂度为 $O(k*l)$，遍历 $l$ 条长度为 $k$ 的句子，并将他们插入到单词查找树中。

* `input()` 方法的时间复杂度为 $O\big(p+q+mlog(m)\big)$，其中 $p$ 表示当前已输入句子 $cur\underline{}sent$ 的长度，$q$ 表示单词查找树中的节点数量，最后对长度为 $m$ 的 $list$ 排序需要时间 $O\big(mlog(m)\big)$。