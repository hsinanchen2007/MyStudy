### 解题思路
河内塔问题：

A 通过 B 移动到 C 上 k 个 =  A 通过 C 移动到 B 上前 k-1 个 + A 把 第 k 个放到 C上 + B 通过 A 把 k-1 个移动到 C 上

python 的语言特性 [list 删除一个元素的三种做法--python](https://www.cnblogs.com/lichunl/p/9622853.html)


### 代码

```python3
class Solution:
    def my_move(self, A, B, C, k): # move A 的前 k 个元素 by B to C
        if k == 1:
            C.append(A[-1])
            A.pop()
        else:
            self.my_move(A, C, B, k-1) # move A[1:] by C to B
            C.append(A[-1])
            A.pop()
            self.my_move(B, A, C, k-1)


    def hanota(self, A: List[int], B: List[int], C: List[int]) -> None:
        """
        Do not return anything, modify C in-place instead.
        """
        l = len(A)
        if l == 0:
            pass
        else:
            self.my_move(A, B, C, len(A)) # move A[1:] by C to B



```