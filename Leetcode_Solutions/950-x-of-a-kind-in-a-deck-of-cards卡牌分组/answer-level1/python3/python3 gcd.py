### 解题思路
此处撰写解题思路
提交错误4遍，看了题解才反应过来原来是一个求解最大公约数的问题。。。。
一开始想到的是hash，找到每个数字的个数，然后对题目意思理解出了问题，所以在 1，1，2，2，2，2 这样的case出现了判断失误，
以为同一个数字分配在一块，其实题目更本就没说。。。
然后这里为啥要找最大公约数呢，只要约数大于等于2就可以了啊？因为如果最大公约数都不大于等于2的话， 说明不可能分组成功的。
所以条件就是每个数字的个数组成的列表进行一个最大公约数的求解，用到了python 的 functools.reduce 进行求解。以及最大公约数math.gcd 或者 fractions.gcd都可以。

然后看到题解里面有的介绍说 int[10000]速度比hash快，python不知道如何使用呢？
### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        return functools.reduce(math.gcd,collections.Counter(deck).values())>1 
```