##  解决方法：
####  方法一：暴力法
**算法：**
- 如果一个字符中只有一个字符可以更改，即它们的汉明距离为 1。 
- 在搜索新单词时，我们只检查长度相同的单词。 

```Python  [ ]
class MagicDictionary(object):
    def __init__(self):
        self.buckets = collections.defaultdict(list)

    def buildDict(self, words):
        for word in words:
            self.buckets[len(word)].append(word)

    def search(self, word):
        return any(sum(a!=b for a,b in zip(word, candidate)) == 1
                   for candidate in self.buckets[len(word)])
```

```Java [ ]
class MagicDictionary {
    Map<Integer, ArrayList<String>> buckets;
    public MagicDictionary() {
        buckets = new HashMap();
    }

    public void buildDict(String[] words) {
        for (String word: words) {
            buckets.computeIfAbsent(word.length(), x -> new ArrayList()).add(word);
        }
    }

    public boolean search(String word) {
        if (!buckets.containsKey(word.length())) return false;
        for (String candidate: buckets.get(word.length())) {
            int mismatch = 0;
            for (int i = 0; i < word.length(); ++i) {
                if (word.charAt(i) != candidate.charAt(i)) {
                    if (++mismatch > 1) break;
                }
            }
            if (mismatch == 1) return true;
        }
        return false;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(S)$ 构建和 $O(NK)$ 搜索，其中 $N$ 是魔法字典中的单词数，$S$ 是其中的字母总数，$K$ 是搜索单词的长度。 
* 空间复杂度：$O(S)$。 


####  方法二：广义邻居
回想一下，在方法 1 中，如果一个单词中只有一个字符可以更改以使字符串相等，那么两个单词就是邻居。 

让我们假设一个词 “apple” 具有广义邻居 *“pple”、“a*ple”、“ap*le”、“app*e” 和 *“appl”*。在搜索像 apply 这样的词是否有像 apple 这样的邻居时，我们只需要知道它们是否有一个广义邻居。 

**算法：**
继续上述思考，一个问题是 “apply” 不是自身的邻居，而是具有相同的广义邻居 “*pply”。为了解决这个问题，我们将计算生成 “*pply” 的源的数量。如果有 2 个或更多，则其中一个不会是 “apply”。如果只有一个，我们应该检查它不是 “apply”。无论是哪种情况，我们都可以确定有一些神奇的单词生成了 “*pply”，而不是 “apply”。 

```Python [ ]
class MagicDictionary(object):
    def _genneighbors(self, word):
        for i in xrange(len(word)):
            yield word[:i] + '*' + word[i+1:]

    def buildDict(self, words):
        self.words = set(words)
        self.count = collections.Counter(nei for word in words
                                        for nei in self._genneighbors(word))

    def search(self, word):
        return any(self.count[nei] > 1 or
                   self.count[nei] == 1 and word not in self.words
                   for nei in self._genneighbors(word))
```

```Java [ ]
public class MagicDictionary {
    Set<String> words;
    Map<String, Integer> count;

    public MagicDictionary() {
        words = new HashSet();
        count = new HashMap();
    }

    private ArrayList<String> generalizedNeighbors(String word) {
        ArrayList<String> ans = new ArrayList();
        char[] ca = word.toCharArray();
        for (int i = 0; i < word.length(); ++i) {
            char letter = ca[i];
            ca[i] = '*';
            String magic = new String(ca);
            ans.add(magic);
            ca[i] = letter;
        }
        return ans;
    }

    public void buildDict(String[] words) {
        for (String word: words) {
            this.words.add(word);
            for (String nei: generalizedNeighbors(word)) {
                count.put(nei, count.getOrDefault(nei, 0) + 1);
            }
        }
    }

    public boolean search(String word) {
        for (String nei: generalizedNeighbors(word)) {
            int c = count.getOrDefault(nei, 0);
            if (c > 1 || c == 1 && !words.contains(word)) return true;
        }
        return false;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(\sum w_i^2)$ 生成和 $O(K^2)$ 搜索，其中 $w_i$ 是 `words[i]` 的长度，$K$ 是搜索单词的长度。 
* 空间复杂度：$O(\sum w_i^2)$，`count` 使用的空间。在生成邻居进行搜索时，我们还使用 $O(K^2)$ 空间。