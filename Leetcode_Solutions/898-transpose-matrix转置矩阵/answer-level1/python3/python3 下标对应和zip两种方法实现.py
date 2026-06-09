```
# 方法一，用下标的对应关系
class Solution1:
    def transpose(self, A) :
        B = [[None for _ in range(len(A))]for _ in range(len(A[0]))]  # 第二个for是行，第一个for是列
        for i in range(len(A)):
            for j in range(len(A[0])):
                B[j][i] = A[i][j]         # [i][j]反过来对应
        return B

# 方法二
class Solution:
    def transpose(self, A) :
        return list(zip(*A))
```