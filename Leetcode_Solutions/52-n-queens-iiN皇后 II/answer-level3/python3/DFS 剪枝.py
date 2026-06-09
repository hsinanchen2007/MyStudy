### 解题思路
&emsp;&emsp;需要熟悉皇后位置占用的规律，一个皇后固定在某一位置即这个皇后确定放置在某一行和某一列上后，这一行，这一列，还有斜着的撇和捺上面都不能放皇后了
&emsp;&emsp;在本代码中，先确定一个行row只有一个皇后，然后定义列cols的set集合，撇pie的set集合，捺na的set集合，这三个集合的作用是在对行row进行DFS将某一种皇后行放法置入result列表中之后，将皇后所在列col，以及涉及到的斜着的撇pie和捺na统统放入这三个集合中。
&emsp;&emsp;那么如何进行有序的放入呢？这里在对行row进行DFS的时候，对col进行一层循环，遍历当前row的所有col，将每一次有用的col置入cols集合中，而对于pie na集合，可以通过总结规律来放入，规律总结如下：对于pie集合，它们的所有元素的行和列之和(row + col)都是一个常数，而对于na集合，它们的所有元素的行和列之差(row - col)都是一个常数。这样就解决了放入集合中元素的问题
&emsp;&emsp;接下来是使用一次if判断，如果这一次循环的位置中有和三个set集合元素一样的，说明这次循环放入的位置被以前皇后给占用了，也就是不能放入，就continue进行下一次循环，如果没有出现与三个集合一样元素，就加入当前的set集合，然后进行下一次DFS也就是下一行的DFS，在一种方法所有DFS也就是一开始的if判断是否行大于等于n都执行完了之后，要对原来的set集合进行清空，以便进行下一种放法的皇后判断。
&emsp;&emsp;如何存储结果呢？这里在DFS的参数中加入一个cur_state 列表，列表中的内容是某一种放法所在列的位置，而列表的下标则表示这种放法所在行的位置，self.DFS(n, row + 1, cur_state + [col]) 通过这一行代码实现。
&emsp;&emsp;在这里通过if判断是否行数达到n，也就是到达最底层的DFS，到达了就使用append方法将cur_state列表加入result列表，result是一个二重列表。
&emsp;&emsp;52题只要将放法的数量结果输出，直接使用len()方法即可返回结果
&emsp;&emsp;这里就直接说一下51题，51题和本题总体都是完全一样的，只是返回的结果不一样，51题要返回所有放置方法位置的列表，上面也说过了，result列表中append的cur_state列表的的内容是某一种放法所在列的位置，列表的下标则表示这种放法所在行的位置，所以在51题中，对于result两重列表使用两重循环实现访问result列表中的cur_state子列表，通过对内容和下标代表含义的不同，将其需要的结果可以放置到另一个列表中，return也使用一次循环，因为需要返回多个方法。


### 代码
```python3
class Solution:
    def totalNQueens(self, n: int) -> int:
        if n < 1: return 0
        self.result = []
        self.cols = set(); self.pie = set(); self.na = set()
        self.DFS(n, 0, [])
        return len(self.result)

    def DFS(self, n, row, cur_state):
        if row >= n: 
            self.result.append(cur_state)
            return
        
        for col in range(n):
            if col in self.cols or row + col in self.pie or row - col in self.na:
                continue
            
            self.cols.add(col)
            self.pie.add(row + col)
            self.na.add(row - col)

            self.DFS(n, row + 1, cur_state + [col])

            self.cols.remove(col)
            self.pie.remove(row + col)
            self.na.remove(row - col)
```