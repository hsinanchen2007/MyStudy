这一题是比较典型的广度遍历问题，题目要求是找到从 beginWord 到 endWord 的最短转换序列的长度，就拿示例一来说，如下图所示：

![qq_pic_merged_1560575947562.jpg](https://pic.leetcode-cn.com/eb8d0846437272966443547fd936c2231d4ad489012a95ebe9ab71cc6d2748c6-qq_pic_merged_1560575947562.jpg)

其实就是将beginWord 单词作为树的根节点，依次向下遍历，看这棵树的叶子结点有没有endWord （有时候也不一定是叶子结点）。如果存在，返回其深度depth，反之返回0。此处有一点需要注意：

在树上层出现过的字符串没必要在下层再次出现，因为如果该字符串是转换过程中必须经过的中间字符串，那么应该挑选上层的该字符串继续进行变化，它的转换次数少。

因为题目所求的是最短转换序列的长度，所以一定要记住这一点。

另外还有一点就是这个转换规则：每次转换只能改变一个字母。每一次迭代中如何来找当前单词的转换单词呢？这里面所用的方法有很多种，我看了网上的一些帖子，大致分为两种。一种是将改变的字母按照小写字母排列情况分为26种情况，依次填进去进行判断。另一种是将改变字母的那个位置用“_”代替，比如“hit”要改变第二个位置的字母，则可表示为“h_t”，而“hot”改变第二个位置的字母后也可表示为“h_t”，说明这两个单词是可以直接转换的。

下面我将依次给出这两种方法的代码。

方法一代码如下：
```python
class Solution(object):
    # 本题采用广度遍历方法
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        # 首先给wordList列表中单词去重
        word_set = set(wordList)
        # 定义当前层的单词集合为beginWord
        cur_word = [beginWord]
        # 定义下一层的单词集合
        next_word = []
        # 定义从 beginWord 到 endWord 的最短转换序列的长度
        depth = 1
        while cur_word:
            for word in cur_word:
                # 如果endWord出现在当前层的cur_word单词集合中，则立即返回该深度
                if word == endWord:
                    return depth
                for index in range(len(word)):
                    for indice in "abcdefghijklmnopqrstuvwxyz":
                        new_word = word[:index]+indice+word[index+1:]
                        if new_word in word_set:
                            word_set.remove(new_word)
                            next_word.append(new_word)
            # 如果endWord未出现在当前层的cur_word单词集合中，则深度+1
            depth += 1
            cur_word = next_word
            next_word = []
        return 0

if __name__ == "__main__":
    beginWord = "hit"
    endWord = "cog"
    wordList = ["hot","dot","dog","lot","log","cog"]
    sequence_length = Solution().ladderLength(beginWord, endWord, wordList)
    print(sequence_length)
```
执行效率很一般，在30%左右。

![image.png](https://pic.leetcode-cn.com/8c32b4d445c24400aa85ebd341aff50f4bdc709acf2aca73d014883fa57fd6cd-image.png)

方法二代码如下：
```python
class Solution(object):
    # 本题采用广度遍历方法
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        # 首先给wordList列表中单词去重
        word_set = set(wordList)
        word_dict = {}
        for word in word_set:
            for index in range(len(word)):
                new_word = word[:index]+"_"+word[index+1:]
                if new_word not in word_dict.keys():
                    word_dict[new_word] = [word]
                else:
                    word_dict[new_word].append(word)
        # 定义当前层的单词集合为beginWord
        cur_word = [beginWord]
        # 定义下一层的单词集合
        next_word = []
        # 定义从 beginWord 到 endWord 的最短转换序列的长度
        depth = 1
        while cur_word:
            for word in cur_word:
                # 如果endWord出现在当前层的cur_word单词集合中，则立即返回该深度
                if word == endWord:
                    return depth
                for index in range(len(word)):
                    new_word = word[:index]+"_"+word[index+1:]
                    if new_word in word_dict.keys():
                        for w in word_dict[new_word]:
                            if w not in next_word:
                                next_word.append(w)
                        del word_dict[new_word]
            # 如果endWord未出现在当前层的cur_word单词集合中，则深度+1
            depth += 1
            cur_word = next_word
            next_word = []
        return 0

if __name__ == "__main__":
    beginWord = "hit"
    endWord = "cog"
    wordList = ["hot","dot","dog","lot","log","cog"]
    sequence_length = Solution().ladderLength(beginWord, endWord, wordList)
    print(sequence_length)
```
但此种方法超出时间限制了，这让我有些费解，因为我始终觉得此方法迭代的次数会更少，效率自然也会更快。各位读者如果看出了我的错误，还望积极留言指出啊。
