### 解题思路
本题实质上是一个排列组合+数组重构的问题。
1. 排列组合
如果有一个数对出现多次，考虑到多个数对选出2个，采取排列组合思想。
```python3
def Cni(n, i):
            Cni = 1
            for j in range(n-i+1, n+1):
                Cni *= j
            for j in range(1, i):
                Cni //= i
            return Cni if n >= i else 0
```
以上代码实现了“已知n个相同的数组，求共有多少对”的问题。

2. 数组重构
- 根据题意，只要数组中元素符合要求皆算作一对，为了减少运算，我们采取调换位置的方法，将每一个骨牌更小的数字调到前方。
- 接着，对列表两次排序，确保相同的牌在一起，以免每次都遍历整个列表。
- 设置计数器`i`,`count1`,`count2`，分别用来计算`index`，总对数，同一种牌相同牌的个数。
- 考虑下标，确保`i + count2`不超出范围，但是要保证所有元素都要遍历，因此在循环后设置`if`和`break`语句块，必要时跳出循环。

3. 结合上述两条思路，有如下代码：

### 代码

```python3
class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        def Cni(n, i):          # 组合数函数
            Cni = 1
            for j in range(n-i+1, n+1):
                Cni *= j
            for j in range(1, i):
                Cni //= i
            return Cni if n >= i else 0

        for dominoe in dominoes:    #将等价的骨牌设为同一种形式
            if dominoe[0] > dominoe[1]:
                dominoe[0], dominoe[1] = dominoe[1], dominoe[0]
        
        dominoes.sort(key=lambda x:x[0])    
        dominoes.sort(key=lambda x:x[1])    # 将相同的牌放到一起

        i = 0               # 首个被比较元素的下标
        count1 = 0          # 总的对数个数
        count2 = 0          # 相同牌重复的次数
        while i + count2 <= len(dominoes) - 1:
            while dominoes[i] == dominoes[i + count2]:
                count2 += 1
                if i + count2 == len(dominoes):     #超出index：跳出循环
                    break
            count1 += Cni(count2, 2)
            i += count2
            count2 = 1
            if i + count2 == len(dominoes):         # 超出index：跳出循环
                break
        return count1

```