### 解题思路
用mark做记录,mark起始为0。

当mark&1<<i==0时，代表i没有重复出现过,mark+=1<<i。

当mark&1<<i!=0，代表i已经出现过，我们需要找到i下一个没有出现过的数字。
假设此时mark=xxx0111xxx，其中xxx代表任意数量的0或1。
那么mark+1<<i=xxx1000xxx，注意其中xxx部分与mark一致，改变的部分恰为第i位到下一个0位。
我们将我们将mark取非，再与mark+1<<i进行与操作，再对所得结果取对数，即可得到下一个没有出现过的数。


### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        mark=0
        anw=0
        for i in A:
            if mark&1<<i!=0:
                tmp1=mark+(1<<i)
                tmp2=~mark
                tmp1=tmp1&tmp2
                num=int(math.log2(tmp1))
                anw+=num-i
                i=num
            mark+=1<<i
        return anw
```