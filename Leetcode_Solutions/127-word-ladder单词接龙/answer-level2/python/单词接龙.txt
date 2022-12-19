拥有一个 `beginWord` 和一个 `endWord`，分别表示图上的 `start node` 和  `end node`。我们希望利用一些中间节点（单词）从  `start node` 到  `end node`，中间节点是 `wordList` 给定的单词。我们对这个单词接龙每个步骤的唯一条件是相邻单词只可以改变`一个字母`。

![Word_Ladder_1.png](https://pic.leetcode-cn.com/fc3a60e60cb7a80723feea0689c25a6f1637df8c64cfec0d70a264eee7e88254-Word_Ladder_1.png){:width="400"}
{:align=center}

我们将问题抽象在一个无向无权图中，每个单词作为节点，差距只有一个字母的两个单词之间连一条边。问题变成找到从起点到终点的最短路径，如果存在的话。因此可以使用`广度优先搜索`方法。

算法中最重要的步骤是找出相邻的节点，也就是只差一个字母的两个单词。为了快速的找到这些相邻节点，我们对给定的 `wordList` 做一个预处理，将单词中的某个字母用 `*` 代替。

![Word_Ladder_2.png](https://pic.leetcode-cn.com/7212249f3e224d9d5ccbc292e902e48b572f965236378e034d8e03924404cba2-Word_Ladder_2.png){:width="400"}
{:align=center}

这个预处理帮我们构造了一个单词变换的通用状态。例如：`Dog ----> D*g <---- Dig`，`Dog` 和 `Dig` 都指向了一个通用状态 `D*g`。

这步预处理找出了单词表中所有单词改变某个字母后的通用状态，并帮助我们更方便也更快的找到相邻节点。否则，对于每个单词我们需要遍历整个字母表查看是否存在一个单词与它相差一个字母，这将花费很多时间。预处理操作在广度优先搜索之前高效的建立了邻接表。

例如，在广搜时我们需要访问 `Dug` 的所有邻接点，我们可以先生成 `Dug` 的所有通用状态：

1. `Dug => *ug`
2. `Dug => D*g`
3. `Dug => Du*`

第二个变换 `D*g` 可以同时映射到 `Dog` 或者 `Dig`，因为他们都有相同的通用状态。拥有相同的通用状态意味着两个单词只相差一个字母，他们的节点是相连的。

#### 方法 1：广度优先搜索

**想法**

利用广度优先搜索搜索从 `beginWord` 到 `endWord` 的路径。

**算法**

1. 对给定的 `wordList` 做预处理，找出所有的通用状态。将通用状态记录在字典中，键是通用状态，值是所有具有通用状态的单词。

2. 将包含 `beginWord` 和 `1` 的元组放入队列中，`1` 代表节点的层次。我们需要返回 `endWord` 的层次也就是从 `beginWord` 出发的最短距离。

3. 为了防止出现环，使用访问数组记录。

4. 当队列中有元素的时候，取出第一个元素，记为 `current_word`。

5. 找到 `current_word` 的所有通用状态，并检查这些通用状态是否存在其它单词的映射，这一步通过检查 `all_combo_dict` 来实现。

6. 从 `all_combo_dict` 获得的所有单词，都和 `current_word` 共有一个通用状态，所以都和 `current_word` 相连，因此将他们加入到队列中。

7. 对于新获得的所有单词，向队列中加入元素 `(word, level + 1)` 其中 `level` 是 `current_word` 的层次。

8. 最终当你到达期望的单词，对应的层次就是最短变换序列的长度。

   > 标准广度优先搜索的终止条件就是找到结束单词。

```Java []
import javafx.util.Pair;

class Solution {
  public int ladderLength(String beginWord, String endWord, List<String> wordList) {

    // Since all words are of same length.
    int L = beginWord.length();

    // Dictionary to hold combination of words that can be formed,
    // from any given word. By changing one letter at a time.
    HashMap<String, ArrayList<String>> allComboDict = new HashMap<String, ArrayList<String>>();

    wordList.forEach(
        word -> {
          for (int i = 0; i < L; i++) {
            // Key is the generic word
            // Value is a list of words which have the same intermediate generic word.
            String newWord = word.substring(0, i) + '*' + word.substring(i + 1, L);
            ArrayList<String> transformations =
                allComboDict.getOrDefault(newWord, new ArrayList<String>());
            transformations.add(word);
            allComboDict.put(newWord, transformations);
          }
        });

    // Queue for BFS
    Queue<Pair<String, Integer>> Q = new LinkedList<Pair<String, Integer>>();
    Q.add(new Pair(beginWord, 1));

    // Visited to make sure we don't repeat processing same word.
    HashMap<String, Boolean> visited = new HashMap<String, Boolean>();
    visited.put(beginWord, true);

    while (!Q.isEmpty()) {
      Pair<String, Integer> node = Q.remove();
      String word = node.getKey();
      int level = node.getValue();
      for (int i = 0; i < L; i++) {

        // Intermediate words for current word
        String newWord = word.substring(0, i) + '*' + word.substring(i + 1, L);

        // Next states are all the words which share the same intermediate state.
        for (String adjacentWord : allComboDict.getOrDefault(newWord, new ArrayList<String>())) {
          // If at any point if we find what we are looking for
          // i.e. the end word - we can return with the answer.
          if (adjacentWord.equals(endWord)) {
            return level + 1;
          }
          // Otherwise, add it to the BFS Queue. Also mark it visited
          if (!visited.containsKey(adjacentWord)) {
            visited.put(adjacentWord, true);
            Q.add(new Pair(adjacentWord, level + 1));
          }
        }
      }
    }

    return 0;
  }
}
```

```Python []
from collections import defaultdict
class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """

        if endWord not in wordList or not endWord or not beginWord or not wordList:
            return 0

        # Since all words are of same length.
        L = len(beginWord)

        # Dictionary to hold combination of words that can be formed,
        # from any given word. By changing one letter at a time.
        all_combo_dict = defaultdict(list)
        for word in wordList:
            for i in range(L):
                # Key is the generic word
                # Value is a list of words which have the same intermediate generic word.
                all_combo_dict[word[:i] + "*" + word[i+1:]].append(word)


        # Queue for BFS
        queue = [(beginWord, 1)]
        # Visited to make sure we don't repeat processing same word.
        visited = {beginWord: True}
        while queue:
            current_word, level = queue.pop(0)      
            for i in range(L):
                # Intermediate words for current word
                intermediate_word = current_word[:i] + "*" + current_word[i+1:]

                # Next states are all the words which share the same intermediate state.
                for word in all_combo_dict[intermediate_word]:
                    # If at any point if we find what we are looking for
                    # i.e. the end word - we can return with the answer.
                    if word == endWord:
                        return level + 1
                    # Otherwise, add it to the BFS Queue. Also mark it visited
                    if word not in visited:
                        visited[word] = True
                        queue.append((word, level + 1))
                all_combo_dict[intermediate_word] = []
        return 0
```

**复杂度分析**

* 时间复杂度：$O(M \times N)$，其中 $M$ 是单词的长度 $N$ 是单词表中单词的总数。找到所有的变换需要对每个单词做 $M$ 次操作。同时，最坏情况下广度优先搜索也要访问所有的 $N$ 个单词。
* 空间复杂度：$O(M \times N)$，要在 `all_combo_dict` 字典中记录每个单词的 $M$ 个通用状态。访问数组的大小是 $N$。广搜队列最坏情况下需要存储 $N$ 个单词。

#### 方法 2：双向广度优先搜索

**想法**

根据给定字典构造的图可能会很大，而广度优先搜索的搜索空间大小依赖于每层节点的分支数量。假如每个节点的分支数量相同，搜索空间会随着层数的增长指数级的增加。考虑一个简单的二叉树，每一层都是满二叉树的扩展，节点的数量会以 `2` 为底数呈指数增长。

如果使用两个同时进行的广搜可以有效地减少搜索空间。一边从 `beginWord` 开始，另一边从 `endWord` 开始。我们每次从两边各扩展一个节点，当发现某一时刻两边都访问了某一顶点时就停止搜索。这就是`双向广度优先搜索`，它可以可观地减少搜索空间大小，从而降低时间和空间复杂度。

![Word_Ladder_3.png](https://pic.leetcode-cn.com/be92086801e264f49bb1c01593dbfee5b08e52c600b62576c5fa0c1ef2d54eb8-Word_Ladder_3.png){:width="400"}
{:align=center}

**算法**

1. 算法与之前描述的标准广搜方法相类似。

2. 唯一的不同是我们从两个节点同时开始搜索，同时搜索的结束条件也有所变化。

3. 我们现在有两个访问数组，分别记录从对应的起点是否已经访问了该节点。

4. 如果我们发现一个节点被两个搜索同时访问，就结束搜索过程。因为我们找到了双向搜索的交点。过程如同从中间相遇而不是沿着搜索路径一直走。

   > 双向搜索的结束条件是找到一个单词被两边搜索都访问过了。

5. 最短变换序列的长度就是中间节点在两边的层次之和。因此，我们可以在访问数组中记录节点的层次。

![Word_Ladder_4.png](https://pic.leetcode-cn.com/77ff942730428bad804a3f3e8bcddb618ce7b26a2df85cae104c5c2563803dde-Word_Ladder_4.png){:width="400"}
{:align=center}

```Java []
import javafx.util.Pair;

class Solution {

  private int L;
  private HashMap<String, ArrayList<String>> allComboDict;

  Solution() {
    this.L = 0;

    // Dictionary to hold combination of words that can be formed,
    // from any given word. By changing one letter at a time.
    this.allComboDict = new HashMap<String, ArrayList<String>>();
  }

  private int visitWordNode(
      Queue<Pair<String, Integer>> Q,
      HashMap<String, Integer> visited,
      HashMap<String, Integer> othersVisited) {
    Pair<String, Integer> node = Q.remove();
    String word = node.getKey();
    int level = node.getValue();

    for (int i = 0; i < this.L; i++) {

      // Intermediate words for current word
      String newWord = word.substring(0, i) + '*' + word.substring(i + 1, L);

      // Next states are all the words which share the same intermediate state.
      for (String adjacentWord : this.allComboDict.getOrDefault(newWord, new ArrayList<String>())) {
        // If at any point if we find what we are looking for
        // i.e. the end word - we can return with the answer.
        if (othersVisited.containsKey(adjacentWord)) {
          return level + othersVisited.get(adjacentWord);
        }

        if (!visited.containsKey(adjacentWord)) {

          // Save the level as the value of the dictionary, to save number of hops.
          visited.put(adjacentWord, level + 1);
          Q.add(new Pair(adjacentWord, level + 1));
        }
      }
    }
    return -1;
  }

  public int ladderLength(String beginWord, String endWord, List<String> wordList) {

    if (!wordList.contains(endWord)) {
      return 0;
    }

    // Since all words are of same length.
    this.L = beginWord.length();

    wordList.forEach(
        word -> {
          for (int i = 0; i < L; i++) {
            // Key is the generic word
            // Value is a list of words which have the same intermediate generic word.
            String newWord = word.substring(0, i) + '*' + word.substring(i + 1, L);
            ArrayList<String> transformations =
                this.allComboDict.getOrDefault(newWord, new ArrayList<String>());
            transformations.add(word);
            this.allComboDict.put(newWord, transformations);
          }
        });

    // Queues for birdirectional BFS
    // BFS starting from beginWord
    Queue<Pair<String, Integer>> Q_begin = new LinkedList<Pair<String, Integer>>();
    // BFS starting from endWord
    Queue<Pair<String, Integer>> Q_end = new LinkedList<Pair<String, Integer>>();
    Q_begin.add(new Pair(beginWord, 1));
    Q_end.add(new Pair(endWord, 1));

    // Visited to make sure we don't repeat processing same word.
    HashMap<String, Integer> visitedBegin = new HashMap<String, Integer>();
    HashMap<String, Integer> visitedEnd = new HashMap<String, Integer>();
    visitedBegin.put(beginWord, 1);
    visitedEnd.put(endWord, 1);

    while (!Q_begin.isEmpty() && !Q_end.isEmpty()) {

      // One hop from begin word
      int ans = visitWordNode(Q_begin, visitedBegin, visitedEnd);
      if (ans > -1) {
        return ans;
      }

      // One hop from end word
      ans = visitWordNode(Q_end, visitedEnd, visitedBegin);
      if (ans > -1) {
        return ans;
      }
    }

    return 0;
  }
}
```

```Python []
from collections import defaultdict
class Solution(object):
    def __init__(self):
        self.length = 0
        # Dictionary to hold combination of words that can be formed,
        # from any given word. By changing one letter at a time.
        self.all_combo_dict = defaultdict(list)

    def visitWordNode(self, queue, visited, others_visited):
        current_word, level = queue.pop(0)
        for i in range(self.length):
            # Intermediate words for current word
            intermediate_word = current_word[:i] + "*" + current_word[i+1:]

            # Next states are all the words which share the same intermediate state.
            for word in self.all_combo_dict[intermediate_word]:
                # If the intermediate state/word has already been visited from the
                # other parallel traversal this means we have found the answer.
                if word in others_visited:
                    return level + others_visited[word]
                if word not in visited:
                    # Save the level as the value of the dictionary, to save number of hops.
                    visited[word] = level + 1
                    queue.append((word, level + 1))
        return None

    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """

        if endWord not in wordList or not endWord or not beginWord or not wordList:
            return 0

        # Since all words are of same length.
        self.length = len(beginWord)

        for word in wordList:
            for i in range(self.length):
                # Key is the generic word
                # Value is a list of words which have the same intermediate generic word.
                self.all_combo_dict[word[:i] + "*" + word[i+1:]].append(word)


        # Queues for birdirectional BFS
        queue_begin = [(beginWord, 1)] # BFS starting from beginWord
        queue_end = [(endWord, 1)] # BFS starting from endWord

        # Visited to make sure we don't repeat processing same word
        visited_begin = {beginWord: 1}
        visited_end = {endWord: 1}
        ans = None

        # We do a birdirectional search starting one pointer from begin
        # word and one pointer from end word. Hopping one by one.
        while queue_begin and queue_end:

            # One hop from begin word
            ans = self.visitWordNode(queue_begin, visited_begin, visited_end)
            if ans:
                return ans
            # One hop from end word
            ans = self.visitWordNode(queue_end, visited_end, visited_begin)
            if ans:
                return ans

        return 0
```

**复杂度分析**

* 时间复杂度：$O(M \times N)$，其中 $M$ 是单词的长度 $N$ 是单词表中单词的总数。与单向搜索相同的是，找到所有的变换需要 $M * N$ 次操作。但是搜索时间会被缩小一半，因为两个搜索会在中间某处相遇。
* 空间复杂度：$O(M \times N)$，要在 `all_combo_dict` 字典中记录每个单词的 $M$ 个通用状态，这与单向搜索相同。但是因为会在中间相遇，所以双向搜索的搜索空间变小。

