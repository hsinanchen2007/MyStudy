# 说实话，这道题花了我好几个小时。
思路比较容易想出来，比较标准的回溯算法。在解决边界问题和效率问题的时候踩了不少坑。在此梳理一下，算是自己的一个总结，也能能给其他同学提个醒。

## 1. 思路介绍
1. 拿到这道题，直观的感觉就是通过回溯算法进行处理。暴力能够解决，想要提升效率就要减少遍历内容，适当停止遍历。因此自然就会让人联想到树结构。
2. 每次从word中拿出一个字符，使用这个字符去匹配board中的字符。如果能匹配，则证明可行，使用word中下一个字符和board中下一个字符去比较。如果不行则此路不通，返回到上一个字符重新开始比较。
3. board中下一个字符有点像随机游走，使用当前字符周围相连的其它没有使用过的字符进行比较。
4. 持续执行2，3步骤，如果匹配上了，就返回true，没有返回false。

## 2. 实现代码
```
def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        x = len(board)
        y = len(board[0])
        def find_next(ix, iy, board, idx):
            tmp_char = board[ix][iy]
            if idx == len(word):
                return True

            if board[ix][iy] == word[idx]:
                if idx == len(word) - 1:
                    return True
                board[ix][iy] = 1
                if ix + 1 < x and board[ix + 1][iy] != 1:
                    if find_next(ix + 1, iy, board, idx + 1):
                        return True
                if ix - 1 >= 0 and board[ix -1][iy] != 1:
                    if find_next(ix - 1, iy, board, idx + 1):
                        return True
                if iy + 1 < y and board[ix][iy + 1] != 0:
                    if find_next(ix, iy+1, board, idx + 1):
                        return True
                if iy - 1 >= 0 and board[ix][iy - 1] != 0:
                    if find_next(ix, iy-1, board, idx + 1):
                        return True
                board[ix][iy] = tmp_char
            else:
                return False

        for i in range(x):
            for j in range(y):
                if  find_next(i,j, board, 0):
                    return True
               
        return False
```


## 3. 采坑积累
# 标记使用过的字符
开始使用的是一个等大小的矩阵，全部初始化为0，如果匹配上了就改为1。下次在使用的时候检查下这个位置的字符是否用过就可以了。
后来想到可以直接在原矩阵上进行修改，会更节省空间和时间。

# 边界问题
第一种边界问题就是越界，这个比较好处理，控制下下标大小就可以了。
第二种边界问题是标使用过的矩阵。这里一定要记得如果这条路不通，要把当前下标还原回去，否则会出误标的问题。有次提交失败就折在这里了。
还有一个是没有遍历原来的board字符，每次只从0，0开始。基本上回溯的外圈都要套一个遍历的，这个错误不应该犯。

# 效率提升
执行没问题之后有好几次超时，在此总结下注意事项。
1. 提交的时候把不必要打印出来的要关上，这会增加耗时。
2. 在递归内部尽量不要使用全局变量标记是否处理成功，尽量通过返回值去标记。我最后怎么都时间通过不了的问题就在这里。
3. 减少不必要的读取。在board上直接改变减少了数据查询，也能节省点效率。
