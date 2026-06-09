### 解题思路
从第一行开始遍历每一个点,创建一个ban_list，每一行检查不在ban_set中的点，将它产生的不能放的点放入ban_set中

### 代码

```python3
class Solution:
    def solveNQueens(self, n: int):
        res = []
        def judge(i,current,ban_set):
            #对第i行的点做判断
            for j in range(n):
#                 if i == 0 :
#                     ban_set = set()
                if (i,j) in ban_set:
                    continue
                else:
                    if i == n-1:
                        res.append(current + [j])
                    else:
                        judge(i+1,current+[j],up_date(i,j,ban_set))
            return

        def up_date(i,j,ban_set):
            #i,j点确定后，更新ban_set
            distance = 1
            ban = ban_set.copy()
            while i + distance <= n-1:
                if (i+distance,j) not in ban:
                    ban.add((i+distance,j))
                if j - distance >= 0 and (i+distance,j-distance) not in ban:
                    ban.add((i+distance,j-distance))
                if j + distance <= n-1 and (i+distance,j+distance) not in ban:
                    ban.add((i+distance,j+distance))
                distance += 1
            return ban
        
        judge(0,[],ban_set = set())
        #把res转化为输出需要的形式
        for i in range(len(res)):
            for j in range(len(res[i])):
                temp = ['.'] * n
                temp[res[i][j]] = 'Q'
                res[i][j] = ''.join(temp)
        return res 


                            

```