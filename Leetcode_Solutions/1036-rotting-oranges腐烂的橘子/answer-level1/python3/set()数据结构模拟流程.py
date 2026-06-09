### 解题思路
主要的数据结构包括fresh_set和corrupt_set,即保存了新鲜的橘子的位置和腐烂橘子的位置信息。
流程可以总结为：
1. 全局遍历：初始化fresh_set和corrupt_set；
2. 时间线：在此环节，根据fresh_set和corrupt_set数量的多少，选择遍历哪一个set()集合。即选择数量相对较少的集合进行遍历，节省时间开销；
3. 注意跳出条件。

### 代码

```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:

        def corrupt_part_search(i, j, cnt_set):
            # up
            if i-1 >= 0 and (i-1,j) in fresh_set:
                cnt_set.add((i-1,j))
            # doin
            if i+1 < rows and (i+1,j) in fresh_set:
                cnt_set.add((i+1,j))
            # left
            if j-1 >=0 and (i,j-1) in fresh_set:
                cnt_set.add((i,j-1))
            # right 
            if j+1 < cols and (i,j+1) in fresh_set:
                cnt_set.add((i,j+1))
            return cnt_set

        def fresh_part_search(i, j, cnt_set):
            # up
            if i-1 >= 0 and (i-1,j) in corrupt_set:
                cnt_set.add((i,j))
            # down
            elif i+1 < rows and (i+1,j) in corrupt_set:
            # left
                cnt_set.add((i,j))
            elif j-1 >=0 and (i,j-1) in corrupt_set:
                cnt_set.add((i,j))
            # right 
            elif j+1 < cols and (i,j+1) in corrupt_set:
                cnt_set.add((i,j))
            return cnt_set
 
        def global_search():
            for i in range(rows):
                for j in range(cols):
                    if grid[i][j] == 1:
                        fresh_set.add((i,j))
                    elif grid[i][j] == 2:
                        corrupt_set.add((i,j))

        rows = len(grid)
        cols = len(grid[0])

        fresh_set = set()
        corrupt_set = set() 
        cnt_set = set()
        global_search()
        if not fresh_set: return 0
        if not corrupt_set: return -1

        timer = 0
        while len(fresh_set) > 0:
            cnt_set.clear()
            if len(fresh_set) < len(corrupt_set) :
                # traverse freshes
                for (i,j) in fresh_set:
                    fresh_part_search(i,j,cnt_set)
            else:
                # traverse corrupts
                for (i,j) in corrupt_set:
                    corrupt_part_search(i,j,cnt_set)
            fresh_set -= cnt_set
            corrupt_set |= cnt_set
            if len(cnt_set) == 0: return -1
            timer += 1
        return timer
```