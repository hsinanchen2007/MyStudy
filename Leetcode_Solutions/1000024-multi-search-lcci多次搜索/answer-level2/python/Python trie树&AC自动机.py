### 解题思路
这两天刚学了AC自动机，来找个题练练怎么写（感觉这个题挺适合练习的），耗时是肯定比不了，毕竟O(n)的复杂度是剔除了自动机构建步骤的。

这道题按着标准的AC自动机写会有一个问题：给的词库本身是相互包含的，但是要求全部定位出来：
``` smalls = ["is","ppi","hi","sis","i","ssippi"] ```
比如 ```sis``` 包含了```[sis, i, is]```，而基础的AC自动机只会检测出 ```sis```; ```ssippi``` 同理。这时候就可以利用fail指针指向的是最长相同后缀这个特性，去递归搜索，有两种方法：
1. 构造自动机的时候利用fail指向节点的标记来更新自己的标记，比如本来的标记是这样： ```ssippi(end)```，现在更新为这样 ```ssi(end1)ppi(end2,end3)```;
![image.png](https://pic.leetcode-cn.com/2423ec630816ea964c54922d4809ad51e7e5deb9f4e7ffe5d72af6cc974703ff-image.png)
2. 搜索的时候每匹配上一个字符就顺着fail指针一路跑到root，将路上的遇到的标记都存储下来。
![image.png](https://pic.leetcode-cn.com/9106ee0eeaf0838c338ddaa9ff951251bee0803c849a771d05bdd6f7509cc7b4-image.png)

居然第二种的用时和内存都优于第一种=。=  不过反正是练习嘛，不在意这么多了，但是词库确定的时候比如 敏感词过滤/替换 肯定还是第一种的办法好啊。

可以通过存储start index来得到smalls出现的位置，我偷懒直接存储了单词长度来相减了。

### 补一点AC自动机的知识
AC自动机就是在trie树的基础上，给每个节点加一个fail指针；
在匹配失败的情况下一律跳转至fail（万能备胎）；
这个fail指针的**创建和使用**都是**递归**的，都会有顺着A节点的fail指针跳到B节点，再从B节点顺着fail指针跳到C节点的过程；
这个递归过程的终止条件是fail指针为空，也就是递归到无路可走，**有且只有root节点的fail指针为空**；

fail指针的构建规则：
 - root节点的fail为None；
 - root的孩子节点的fail全部指向root（第一个字符就匹配失败了 不回到最开始还想咋地）
 - 剩下的fail指针采用bfs一层层向下构建。
 - 懒得写了。

### 代码
这个代码是方法2搜索时递归跑fail指针；方法1只要在每次node.fail指针计算完毕后，用node.fail.data 来更新一下node.data就好了
```python3
from collections import defaultdict, deque

class Solution:
    def multiSearch(self, big: str, smalls: List[str]) -> List[List[int]]:
        trie = Trie()
        trie.insert(smalls)
        trie.ac_automation()
        res = trie.search(big)
        return [res[word] for word in smalls]

# 树节点
class Node:
    def __init__(self):
        self.child = {}
        self.fail = None
        self.data = None

class Trie:
    def __init__(self):
        self.root = Node()

    def insert(self, words) -> None:
        for word in words:
            cur = self.root
            for c in word:
                if c not in cur.child:
                    cur.child[c] = Node()
                cur = cur.child[c]
            cur.data = word # 标记单词结束，并且存储一些内容, 现在图省事存的单词

    def ac_automation(self):
        queue = deque()
        # 第一层节点的fail指针全部指向root，并且入队列。
        for k,v in self.root.child.items():
            v.fail = self.root
            queue.append(v)

        while len(queue):
            current = queue.popleft() 
            for k,v in current.child.items(): # 更新孩子节点们的fail指针
                cur_fail = current.fail
                while cur_fail: 
                    if  k in cur_fail.child: # 如果找到相同节点，将fail指针指过去，跳出循环
                        v.fail = cur_fail.child[k]
                        break
                    else:
                        cur_fail = cur_fail.fail 
                if v.fail == None: # 找不到相同节点就指向root
                    v.fail = self.root
                ##################### 方法1更新节点处 #########################
                # 更新队列
                queue.append(v)
                

    def search(self, word: str):
        cur = self.root
        res = defaultdict(list)
        
        for i in range(len(word)):
            # 一直往fail指针跳，直到找到相同字符/回到了root
            while word[i] not in cur.child and cur.fail != None: 
                cur = cur.fail
            # 这道题只需处理找到了相应字符的情况，没找到直接跳过就行了
            if word[i] in cur.child: 
                cur = cur.child[word[i]] 
                tmp = cur
                while tmp.fail != None:  # 加while跑遍所有fail来用来应对这道题
                    if tmp.data is not None:
                        res[tmp.data].append(i - len(tmp.data) + 1)
                    tmp = tmp.fail
        
        return res
```