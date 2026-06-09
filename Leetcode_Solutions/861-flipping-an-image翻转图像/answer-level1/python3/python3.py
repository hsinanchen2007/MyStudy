```
class Solution:
    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        for i in range(len(A)):
            for j in range((len(A[0])+1)//2):   #主要奇数列最中间的也需要被小狐狸
                A[i][j],A[i][~j]=1^A[i][~j],1^A[i][j]      #~j表示从右数第j个元素
        return A
```
