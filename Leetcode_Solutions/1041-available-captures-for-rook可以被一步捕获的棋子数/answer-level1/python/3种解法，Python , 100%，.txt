## 解法一（行列查找）
思路：查找到白色车所在的坐标后，依次提取出对应的行列，然后在里面进行查找。
1. 提取白色车所在的行列坐标
2. 获取白色车对应行和列的值，组成新的列表
3. 在两个列表中判断和计算

* 时间复杂度：O(n^2^)
* 空间复杂度：O(n)
```python
class Solution:    
    def numRookCaptures(self, board: List[List[str]]) -> int:
        row,col , cnt = -1,-1,0
        lenRow, lenCol = len(board), len(board[0])
        #获取坐标位置
        for i in range(0,lenRow):
            if 'R' in board[i]:
                col = board[i].index('R')
                row = i
                break
        #子函数判断是否满足
        def checkP(bList, start, end, direct)-> int:
            for i in range(start,end,direct):
                if bList[i] == 'p':
                    return 1
                elif bList[i] == 'B':
                    return 0
            return 0
        #提取行列
        rowList = board[row]
        colList = [b[col] for b in board]
        #依次判断
        cnt += checkP(colList,row-1,-1,-1)
        cnt += checkP(colList,row+1,lenRow,1)
        cnt += checkP(rowList,col-1,-1,-1)
        cnt += checkP(rowList,col+1,lenCol,1)
        return cnt
```
***
## 解法二（递归查找）
思路：得到白色车所在行列后，以该位置为中心分别进行递归查找
1. 提取白色车所在的行列坐标
2. 使用递归在对应方向上持续寻找，直到边界
3. 分别计算前后左右四个不同的方向

* 时间复杂度：O(n^2^)
* 空间复杂度：O(1)
```python
class Solution:    
    def numRookCaptures(self, board: List[List[str]]) -> int:
        row,col , cnt = -1,-1,0
        lenRow, lenCol = len(board), len(board[0])
        #获取坐标位置
        for i in range(0,lenRow):
            if 'R' in board[i]:
                col = board[i].index('R')
                row = i
                break
        # 在一个方向上递归查找
        def checkP(rIdx, cIdx, rDelta, cDelta, lenList)-> int:
            if not( 0 <= rIdx < lenList and 0 <= cIdx < lenList):
                return 0
            if board[rIdx][cIdx] == 'p':
                return 1
            elif board[rIdx][cIdx] == 'B':
                return 0
            else :
                return checkP(rIdx + rDelta,cIdx + cDelta,rDelta,cDelta,lenList)
        # 四个方向分别计算
        cnt += checkP(row+1,col,1,0,lenRow)
        cnt += checkP(row,col+1,0,1,lenRow)
        cnt += checkP(row-1,col,-1,0,lenRow)
        cnt += checkP(row,col-1,0,-1,lenRow)
        return cnt
        
```

***
## 解法三（方向数组）
思路：基本原理跟解法二一致，使用方向数组进行循环查找
1. 提取白色车所在的行列坐标
2. 使用方向数组，在四个方向上分别进行循环，每次仅在一个方向上前进
3. 累计四个方向的判断结果

* 时间复杂度：O(n^2^)
* 空间复杂度：O(1)
```python
class Solution:    
    def numRookCaptures(self, board: List[List[str]]) -> int:
        row,col , cnt = -1,-1,0
        lenRow, lenCol = len(board), len(board[0])
        dirRow, dirCol = [1,0,-1,0],[0,1,0,-1]
        for i in range(0,lenRow):
            if 'R' in board[i]:
                col = board[i].index('R')
                row = i
                break
        for i in range(0,4):#4个方向
            rIdx, cIdx = row, col
            for j in range(0,lenRow):
                rIdx += dirRow[i]
                cIdx += dirCol[i]
                if not( 0 <= rIdx < lenRow and 0 <= cIdx < lenRow):
                    break
                if board[rIdx][cIdx] == 'p':
                    cnt += 1
                    break
                elif board[rIdx][cIdx] == 'B':
                    break
        return cnt        
```

欢迎大佬们，随手关注VX公众号【[真相很简单](https://www.zhenxiangsimple.com/img/zhenxiangSimple.jpg)】，拍砖指导，查看一题多解