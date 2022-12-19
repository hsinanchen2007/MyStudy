先说下我的思路：我开始想的是如果在原二维数组上直接递归的话，那么还需要开辟一个二维数组来标记某个位置是否被访问过。而且直接使用递归的话，是三个方向去变量，比较复杂。于是我将word中的每个字母当成key，而其在board中出现的位置所组成的列表则为其values。
例如：
board = [["C", "A", "A"], ["A", "A", "A"], ["B", "C", "D"]], 
word = "AAB"
则有：dic = {"A":[(0,1), (0,2), (1,0), (1,1),(1,2), "B":[(2,0)]}

这个有点类似于用链表存储图，之后再利用dfs，深度搜索相应的word，每次确定了一个坐标后，需要将该坐标从该列表中删除，这个删除真的是费了我一番心思。开始是用的remove删除元素，append恢复元素，得到的结果大部分相悖于正确结果，后来慢慢的调试，找到了问题所在，使用del list[i]的形式删除元素，使用list.insert(i, obj)恢复元素。
代码如下：
```
    if not board or not board[0]: return False
    if not word: return True
    row_len = len(board)
    col_len = len(board[0])
    letters_idx = {}
    for i in range(row_len):
        for j in range(col_len):
            char = board[i][j]
            if char in word:
                tmp = letters_idx.get(char, [])
                tmp.append((i, j))
                letters_idx[char] = tmp.copy()
    flag = False

    def dfs(cur, coordinate):
        nonlocal flag
        if cur == len(word) - 1:
            flag = True
            return
        # 找到与当前字母相邻的
        for i, c in enumerate(letters_idx.get(word[cur + 1], [])):
            if (c[0] == coordinate[0] and abs(c[1] - coordinate[1]) == 1) or (
                    c[1] == coordinate[1] and abs(c[0] - coordinate[0]) == 1):
                del letters_idx[word[cur + 1]][i]
                dfs(cur + 1, c)
                letters_idx[word[cur + 1]].insert(i, c)
            if flag:
                break
        return

    for (i,tu) in enumerate(letters_idx.get(word[0], [])):
        del letters_idx[word[0]][i]
        dfs(0, tu)
        letters_idx[word[0]].insert(i, tu)
        if flag: return True
    return False
```
