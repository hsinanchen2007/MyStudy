### 解题思路
####递归基：
在碟子数<1时，不做任何操作
#### 递归：
1）在碟子数>=1时，先将上面n-1个碟子从A通过C移动到B，
2）再将最后一个盘子直接从A移动到C，
3）最后将n-1个碟子从B经过A移动到C，完成移动

### 代码

```python3
class Solution:
    def hanota(self, A: List[int], B: List[int], C: List[int]) -> None:
        """
        Do not return anything, modify C in-place instead.
        """
        def move(n,A,B,C):
            if n>=1:
                move(n-1,A,C,B)#A->B
                C.append(A[-1])#A->C
                A.pop()
                move(n-1,B,A,C)#B->C
        n=len(A)
        move(n,A,B,C)



```