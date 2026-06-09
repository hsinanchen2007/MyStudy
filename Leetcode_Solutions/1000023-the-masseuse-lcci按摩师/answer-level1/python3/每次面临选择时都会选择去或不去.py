### 解题思路
每次面临选择时都会选择去或不去
这次选择去的话结果就是上次选择不去的情况加上这次去的奖励
这次选择不去的话结果就是上次选择去和选择不去的最大值
最后返回这次去和这次不去的最大值

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        go=not_go=0
        for i in nums:            
            go,not_go=not_go+i,max(go,not_go)
        return max(go,not_go)

```