### 解题思路
1. 为满足第1个要求，假设每个孩子有1个糖果；
2. 从左向右遍历，当ratings[i]>ratings[i-1]，则使得第i个孩子糖果=第i-1个孩子糖果；这样可以保证右边孩子分高的话其糖果也比左边孩子的多；
3. 从右向左遍历，当ratings[i]>ratings[i+1]，令第i个孩子糖果=第i+1个孩子糖果；这样可以保证相邻左边孩子分高的话其糖果也比右边孩子的多；
4. 综合2，3两步，可以使得相邻孩子中，分高的孩子分到的糖果更多；

### 代码

```python3
class Solution:
    def candy(self, ratings: List[int]) -> int:
        # 输入参数为空集或只有1个元素时
        num = len(ratings)
        if num == 0:
            return 0
        if num == 1:
            return 1
        # res保存每个孩子可以分到的糖果
        res = [1]*num
        # 从左向右遍历，使得每个孩子至少1个糖果并且其相邻孩子中，若右边孩子评分高会获得更多的糖果；
        for i in range(1, num):
            if ratings[i] > ratings[i-1]:
                res[i] = res[i-1] + 1
        # 在上述基础下，再从右向左遍历，则最终会使得相邻孩子中，若左边孩子评分高会获得更多的糖果；
        for i in range(num-2, -1, -1):
            if ratings[i] > ratings[i+1]:
                res[i] = res[i+1]+1 if res[i+1]+1 > res[i] else res[i]
        
        # 因此通过两次遍历，可以使得每个孩子至少分配1个糖果并且相邻孩子中评分高的孩子会获得更多的糖果；
        return sum(res)
```