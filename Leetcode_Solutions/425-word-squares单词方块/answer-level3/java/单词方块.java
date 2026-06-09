####  概述
再深入研究解决方案之前，最好先退一步弄清楚问题的要求。

给定一个非重复的单词列表，要求我们构造所有可能的单词方块组合。这是单词方块的定义：

当且仅当从第 k 行形成的每个字符串（$H_k$）等于从第 k 列形成的字符串（$V_k$）时，单词序列形成有效的单词方块，即:
$$H_k == V_k \qquad \forall{k} \quad 0 ≤ k < \max(\text{numRows}, \text{numColumns}).$$

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDI1LzQyNV92YWxpZF93b3JkX3NxdWFyZS5wbmc?x-oss-process=image/format,png)
从定义中我们可以看到，由于行和列的形成的字符串相等形成单词方块，所以单词方块应在对角线上对称。

换句话说，如果我们知道单词方块的右上部分，我们可以推断出它的左下部分，反之亦然。单词方块中的对称性也可以解释为问题的约束，这可以帮助我们缩小有效组合的范围。

####  算法：回溯
**算法：**

给定一个单词列表，要求我们找到可以构成单词方块的单词的组合。解决上述问题的算法的主要部分可能非常简单。

其思想是我们从上到下一行一行的构造单词方块。在每一行中，我们只需尝试和出错，即尝试使用一个单词，如果不满足要求，则尝试另一个单词。

我们可能注意到，上述算法的思想实际上被称为回溯，它通常与递归和 DFS（深度优先搜索）相联系。

让我们用一个例子来说明这个想法。给定一个单词列表 `[ball, able, area, lead, lady]`，我们尝试将四个单词放在一起构建单词方块。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDI1LzQyNV9iYWNrdHJhY2sucG5n?x-oss-process=image/format,png)
- 让我们从单词 `ball` 开始，作为单词方块的第一个单词，也就是我们将放到第一行的单词。
- 然后我们转到第二行。考虑到单词方块的对称性，我们现在知道应该填充在第二行第一列的字母。也就是说，我们知道第二行的单词应该以 `a` 前缀开头。
- 在单词列表中，有两个前缀为 `a` 的单词（即 `able`，`area`）。这两个单词都可能是填充第二行单词的候选。下一步我们对这两个单词进行尝试。
- 下一步，我们用单词 `able` 填充在第二行。然后我们转向第三行。同样，由于对称性，我们知道了第三行中的单词应该以 `ll` 开头。不幸的是，单词列表中没有以 `ll` 开头的单词。导致我们不能继续填充单词方块。然后，放弃了此次尝试，返回到上一个状态（第一行已填充）。
- 下一步，我们尝试用单词 `area` 填充第二行。一旦我们填充第二行，我们知道在下一行中，要填充的单词应该以前缀 `le` 开头。这次我们在单词列表中找到了这样的单词，即 `lead`。
- 因此，下一步我们用 `lead` 这个单词填充第三行。等等等等。
- 最后，以每个单词为起始单词重复上述步骤，那么将包含所有的可能性来构造一个有效的单词方块。

```python [Algorithm-Python]
class Solution:

    def wordSquares(self, words: List[str]) -> List[List[str]]:

        self.words = words
        self.N = len(words[0])

        results = []
        word_squares = []
        for word in words:
            # try with every word as the starting word
            word_squares = [word]
            self.backtracking(1, word_squares, results)
        return results

    def backtracking(self, step, word_squares, results):

        if step == self.N:
            results.append(word_squares[:])
            return

        prefix = ''.join([word[step] for word in word_squares])
        # find out all words that start with the given prefix        
        for candidate in self.getWordsWithPrefix(prefix):
            # iterate row by row
            word_squares.append(candidate)
            self.backtracking(step+1, word_squares, results)
            word_squares.pop()

    def getWordsWithPrefix(self, prefix):
        for word in self.words:
            if word.startswith(prefix):
                yield word
```

扫视了一眼代码，这个问题似乎并不像它的难度等级一样令人畏惧。事实上，如果一个人能在面试中实现代码的框架，那么毫不客气的说，他已经完成了面试。

上述的实现是正确的，并在网上能通过大多数的测试用例。但是，对于某些较大的测试用例，他将遇到超出时间限制的异常。

但是，没有必要沮丧，因为我们已经知道了算法的难点。我们只需要最后解决优化的问题，这实际上可能是面试中的后续问题。


####  方法一：使用哈希表的回溯
正如我们上述回溯算法中注意到的，瓶颈在于函数 `getWordsWithPrefix()`，它将查找具有给定前缀的所有单词。在每次调用该函数时，我们都在遍历整个单词列表，具有线性时间复杂性 $\mathcal{O}(N)$。

优化 `getWordsWithPrefix()` 函数的一个想法时预先处理这些单词，构建一个数据结构，以便加快查找过程。

你们可能还记得，提供快速查找操作的数据结构之一称为哈希表或字典。我们可以简单构建一个哈希表，将所有可能的前缀作为键，将与前缀相关联的的那次作为表中的值。稍后，给定前缀，我们能够在常量时间 $\mathcal{O}(1)$ 中列出所有具有给定前缀的所有单词。

**算法：**

- 我们在上面列出的回溯算法的基础上，对两部分进行了调整。
- 第一部分，我们添加了一个新的函数 `buildPrefixHashTable(words)` 来根据输入的单词构建一个哈希表。
- 第二部分，在函数 `getWordsWithPrefix()` 中，我们查询哈希表来检索给定前缀的所有单词。

```python [solution1-Python]
class Solution:

    def wordSquares(self, words: List[str]) -> List[List[str]]:

        self.words = words
        self.N = len(words[0])
        self.buildPrefixHashTable(self.words)

        results = []
        word_squares = []
        for word in words:
            word_squares = [word]
            self.backtracking(1, word_squares, results)
        return results

    def backtracking(self, step, word_squares, results):
        if step == self.N:
            results.append(word_squares[:])
            return

        prefix = ''.join([word[step] for word in word_squares])
        for candidate in self.getWordsWithPrefix(prefix):
            word_squares.append(candidate)
            self.backtracking(step+1, word_squares, results)
            word_squares.pop()

    def buildPrefixHashTable(self, words):
        self.prefixHashTable = {}
        for word in words:
            for prefix in (word[:i] for i in range(1, len(word))):
                self.prefixHashTable.setdefault(prefix, set()).add(word)

    def getWordsWithPrefix(self, prefix):
        if prefix in self.prefixHashTable:
            return self.prefixHashTable[prefix]
        else:
            return set([])
```

```java [solution1-Java]
class Solution {
  int N = 0;
  String[] words = null;
  HashMap<String, List<String>> prefixHashTable = null;

  public List<List<String>> wordSquares(String[] words) {
    this.words = words;
    this.N = words[0].length();

    List<List<String>> results = new ArrayList<List<String>>();
    this.buildPrefixHashTable(words);

    for (String word : words) {
      LinkedList<String> wordSquares = new LinkedList<String>();
      wordSquares.addLast(word);
      this.backtracking(1, wordSquares, results);
    }
    return results;
  }

  protected void backtracking(int step, LinkedList<String> wordSquares,
                              List<List<String>> results) {
    if (step == N) {
      results.add((List<String>) wordSquares.clone());
      return;
    }

    StringBuilder prefix = new StringBuilder();
    for (String word : wordSquares) {
      prefix.append(word.charAt(step));
    }

    for (String candidate : this.getWordsWithPrefix(prefix.toString())) {
      wordSquares.addLast(candidate);
      this.backtracking(step + 1, wordSquares, results);
      wordSquares.removeLast();
    }
  }

  protected void buildPrefixHashTable(String[] words) {
    this.prefixHashTable = new HashMap<String, List<String>>();

    for (String word : words) {
      for (int i = 1; i < this.N; ++i) {
        String prefix = word.substring(0, i);
        List<String> wordList = this.prefixHashTable.get(prefix);
        if (wordList == null) {
          wordList = new ArrayList<String>();
          wordList.add(word);
          this.prefixHashTable.put(prefix, wordList);
        } else {
          wordList.add(word);
        }
      }
    }
  }

  protected List<String> getWordsWithPrefix(String prefix) {
    List<String> wordList = this.prefixHashTable.get(prefix);
    return (wordList != null ? wordList : new ArrayList<String>());
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N\cdot26^{L})$。其中 $N$ 是输入单词列表的单词数量和 $L$ 指的是单词的长度。
	*  在回溯算法中，要精确的计算运算次数是很困难的。我们知道回溯的路径会形成一颗 n 元树。因此，运算次数的上界是一颗完整 n 元树的结点总数。
	* 在我们的例子中，任何结点上，最多可以有 26 个分支（即 26 个字母）。因此 26 元树种的最大结点数约为 $26^L$ 。
	* 在回溯函数的循环种，我们列举了每个单词作为单词方块起始单词的可能性。因此，算法的总时间复杂度应为 $\mathcal{O}(N\cdot26^{L})$。
	* 实际上，回溯实际跟踪比上限小的多，这是由于约束检查大大减少了回溯的跟踪。
* 空间复杂度：$\mathcal{O}(N\cdot{L} + N\cdot\frac{L}{2}) = \mathcal{O}(N\cdot{L})$，其中 $N$ 是输入单词列表的单词数量和 $L$ 指的是单词的长度。
	*  空间复杂度的前半部分（即 $N\cdot{L}$）是哈希表种存储的值，长度为 $L$ 乘以单词列表中的单词数。
	* 空间复杂度的后半部分（即 $N\cdot\frac{L}{2}$）是哈希表键占用的空间，它包含所有单词的前缀。
	* 总的来说，可以说算法的总空间与单词的总数乘以单个单词的长度成正比。


####  方法二：使用单词查找树的回溯
说到前缀，还有另一种称为 Trie（也成为前缀树）的数据结构，可以在该问题中使用它。

在上述方法中，我们已将检索给定前缀的单词列表的时间复杂度从线性时间 $\mathcal{O}(N)$ 降到常量时间 $\mathcal{O}(1)$。作为交换，我们要花费一些额外的空间来存储每个单词的前缀。

Trie 数据结构提供了紧凑且快速的方法来检索具有给定前缀的单词。

下图中，我们展示了一个示例，说明如何从单词列表构建 Trie。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDI1LzQyNV90cmllLnBuZw?x-oss-process=image/format,png)
如我们所见，Trie 是一个  n 元树，其中每个结点表示前缀的一个字符。Trie 数据结构非常紧凑，可以存储前缀并且可以消除冗余前缀，例如 `le` 和 `la` 的前缀将共享一个结点。然而，从 Trie 检索单词仍然很快。检索一个单词需要  $\mathcal{O}(L)$，其中 $L$ 指的是


如我们所见，Trie基本上是一个n-aray树，其中每个节点表示前缀中的一个字符。Trie数据结构非常紧凑，可以存储前缀，因为它可以消除冗余前缀，例如le和la的前缀将共享一个节点。然而，从Trie检索单词仍然很快。检索一个单词需要$\mathcal{O}（L）$，其中$L$是单词的长度，比暴力枚举快得多。

**算法：**

- 我们在上面列出的回溯算法的基础上，对两部分进行了调整。
- 第一部分，我们添加了一个函数 `buildTrie(words)` 来输入单词构建 Trie
- 第二部分，在 `getWordsWithPrefix(prefix)` 函数中，我们查询 Trie 来检索具有给定前缀的单词。
- 下面是一些示例实现，注意，我们对 Trie 数据结构进行了一些调整，以便进一步优化时间和空间复杂性。
- 我们不在 Trie 的叶节点标记单词，而是在每个结点标记单词，这样一旦到达前缀中的最后一个结点，就不需要执行进一步的遍历。这个技巧可以优化时间复杂度。
- 我们没有在 Trie 存储实际的单词，而是保留单词的所有，这样可以大大节省空间。

```python [solution2-Python]
class Solution:

    def wordSquares(self, words: List[str]) -> List[List[str]]:

        self.words = words
        self.N = len(words[0])
        self.buildTrie(self.words)

        results = []
        word_squares = []
        for word in words:
            word_squares = [word]
            self.backtracking(1, word_squares, results)
        return results

    def buildTrie(self, words):
        self.trie = {}

        for wordIndex, word in enumerate(words):
            node = self.trie
            for char in word:
                if char in node:
                    node = node[char]
                else:
                    newNode = {}
                    newNode['#'] = []
                    node[char] = newNode
                    node = newNode
                node['#'].append(wordIndex)

    def backtracking(self, step, word_squares, results):
        if step == self.N:
            results.append(word_squares[:])
            return

        prefix = ''.join([word[step] for word in word_squares])
        for candidate in self.getWordsWithPrefix(prefix):
            word_squares.append(candidate)
            self.backtracking(step+1, word_squares, results)
            word_squares.pop()

    def getWordsWithPrefix(self, prefix):
        node = self.trie
        for char in prefix:
            if char not in node:
                return []
            node = node[char]
        return [self.words[wordIndex] for wordIndex in node['#']]
```

```java [solution2-Java]
class TrieNode {
  HashMap<Character, TrieNode> children = new HashMap<Character, TrieNode>();
  List<Integer> wordList = new ArrayList<Integer>();

  public TrieNode() {}
}


class Solution {
  int N = 0;
  String[] words = null;
  TrieNode trie = null;

  public List<List<String>> wordSquares(String[] words) {
    this.words = words;
    this.N = words[0].length();

    List<List<String>> results = new ArrayList<List<String>>();
    this.buildTrie(words);

    for (String word : words) {
      LinkedList<String> wordSquares = new LinkedList<String>();
      wordSquares.addLast(word);
      this.backtracking(1, wordSquares, results);
    }
    return results;
  }

  protected void backtracking(int step, LinkedList<String> wordSquares,
                              List<List<String>> results) {
    if (step == N) {
      results.add((List<String>) wordSquares.clone());
      return;
    }

    StringBuilder prefix = new StringBuilder();
    for (String word : wordSquares) {
      prefix.append(word.charAt(step));
    }

    for (Integer wordIndex : this.getWordsWithPrefix(prefix.toString())) {
      wordSquares.addLast(this.words[wordIndex]);
      this.backtracking(step + 1, wordSquares, results);
      wordSquares.removeLast();
    }
  }

  protected void buildTrie(String[] words) {
    this.trie = new TrieNode();

    for (int wordIndex = 0; wordIndex < words.length; ++wordIndex) {
      String word = words[wordIndex];

      TrieNode node = this.trie;
      for (Character letter : word.toCharArray()) {
        if (node.children.containsKey(letter)) {
          node = node.children.get(letter);
        } else {
          TrieNode newNode = new TrieNode();
          node.children.put(letter, newNode);
          node = newNode;
        }
        node.wordList.add(wordIndex);
      }
    }
  }

  protected List<Integer> getWordsWithPrefix(String prefix) {
    TrieNode node = this.trie;
    for (Character letter : prefix.toCharArray()) {
      if (node.children.containsKey(letter)) {
        node = node.children.get(letter);
      } else {
        // return an empty list.
        return new ArrayList<Integer>();
      }
    }
    return node.wordList;
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N\cdot26^{L}\cdot{L})$，其中 $N$ 指的是输入单词数量和 $L$ 指的是单个单词的长度。
	*  基本上，时间复杂度与方法一（$\mathcal{O}(N\cdot26^{L})$）相同，只是我们现在需要的不是 `getWordsWithPrefix(prefix)` 函数的常数时间访问，而是 $\mathcal{O}(L)$.
* 空间复杂度：$\mathcal{O}(N\cdot{L} + N\cdot\frac{L}{2}) = \mathcal{O}(N\cdot{L})$，其中 $N$ 指的是单词数量和 $L$ 指的是单个单词的长度。
	* 空间复杂度前半部分（即 $N\cdot{L}$） 是存储在 Trie 中的单词。
	* 空间复杂度后半部分（即 $N\cdot\frac{L}{2}$）是所有单词前缀的占用空间。最坏的清空下，前缀之间没有重叠。
	* 总的来说，这种方法与以前的方法具有相同的时间复杂度。然而，在运行时，由于我们所作的优化，它将消耗更少的内存。