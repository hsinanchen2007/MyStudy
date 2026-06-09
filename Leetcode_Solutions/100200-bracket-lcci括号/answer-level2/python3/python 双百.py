### 解题思路
![1584153281(1).png](https://pic.leetcode-cn.com/8e4306227438874073fd1f64f59dd5c41ce1c726c2665eaac5c56729a39455c0-1584153281\(1\).png)

题目中有个隐含条件：就是 ( 在组合时候比 ) 用的多或相等
然后用回溯

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        re = []
        state = ''

        def dsp(state, p, q):       #p,q分别表示(和)还剩的个数，有个隐含条件：就是(在组合时候比)用的多或相等
            if p > q:               #非法，剪枝
                return 
            if q == 0:              #)用完之时
                re.append(state)
            
            if p > 0:
                dsp(state+'(', p-1, q)
            if q > 0:
                dsp(state+')', p, q-1)

        dsp(state, n, n)
        return re
```