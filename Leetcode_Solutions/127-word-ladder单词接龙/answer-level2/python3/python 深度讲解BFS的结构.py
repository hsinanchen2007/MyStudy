### 关键点：
1. 这道题对 检查两个单词是否是相邻的，复杂度要求很高。我们需要在很快的速度上判定，是否有可用的相邻节点
2. 需要将问题抽象化成为图论问题。



### 函数：defaultdict( type )
其传入参数必须是type, 例如 int, list, set等，而返回的默认值，就是这些type下的默认值，例如int返回的默认值是0，list是空list等

defaultdict与普通dict的最大作用在于：
你可以直接call一个不存在的key， 如果不存在这个key，那就先直接创建这个key，并根据默认值的设置，赋值value，而后在继续操作。
省去了
      dict[new] = dict.get(new, default = [])
      然后才能使用dict[new]来进一步操作。
相比之下：你可放心大胆的用：defaultdict[new] 管他有没有。


### BFS的标准套路：

```
for head in all_node()
    if head 没有visited过   # 以上两步是为了防止有孤立的部分存在而被遗漏，如果没有孤立的部分可以不写，直接放queue里一个就开始循环即可

        queue.append(head)
        mark head

        # 主干部分
        while queue is not empty:
            cur_node = queue.pop() # 我们不需要关心node将会以何种顺序出queue，我们只在乎如何往queue里进就行了。

            # 找邻居
            for 所有 cur_node 的邻居们：
                if cur_neighbour 没有visit过：

                    deal -> cur_neighbour
                    mark -> cur_neighbour
                    inject -> cur_neighbour

```
#### 结构总结
上述过程可以总结为四个模块

```
for 找head
    while queue：
        for 找邻居
            if 没有重复：处理，标记，入队

```
#### 如何mark
mark的方法有很多，常见的方法是把所有遍历过的node放到set里，每次都去set里查看，是否已经存在于set里了。
也可以写一个dict，key是node，value是bool，表示是否访问过了

#### 如何找邻居
在这道题中，找邻居的方法比较复杂：
```
for 所有可能去掉一个字母的同源
    for 每个同源的都是邻居

```

```
from collections import defaultdict
from collections import deque
class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        # 建立通用list
        size, general_dic = len(beginWord), defaultdict(list)
        for w in wordList:
            for _ in range(size):
                general_dic[w[:_]+"*"+w[_+1:]].append(w)
        # BFS
        queue = deque()
        queue.append((beginWord, 1))  # 因为在BFS中，queue中通常会同时混合多层的node，这就无法区分层了，要区分层就要queue中直接加入当前node所属层数。
        mark_dic = defaultdict(bool)  # bool 的默认值是false，因此所有不在list里的是false
        mark_dic[beginWord] = True
        while queue:
            cur_word, level = queue.popleft()   # queue头出来一个
            for i in range(size):               # 找邻居，这里的所有邻居都在level+1层
                for neighbour in general_dic[cur_word[:i]+"*"+cur_word[i+1:]]:
                    if neighbour == endWord: return level + 1
                    if not mark_dic[neighbour]:
                        mark_dic[neighbour] = True
                        queue.append((neighbour, level+1))  #符合条件（neighbour + unmarked)的进去
        return 0
```
