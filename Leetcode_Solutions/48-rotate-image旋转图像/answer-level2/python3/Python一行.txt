代码来源网络  
zip函数实现矩阵的转置，有兴趣的可以去查查zip这个函数的用法  
```
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        matrix[:]=map(list,zip(*matrix[::-1]))
```
Life is short, you need Python