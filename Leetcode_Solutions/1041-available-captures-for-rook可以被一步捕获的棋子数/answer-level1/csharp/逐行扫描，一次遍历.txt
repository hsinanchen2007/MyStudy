### 解题思路
逐行扫描，并且用bool数组`colHasP`记录某**列**是否包括有效的p（有效p是指，从p出发垂直往下走，不能先遇到白象，即可以先遇到白车，或者一路畅通到棋盘下边缘）；用`hasP`记录某**行**含有有效p（有效p是指，从p出发水平往右走，不能先遇到白象，即可以先遇到白车，或者一路畅通到棋盘右边缘）
- 当扫描到p时，标记该列含有有效p`colHasP[j] = true;`，并且标记该行含有有效p`hasP = true;`；如果已经扫描到白车r，则对比该p的坐标，要是与白车r在同一行，则这个有效p可以被白车捕获，捕获数++ `sum++;`（且该行不用继续扫描，因为一个方向最多捕获一个p，左边肯定统计过，这次统计了右边，则水平方向统计完毕）；如果该p与白车在同一列，则表示该有效p可以被白车捕获，且整个棋盘扫描结束（因为白车的左边，上边，右边三个方向之前统计过了，这次统计到了下方，至此四个方向统计完毕），可以直接返回`return sum + 1;`
- 当扫描到白象b时，如果已经扫描到白车r，则对比坐标，如果白象与白车r在同一行，则该行扫描结束（因为该行即使再有p，也被白象阻隔了），如果与白车r在同一列，则可以宣布扫描结束，因为白车r的同一行捕获肯定已经计算好，同一列的话，上方已经统计过了，下方已经被这个白象阻断，不会再捕获其他p了，所以扫描结束，返回sum；如果没遇到白车r，则更新有效p状态：该行之前记录的有效p失效了（被白象阻断）`hasP = false;`，该列记录的有效p也失效了`hasP = false;`
- 如果扫描到白车r，记录其坐标，并将该行和该列已经发现的有效p（即左上方已经扫描过的区域）加入sum
```
sum += colCount[j] ? 1 : 0;
sum += hasP ? 1 : 0;
```

### 代码

```csharp
public class Solution {
    public int NumRookCaptures(char[][] board) {
        bool[] colHasP = new bool[8];
        int sum = 0;
        int x = -1;
        int y = -1;
        for (int i = 0; i < 8; i++)
        {
            bool hasP = false;
            for (int j = 0; j < 8; j++)
            {
                if (board[i][j] == 'p')
                {
                    if (y == i)
                    {
                        sum++;
                        break;
                    }
                    if (x == j)
                    {
                        return sum + 1;
                    }
                    colHasP[j] = true;
                    hasP = true;
                    continue;
                }
                if (board[i][j] == 'B')
                {
                    if (y == i)
                    {
                        break;
                    }
                    if (x == j)
                    {
                        return sum;
                    }
                    colHasP[j] = false;
                    hasP = false;
                    continue;
                }
                if (board[i][j] == 'R')
                {
                    x = j;
                    y = i;
                    sum += colHasP[j] ? 1 : 0;
                    sum += hasP ? 1 : 0;
                }
            }
        }
        return sum;
    }
}
```