### 解题思路
1.前缀树需要实现插入以及删除功能

插入功能好实现,这里就不展开了。

删除功能的实现,如图:
![图片3.png](https://pic.leetcode-cn.com/5be6edd9fb84f8e17451c3932f685c591829ad39ace5ff3d868c06872fb981aa-%E5%9B%BE%E7%89%873.png)
1.从根结点开始往下遍历寻找子树。
2.当遍历到叶子结点时,若该叶子结点除了‘end’键,再无其他键,那么将'end'键删除。
3.递归向上,如果上一个结点进行了删除操作,那么如果当前结点只有一个key,那么可以删除这个key,否则结束递归。

剩下的工作,在每个起点回溯即可,当遇到不满足前缀的,便返回。

### 代码
```python
class Solution:
    def findWords(self, board: list, words: list) -> list:
        
        def insert(word):
            temp = trie['#']
            for char in word:
                if char not in temp.keys():
                    temp[char] = {}
                temp = temp[char]
            temp['end'] = True

        def remove(word, trie):
            if len(word) == 1:
                trie[word].pop('end')
                if len(trie[word]) >= 1:
                    return False
                else:
                    return True
            else:
                if remove(word[1:], trie[word[0]]):
                    trie[word[0]].pop(word[1])
                    if len(trie[word[0]].keys()) >= 1:
                        return False
                    else:
                        return True
                else:
                    return False

        def isValid(loc):
            return (0 <= loc[0] < len(board)) and (0 <= loc[1] < len(board[0]))

        def dfs(loc, combo, sub_trie):
            char = board[loc[0]][loc[1]]
            if char in sub_trie.keys():
                if 'end' in sub_trie[char].keys():
                    remove('#' + combo, trie)
                    result.append(combo)

                for direction in directions:
                    temp_loc = (loc[0]+direction[0], loc[1] + direction[1])
                    if char not in sub_trie.keys(): break

                    if isValid(temp_loc) and (temp_loc not in visited) and (board[temp_loc[0]][temp_loc[1]] in sub_trie[char].keys()):
                        visited.add(temp_loc)
                        dfs(temp_loc, combo + board[temp_loc[0]][temp_loc[1]], sub_trie[char])
                        visited.remove(temp_loc)
        # start
        trie = {'#': {}}
        directions = [(1,0),(-1,0),(0,1),(0,-1)]
        result = []

        for word in words:
            insert(word)

        for row in range(len(board)):
            for col in range(len(board[0])):
                visited = set()
                visited.add((row, col))
                dfs((row, col), board[row][col], trie['#'])

        return sorted(result)
```
