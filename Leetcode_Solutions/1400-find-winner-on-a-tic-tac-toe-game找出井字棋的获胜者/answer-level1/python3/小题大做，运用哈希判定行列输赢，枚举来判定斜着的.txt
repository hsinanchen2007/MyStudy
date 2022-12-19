### 解题思路
##运用哈希判定行列输赢，枚举来判定斜着的

### 代码

```python3
class Solution:
    def tictactoe(self, moves) -> str:
        #井字棋，a总是先走，一共可以走五局，最坏就是a走最后一颗棋子依然没有取胜
        #需要模拟随机走棋，自然需要导入random模块
        #判定胜负游戏进行到第三局开始判定胜负
        def isWin(flag):
            for j in range(2):
                hash1 = {}
                for i in range(flag,len(moves),2):
                    hash1[moves[i][j]] = hash1.get(moves[i][j],0)+1
                if max(hash1.values()) >=3:
                    return True
            win_set1 = ((0,0),(1,1),(2,2))
            win_set2 = ((2,0),(0,2),(1,1))
            count1 = 0
            count2 = 0
            for k in range(flag, len(moves), 2):
                if tuple(moves[k]) in win_set1:
                    count1 += 1
                if tuple(moves[k]) in win_set2:
                    count2 += 1
            count = count1 if count1 > count2 else count2
            # for m in range(1):
            #     for n in range(flag,len(moves),2):
            #         _is = moves[n][m]
            #         if moves[n][m+1] == _is*moves[n][m+1]/2:
            #             count += 1
            if count >=3:
                return True
            return False
        if not moves or len(moves) < 5:
            return 'Pending'
        elif 5 <=len(moves) <= 9:
            if isWin(0):
                return 'A'
            elif isWin(1):
                return 'B'
            elif not isWin(1) and not isWin(0) and len(moves) < 9:
                return 'Pending'
            else:
                return 'Draw'
```