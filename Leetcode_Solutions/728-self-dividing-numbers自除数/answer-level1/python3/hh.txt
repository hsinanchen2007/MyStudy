### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        A=[str(i) for i in range(left,right+1)]
        M=[]
        for i in A:
            for b in range(len(i)):
                if int(i[b])==0:
                    break
                if int(i)%int(i[b])!=0:
                    break
            else:
                M.append(int(i))
        return M
```