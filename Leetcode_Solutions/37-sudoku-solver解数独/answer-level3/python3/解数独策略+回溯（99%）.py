### 解题思路
![5b4e6860de992e8fdb0fd89f1f13501.png](https://pic.leetcode-cn.com/fea6921c48f47b9dff933c93684cf2467fb3f8ff702dc9979db8ac9959d312c0-5b4e6860de992e8fdb0fd89f1f13501.png)

1.利用解数独策略把可以确定的值先确定下来；
2.常规回溯；

详见代码注释

### 代码

```python3
from collections import defaultdict
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        allnum = ['1','2','3','4','5','6','7','8','9']
        rows = [set(allnum) for _ in  range(9)] # 行剩余可用数字
        cols = [set(allnum) for _ in  range(9)] # 列剩余可用数字
        boxes = [set(allnum) for _ in  range(9)] # 块剩余可用数字
        empty = defaultdict(set) # 收集需填数位置，按行、列、方块缺失分成3部分，共27个集合
        #empty2 = []


        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':  # 更新可用数字
                    rows[i].remove(board[i][j])
                    cols[j].remove(board[i][j])
                    boxes[(i//3)*3+j//3].remove(board[i][j])
                else:
                    empty[i].add((i,j)) # 按行分块
                    empty[10+j].add((i,j)) # 按列分块，10+j是为了保证key值唯一
                    empty[100+(i//3)*3+j//3].add((i,j)) # 按方块分块，100+(i//3)*3+j//3是为了保证key值唯一
        #            empty2.append((i,j))

#        count2 = 0            
        def backtrack(count): #遍历空缺位置
#            global count2 #记录迭代次数
#            count2 += 1
            if count == len(empty2): # 处理完empty代表找到了答案
                return True
            i,j = empty2[count]
            b = (i//3)*3+j//3
            for num in rows[i] & cols[j] & boxes[b]: # 可用数字
                board[i][j] = num
                rows[i].remove(num)
                cols[j].remove(num)
                boxes[b].remove(num)
                if backtrack(count+1):
                    return True
                rows[i].add(num) # 回溯
                cols[j].add(num)
                boxes[b].add(num)
            return False

        #backtrack(0)
#        print(count2)    

        #L = defaultdict(set)
        # 下面的两大块代码根据解数独策略来确定可以确定的值
        def permut(l1): # 与常规回溯类似，稍作改动，寻找每个块（行、列、方块）的可行解，当某个位置上的可行解唯一时，该位置的值便可以确定了
            flag = False
            if len(l1) == 0: # 回溯终止条件：每个块的待安排位置为空
                return True
            i,j = l1[0]
            b = (i//3)*3+j//3
            for num in rows[i] & cols[j] & boxes[b]: # 可用数字
                L[l1[0]].append(num) # 添加位置（i，j）的疑似可行解
#                board[i][j] = num
                rows[i].remove(num)
                cols[j].remove(num)
                boxes[b].remove(num)
                if not permut(l1[1:]): # 走不通时，回溯，删除疑似可行解num
                    L[l1[0]].pop()
                else:
                    flag = True  # 存在可行解时，也需要回溯，尝试别的可行解          
#                board[i][j] = '.' 
                rows[i].add(num) 
                cols[j].add(num)
                boxes[b].add(num)        
            return flag #只要存在一个可行解，则返回True,否则返回False


        f = True
        while f: #遍历一遍后没有新增的确定值，则跳出循环
            f = False
            a=sorted(empty.values(),key=lambda x:len(x)) #根据缺失情况排序，缺失值越少，优先级越高
            for l in a:
                if len(l) > 5: # 缺失值数量大于5时较难确定，跳出循环
                    break
                L = defaultdict(list)
                if not permut(list(l)): # 出现错误，数独不存在可行解
                    f = False
                    break
                for key in L:
                    tmp = set(L[key])
                    if len(tmp) == 1: #当位置（i，j）的疑似可行解只有一个值时，可以确定该位置数值
                        i,j = key
                        num = tmp.pop()
                        board[i][j] = num
        #                print(i,j,num)
        #                print(board)
                        f = True
                        rows[i].remove(num)
                        cols[j].remove(num)
                        boxes[(i//3)*3+j//3].remove(num)
                        empty[i].remove(key)
                        empty[10+j].remove(key)
                        empty[100+(i//3)*3+j//3].remove(key)

        empty2 = []  # 合并剩余的空缺位置               
        for i in range(9):
            empty2.extend(list(empty[i]))
        backtrack(0) # 回溯
```