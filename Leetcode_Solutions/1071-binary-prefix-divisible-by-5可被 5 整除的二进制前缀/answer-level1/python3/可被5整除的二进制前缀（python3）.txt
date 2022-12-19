#### 思路分析：
初始化相同大小的数组，遍历`A[i]`且转化为10进制后判断是否可被5整除，将结果更新在`res`中。
#### 参考代码
```
class Solution:
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        # 初始化结果[None,None,...,None]
        res = [None for _ in range(len(A))]
        s = ''
        for i,value in enumerate(A):
            s += str(value)
            if int(s,2) % 5 == 0: # 使用int(n,2)将二进制转化为10进制
                res[i] = True
            else:
                res[i] = False
        return res
```
#### 复杂度分析
- 时间复杂度：*O(N)*，这里*N*是数组的长度，遍历了一次数组
- 空间复杂度：*O(N)*，使用了长度为*N*的数组。
#### 利用二进制计算：
将二进制转化成十进制会消耗一定时间，以下代码可提高运算效率：
```
class Solution:
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        d = 0
        ans = []
        for i in A:
            d = (d<<1)|i  # 二进制运算
            ans.append(not d%5)
            d%=5
        return ans
```
#### 复杂度分析
- 时间复杂度：*O(N)*，这里*N*是数组的长度，遍历了一次数组
- 空间复杂度：*O(N)*，使用了长度为*N*的数组。

