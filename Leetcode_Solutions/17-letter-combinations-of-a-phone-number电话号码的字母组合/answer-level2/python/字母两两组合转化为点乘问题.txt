### 解题思路
将字母两两组合转化为点乘问题，使用`itertools.product`巧妙解决；
注意考虑到空输入与单字符输入的情况。

### 代码

```python3
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        from itertools import product
        kb = {'2':'abc', '3':'def', '4':'ghi', '5':'jkl', '6':'mno', '7':'pqrs', '8':'tuv', '9':'wxyz'}
        if len(digits) == 1:
            return list(kb[digits])
        kbn = [kb[n] for n in list(digits)]
        ans = kbn[0]
        for i in range(1,len(digits)):
            ans = list(product(ans,kbn[i]))
            ans = [''.join(a) for a in ans]
        return ans
```
![image.png](https://pic.leetcode-cn.com/500d757e764a824f5a0f4e05edcd14a96d299e831707bc170f4315753eebe3f6-image.png)
