### 解法

在开始本题的题解之前，我们首先看一下这个题要求我们做的事情的简单版本。我们需要设计一个类，在构造器中接收一个单词列表。这个类有一个我们需要去实现的函数，这个函数的名字叫 `shortest` ，它接收 2 个单词作为输入并返回这两个单词的最近距离。

两个单词的距离定义为它们在单词列表里的下标距离。比方说第一个单词在位置 `i` 出现第二个单词在位置 `j` 出现，那么两者的距离为 `abs(i - j)`。

问题问我们的单词间 `最小` 不同距离显然说明单词可能会出现在多个不同的位置。如果单词 `word1` 出现了 `K` 次， `word2` 出现了 `L` 次，我们重复检查每一对下标需要 $O(N^2)$ 的时间复杂度，这样没法进行优化，我们在此不会讨论这种比较显然的做法。

暴力方法会考虑所有的下标对（`word1_location`, `word2_location`），并看看能产生的最小距离。我们基于这个想法，并尝试用预处理来降低暴力解法的时间复杂度。

#### 方法：使用预处理并将下标排序

**想法**

一个给定的单词在原单词列表里出现几次。我们假设第一个单词 `word1` 在原数组中出现的位置为 `[i1, i2, i3, i4]` 。类似的，我们假设第二个单词 `word2` 出现的位置在 `[j1, j2, j3]` 。

现在，给定下标列表，我们将尝试找到绝对距离最小的下标对 `(i, j)` 。

> 这个方法的核心想法是如果这些下标对是有序的，我们可以用线性的时间找到距离最小的下标对。

这个思路使用两个指针来实现。对于一个排好序的下标对列表，我们用一个指针 `i` 代表 `word1` 的下标，指针 `j` 表示 `word2` 中的下标。每一次迭代，我们记录下标的距离，也就是 `abs(word1[i] - word2[j])` 。一旦我们更新答案后，我们有两种可能的下一步选择。

$$word1[i] < word2[j]$$

这种情况下，意味着我们往后移动 `j`是没有意义的。由于单词出现的位置是有序的，我们知道 `word2[j + 1] > word2[j]` ，所以如果我们移动 `j` ，那么 `abs(word1[i] - word2[j + 1])` 只会变得比 `abs(word1[i] - word2[j])` 更大，这对于找最小距离毫无帮助。

> 所以，如果我们 `word1[i] < word2[j]` ，我们往后移动指针 `i`，也就是我们去尝试第 `(i+1)` 个单词出现的位置的贡献 `abs(word1[i + 1] - word2[j])` 是否能比 `abs(word1[i] - word2[j])` 贡献一个更小距离。我们说尝试的原因是因为答案不一定更优。

让我们来看看两个不同的例子。在第一个例子中，我们看到向后移动 `i` 会给我们全局最优解。而在第二个例子中，我们可以看到向后移动 `i` 并不会求出更好的解。

**例子-1**

```
word1 = [2,4,5,9]
word2 = [4,10,11]

i, j = 0, 0
min_diff = 2 (abs(2 - 4))
word1[i] < word2[j] 即 2 < 4
  将 i 往后移动一步

i, j = 1, 0 (abs(4 - 4))
min_diff = 0 （我们得到了最优解！）
```

**例子-2**

```
word1 = [2,7,15,16]
word2 = [4,10,11]

i, j = 0, 0
min_diff = 2 (abs(2 - 4))
word1[i] < word2[j] 即 2 < 4
  将 i 往后移动一步

i, j = 1, 0
min_diff = 2 (2 < abs(7 - 4))

这里，我们没有更新全局结果。这就是我们前面说的将 'i' 移动或许不会得到更优解
但把 'j' 往后移动会让结果变得更差（或者保持不变）
```

下面让我们来讨论第二种情况。

$$word1[i] > word2[j]$$

这种情况下，将 `i` 往后移动没有意义，由于下标都排过序了，所以 `word1[i + 1] > word1[i]` 。如果我们将 `i` 往后移动，差 `abs(word1[i + 1] - word2[j])` 会比 `abs(word1[i] - word2[j])` 更大，对找最优解也毫无帮助。

> 所以，与前一种情况类似，如果 `word1[i] > word2[j]` ，我们会把 `j` 往后移动，并看是否能得到更优解。

现在让我们重新看一下这道题的完整解法。

**算法**

1. 在类的 `构造函数` 中，我们仅仅将单词列表遍历一遍，并用一个字典，将单词与它在数组中出现位置做一个映射。
2. 由于我们遍历单词列表的时候是从左到右的，我们得到的出现序列本身就是有序的，所以我们不需要额外排序。
3. 我们把这个字典叫做 `locations` 。
4. 对于给定的单词对，我们获取它们分别对应的列表数组，记作 `loc1` 和 `loc2` 。
5. 初始化两个指针变量 `l1 = 0` 和 `l2 = 0` 。
6. 对于给定的 `l1` 和 `l2` ，我们首先更新目前为止的最近距离（如果更优），即 `dist = min(dist, abs(loc1[l1] - loc2[l2]))` 。然后，我们判断如果 `loc1[l1] < loc2[l2]` ，那么移动 `l1` 一步，即 `l1 = l1 + 1`，否则我们移动 `l2` 一步，即 `l2 = l2 + 1` 。
7. 我们继续执行知道有一个指针到达了数组的末尾。
8. 返回全局最优解。

![image.png](https://pic.leetcode-cn.com/4947032370e30d438767529960eeb496ce15e00bf9bd27e352609c2967e04c44-image.png){:width="500px"}
{:align="center"}

上图展示了在构造函数中我们构建的位置字典。键代表的是单词，值是一个升序包含所有出现位置的列表。我们看一看 `apple` 和 `football` 之间的最近距离。我们需要用到的两个有序列表是 `[3, 6, 8, 12]` 和 `[2, 7, 9]` 。

<![image.png](https://pic.leetcode-cn.com/4e75f393e23a4d358dbc713155b9eb2c91586a98c0c3616a19c85af9a6fc6099-image.png),![image.png](https://pic.leetcode-cn.com/978544e2d2c7c92efde6b1f623268a960143caf1e842c746251db757f18bf063-image.png),![image.png](https://pic.leetcode-cn.com/d46d28a79f47da303f1f5e1d942b0c38b8929329aab5258a7a1851fd1353ed37-image.png),![image.png](https://pic.leetcode-cn.com/21edb6b0bec27efa3a8492af57031c1eb5ef8273885ee4e424923f42aee2324c-image.png),![image.png](https://pic.leetcode-cn.com/9fb0e04dcd7e26265652b7f14d291c7405300f944ad1dbb21f4b3b33ef8ef62f-image.png),![image.png](https://pic.leetcode-cn.com/0e6c908639531d9e26b6147cefac10bd8c166655df9e5fb4cf98f7b27a50f5a1-image.png),![image.png](https://pic.leetcode-cn.com/18ea3198b5eb2800bfbb430d1d76b5df761b15aa7c9205404c4ad41809055af5-image.png),![image.png](https://pic.leetcode-cn.com/787c2a25169390256962547bdb4b0dd164b8f95bea1f76095e773758ee561eff-image.png),![image.png](https://pic.leetcode-cn.com/6a3ea80555a3a936cc1913a9c9219786bc2c086d0cfea6b4714fad0c89a18610-image.png),![image.png](https://pic.leetcode-cn.com/e4811b975125c7a1d01681cbbf7786cd0d6b720ae99b8be0f65db49b8f38870b-image.png),![image.png](https://pic.leetcode-cn.com/31a764b2042871df0e18bce8125cc9cbc7cf9f5ab62c163553fb430363b05096-image.png),![image.png](https://pic.leetcode-cn.com/fdf84deb9fec60ce4d4c8fca9d91b0d5ec49ae24b0c87181f6dcd6419da02d97-image.png),![image.png](https://pic.leetcode-cn.com/15542ecc42690dc17054df2f84d79745b6f57a236206d74d9066ef65a15be4f9-image.png),![image.png](https://pic.leetcode-cn.com/960dad9d39e90e3ea424fd872e27008e114674c3bdaa92298d6aa57ce0f3197a-image.png),![image.png](https://pic.leetcode-cn.com/ea26f4d58423c5e12d47089ea1e34fd9c3a428ddb5424412b861db92fcbbf29c-image.png)>

```Java []
class WordDistance {

    HashMap<String, ArrayList<Integer>> locations;

    public WordDistance(String[] words) {
        this.locations = new HashMap<String, ArrayList<Integer>>();

        // Prepare a mapping from a word to all it's locations (indices).
        for (int i = 0; i < words.length; i++) {
            ArrayList<Integer> loc = this.locations.getOrDefault(words[i], new ArrayList<Integer>());
            loc.add(i);
            this.locations.put(words[i], loc);
        }
    }

    public int shortest(String word1, String word2) {
        ArrayList<Integer> loc1, loc2;

        // Location lists for both the words
        // the indices will be in SORTED order by default
        loc1 = this.locations.get(word1);
        loc2 = this.locations.get(word2);

        int l1 = 0, l2 = 0, minDiff = Integer.MAX_VALUE;
        while (l1 < loc1.size() && l2 < loc2.size()) {
            minDiff = Math.min(minDiff, Math.abs(loc1.get(l1) - loc2.get(l2)));
            if (loc1.get(l1) < loc2.get(l2)) {
                l1++;
            } else {
                l2++;
            }
        }

        return minDiff;
    }
}
```
```Python []
from collections import defaultdict
class WordDistance:

    def __init__(self, words):
        """
        :type words: List[str]
        """
        self.locations = defaultdict(list)

        # Prepare a mapping from a word to all it's locations (indices).
        for i, w in enumerate(words):
            self.locations[w].append(i)

    def shortest(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        loc1, loc2 = self.locations[word1], self.locations[word2]
        l1, l2 = 0, 0
        min_diff = float("inf")

        # Until the shorter of the two lists is processed
        while l1 < len(loc1) and l2 < len(loc2):
            min_diff = min(min_diff, abs(loc1[l1] - loc2[l2]))
            if loc1[l1] < loc2[l2]:
                l1 += 1
            else:
                l2 += 1
        return min_diff
```

**复杂度分析**

 - 时间复杂度：构造函数的时间复杂度为 $O(N)$ ，其中 N 是原本列表中单词的个数。我们逐一迭代遍历它们，并用一个键值对字典保存起来。然后，对于每一次查询最近距离，时间复杂度是 $O(max(K,L))$ 其中 $K$ 和 $L$ 分别表示两个单词对应数组的长度。同时我们知道， $K = O(N)$ 且 $L = O(N)$ 。因此，总时间复杂度是 $O(N)$ 的。时间复杂度**是** $O(max(K, L))$ **而不是** $O(min(K, L))$ 的原因是，有可能较短列表的元素比较长列表的元素都要大，这种情况下，较短列表不会被迭代而较长列表所有元素都会被遍历一次。
 - 空间复杂度：$O(N)$ 。 我们构造函数里产生的字典大小为 $O(N)$ 。键是单词列表里所有不同的单词，值是 $0 \dots N$ 的所有下标。
