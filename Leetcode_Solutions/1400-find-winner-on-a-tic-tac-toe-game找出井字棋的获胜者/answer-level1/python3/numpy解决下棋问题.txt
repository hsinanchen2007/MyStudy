### 解题思路
此处撰写解题思路
统计每行以及每列以及两条对角线是否出现三个X，或者三个O,若出现三个X则表示A赢若出现三个O则表示B赢，都没有出现，判断期盼中是否还要空格，没有则平手，反之没有下完
利用numpy可以方便产生矩阵和求和
### 代码

```python3
class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        import numpy as np

        a = np.random.randint(0,1,(3,3))

        num = 0
        for _ in moves:
            index_a,index_b = tuple(_)
            if num % 2 ==0:
                a[index_a][index_b]=1
            else:
                a[index_a][index_b]=-1
            num +=1
        if np.sum(a[0]) ==3 or np.sum(a[1]) ==3 or np.sum(a[2])==3 or np.sum(a[:,0])==3 or np.sum(a[:,1])==3 or\
        np.sum(a[:,2])==3 or (a[0][0]+a[1][1]+a[2][2])==3 or (a[0][2]+a[1][1]+a[2][0])==3:
            return("A")
        elif np.sum(a[0]) ==-3 or np.sum(a[1]) ==-3 or np.sum(a[2])==-3 or np.sum(a[:,0])==-3 or np.sum(a[:,1])==-3 or\
        np.sum(a[:,2])==-3 or (a[0][0]+a[1][1]+a[2][2])==-3 or (a[0][2]+a[1][1]+a[2][0])==-3:
            return("B")
        elif np.any(a==0):
            return("Pending")
        else:
            return("Draw")
```