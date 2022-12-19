### 解题思路
- 模拟人类分糖果过程
- 分摊过之前检查手里的糖果，如果没分完就分
- 分完配置下一次的坐标和糖果数
- 最后有不符合的多余的给下一个人就好

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        l = [0]*num_people
        index = 0
        distributed = 0
        n = 1
        while  (distributed+n) <= candies:
            l[index] = l[index]+ n
            distributed = distributed + n
            
            if (index+1)%num_people==0:
                index = 0
            else:
                index = index + 1
            n = n+1

        l[index] = l[index] + (candies-distributed)
        return l
```