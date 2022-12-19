```python []
from collections import defaultdict
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        
        if endWord not in wordList or not endWord or not beginWord or not wordList:
            return 0
        L = len(beginWord)
        
        all_combo_dict = defaultdict(list)  #创建叫all...字典
        for word in wordList:              #遍历列表的单词
            for i in range(L):             #循环一个单词的长度 从0开始
                all_combo_dict[word[:i] + "*" + word[i+1:]].append(word)  #一次{'h*t':[hot]} 两次{'*ot':[hot]}
        
         # Queue for BFS
        queue = [(beginWord, 1)]
        visited = {beginWord: True}
        while queue:
            current_word, level = queue.pop(0) #取出队列中第一个元素
            for i in range(L):                 #循环一个单词长度
                inter_word = current_word[:i] + "*" + current_word[i+1:]
                for word in all_combo_dict[inter_word]: #将一个单词（例*it h*t hi*）对应的单词遍历到word
                    if word == endWord:
                        return level + 1
                    if word not in visited:  #当word不等于endWord时
                        visited[word] = True
                        queue.append((word, level + 1))
                all_combo_dict[inter_word] = []   #上一步for循环之后将*单词对应的 单词改为[]
        
        return 0
                