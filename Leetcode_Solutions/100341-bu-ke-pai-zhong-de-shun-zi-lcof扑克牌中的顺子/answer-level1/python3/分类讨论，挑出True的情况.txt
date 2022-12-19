### 解题思路
分类讨论，挑选出顺子可能成立的情况，其他的全都是False。

0可能出现0、1、2、3、4次。
* 0不出现：5个数字不重复，且最大值-最小值=4
* 0出现1次：4个数字不重复，且最大值-最小值≤4
* 0出现2次：3个数字不重复，且最大值-最小值≤4
* 0出现3次：2个数字不重复，且最大值-最小值≤4
* 0出现4次：肯定成立

### 代码

```python3
class Solution:
    def isStraight(self, numbers: List[int]) -> bool:
        n_zeros = numbers.count(0)
        unique_nums = set(numbers)-set([0])
        if n_zeros==0 and len(unique_nums)==5 and max(unique_nums)-min(unique_nums)==4: return True
        if n_zeros==4: return True
        if n_zeros + len(unique_nums)==5 and max(unique_nums)-min(unique_nums)<=4: return True
        return False
```