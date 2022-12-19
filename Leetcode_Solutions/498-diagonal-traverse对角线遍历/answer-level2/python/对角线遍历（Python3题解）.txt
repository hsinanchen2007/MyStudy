### 解题思路
1.判断一个list是否为空，可以直接使用 not
2.逻辑表达式为 and、or、not，而不是&&等符号
3.可以尝试把多个变量定义在一行，减少代码量
4.三元表达式：（条件为真的结果）if （条件）eles （条件为假的结果）
5.Python中没有自增自减运算符，但是有赋值运算符

### 代码

```python
class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        ans=[]
        if not matrix or not matrix[0]:
            return ans

        m,n=len(matrix),len(matrix[0])

        flag,a,b=True,0,0
        for i in range(m+n):
            if flag:       
                a=i if i<m else m-1         
                b=i-a
                while a>=0 and b<n:
                    ans.append(matrix[a][b])
                    a-=1
                    b+=1
                flag=False
            else:
                b=i if i<n else n-1
                a=i-b
                while b>=0 and a<m:
                    ans.append(matrix[a][b])
                    a+=1
                    b-=1
                flag=True
        return ans
```