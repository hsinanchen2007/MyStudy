### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        if len(moves) < 5:
            #至少连成三个的moves是长度5
            return 'Pending'
        A = []#列表记录A走的
        B = []#列表记录B走的
        for i in range(1, len(moves), 2):
            A.append(moves[i - 1])
            B.append(moves[i])
        if len(moves) % 2 == 1:#moves长度是奇数的时候最后一步总是A的
            A.append(moves[len(moves) - 1])

        scnt = scnt1 = scnt2 =0 #记录A竖是否3个
        hcnt = hcnt1 = hcnt2 =0 #记录A横是否3个
        xcnt = xcnt1 = 0 #A斜是否3个
        bscnt = bscnt1 = bscnt2 = 0  # 记录B竖是否3个
        bhcnt = bhcnt1 = bhcnt2 = 0  # 记录B横是否3个
        bxcnt = bxcnt1 = 0  # B斜是否3个

        for item in A:
            #竖
            if item in [[0,0],[1,0],[2,0]]:
                scnt += 1
            if item in [[0,1],[1,1],[2,1]]:
                scnt1 += 1
            if item in [[0,2],[1,2],[2,2]]:
                scnt2 += 1
            #横
            if item in [[0,0],[0,1],[0,2]]:
                hcnt += 1
            if item in [[1,0],[1,1],[1,2]]:
                hcnt1 += 1
            if item in [[2,0],[2,1],[2,2]]:
                hcnt2 += 1
            #斜
            if item in [[2,0],[1,1],[0,2]]:
                xcnt += 1
            if item in [[0,0],[1,1],[2,2]]:
                xcnt1 += 1

        for item in B:
            #竖
            if item in [[0,0],[1,0],[2,0]]:
                bscnt += 1
            if item in [[0,1],[1,1],[2,1]]:
                bscnt1 += 1
            if item in [[0,2],[1,2],[2,2]]:
                bscnt2 += 1
            #横
            if item in [[0,0],[0,1],[0,2]]:
                bhcnt += 1
            if item in [[1,0],[1,1],[1,2]]:
                bhcnt1 += 1
            if item in [[2,0],[2,1],[2,2]]:
                bhcnt2 += 1
            #斜
            if item in [[2,0],[1,1],[0,2]]:
                bxcnt += 1
            if item in [[0,0],[1,1],[2,2]]:
                bxcnt1 += 1
        if scnt == 3 or scnt1 == 3 or scnt2 == 3 or hcnt == 3 or hcnt1 == 3 or hcnt2 == 3 or xcnt == 3 or xcnt1 == 3:
            return 'A'
        elif bscnt == 3 or bscnt1 == 3 or bscnt2 == 3 or bhcnt == 3 or bhcnt1 == 3 or bhcnt2 == 3 or bxcnt == 3 or bxcnt1 == 3:
            return 'B'
        elif 9 - len(moves) != 0:
            #没下完呢
            return 'Pending'
        else:
            return 'Draw'
        
```