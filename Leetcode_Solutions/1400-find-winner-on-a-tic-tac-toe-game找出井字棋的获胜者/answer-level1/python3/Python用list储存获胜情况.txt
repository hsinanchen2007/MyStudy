考虑到井字棋总共有棋子排成一行/一列/对角线时，即可获胜，所以对于玩家A和B分别用用一个长度为8的list储存获胜情况。

其中编号0-2的位置储存第0-2行的棋子的个数（**当一行有3个棋子时，即棋子排成了一行，获胜**）

3-5位置储存0-2列的棋子的个数（**当一列有3个棋子时，即棋子排成了一列，获胜**）

6位置储存行和列相等的棋子的个数（**即左上到右下的对角线上的棋子，三个时即获胜**）

7位置储存行和列相加为4的棋子的个数（**即右上到左下的对角线上的棋子，三个时即获胜**）

最后判断A和B中的最大值是否是3，如果是的话，则该玩家获胜。

如果都没有，判断移动步数是否为9，如果是9则为平局，否则是游戏未结束。

```
class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        A = [0]*8
        B = [0]*8
        l = len(moves)
        for n in range(l):
            if n%2:
                B[moves[n][0]] += 1
                B[moves[n][1]+3] += 1
                if moves[n][0]==moves[n][1]:
                    B[6]+=1
                if moves[n][0]+moves[n][1]==2:
                    B[7]+=1
            else:
                A[moves[n][0]] += 1
                A[moves[n][1]+3] += 1
                if moves[n][0]==moves[n][1]:
                    A[6]+=1
                if moves[n][0]+moves[n][1]==2:
                    A[7]+=1

        if max(A)==3:
            return 'A'
        elif max(B)==3:
            return 'B'
        elif l==9:
            return 'Draw'
        else:
            return 'Pending'
```
