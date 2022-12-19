### 解题思路
汉明距离为两个数的二进制表示中对应位置不同的数量，可以单位计：第i位上假设有m个0，n个1，则第i位上的汉明距离和为m*n,最后再相加。
map(func,iter)#映射
fun(*)#解包
zip(iter)#打包成列表元组

### 代码

```python3
class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        #和461汉明距离相似
        return sum(a.count('0')*a.count('1') for a in zip(*map('{:032b}'.format,nums)))

```