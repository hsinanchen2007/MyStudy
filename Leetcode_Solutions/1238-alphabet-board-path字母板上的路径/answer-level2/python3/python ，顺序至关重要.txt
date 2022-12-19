### 解题思路
此题的难点是移动顺序，因为z在最后一行，存在非法移动
所以当任何点移到z时，必须先向左，再向下
当从z移到任意一点时，必须先向上，再向右(很显然这里既是最左边，又是最下角，所以把左边和下面的操作放在前面不影响)
所以一个可能的顺序是 左 下 右 上，或者左 上 右 下 

### 代码
```
```python3
class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        ans=[]
        preRow=preCol=0
        for char in target:
            tmp=ord(char)-ord("a")
            curRow,curCol=tmp//5,tmp%5
        
            if curCol<preCol:
                hori=(preCol-curCol)*"L" 
                ans.append(hori)
            if curRow<preRow:
                verti=(preRow-curRow)*"U" 
                ans.append(verti)
            if curCol> preCol:
                hori=(curCol-preCol)*"R" 
                ans.append(hori)
            if curRow>preRow:
                verti=(curRow-preRow)*"D" 
                ans.append(verti)
            ans.append("!")
            preRow,preCol=  curRow,curCol
        return "".join(ans)
      
```

