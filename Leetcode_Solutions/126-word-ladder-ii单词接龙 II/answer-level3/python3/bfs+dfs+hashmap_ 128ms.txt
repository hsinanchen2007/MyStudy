
思路:
    
- **最短路径, 用BFS比较合适**
- 一次BFS, 获取最短路径信息，如果直接存储路径入Queue，路径长度会随着层次数逐渐加大; 故改用**只存储前驱结点信息**。usedwords: word -> set of parent_word
- 前驱结点信息中**通过dfs(回溯)恢复路径**

总结:
1. hashable预处理wordList, 获取无向图的邻接关系
2. 层次遍历(bfs)，获取最短路径，通过前驱结点保留路径信息
3. 回溯法(dfs)恢复最短路径 (也可以用迭代恢复，代码读起来头疼)

```
p2w, len_word = defaultdict(list), len(beginWord)　＃预处理wordList
for word in wordList:
    for i in range(len_word):
        p2w[word[:i] + "*" + word[i + 1:]].append(word)

level, used_words = defaultdict(set), defaultdict(set)  # usedword -> parent
level[beginWord] = set()
used_words.update(level)
while level:　# 层次遍历
    if endWord in used_words: break
    next_level = defaultdict(set)
    for word in level:
        for i in range(len_word):
            for next_word in p2w[word[:i] + "*" + word[i + 1:]]:
                if next_word not in used_words:
                    next_level[next_word].add(word)
    level = next_level
    used_words.update(next_level)

def get_path(begin_word: str, end_word: str, used_words) -> List[str]:　＃恢复最短路径
    ans = []

    def dfs(begin_word: str, end_word: str, path: List[str]):
        if end_word not in used_words: return
        for w in used_words[end_word]:
            if w == begin_word: ans.append([w] + path)
            dfs(begin_word, w, [w] + path)
    dfs(begin_word, end_word, [end_word])
    return ans
ans = get_path(beginWord, endWord, used_words)
return ans
```
