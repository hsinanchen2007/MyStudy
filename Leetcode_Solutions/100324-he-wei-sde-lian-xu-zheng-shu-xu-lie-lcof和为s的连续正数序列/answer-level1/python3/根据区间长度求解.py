### 解题思路
- 找规律, 枚举长度le, 判断target能否由该长度的数组求和所得
    1. 如果le为奇数, 那么target%le应该为0才可以, 而target//le即为最中心的数字
    2. 如果le为偶数, 那么target/le应该为x.5, 也即(target+le//2)%le需要为0
- 然后根据中心数字和长度求得start, 从而得到解
- 注意start需要>0, 如果<=0则可以break, 因为后续的长度更长, 要想满足和为target的话start会更小
- 注意le从小到大, 即start从大到小, 最后需要翻转输出

### 代码

```python

class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        
        res = []
        for le in range(2, target // 2 + 1):
            if le & 1 != 0 and target % le == 0:
                start = target // le - le // 2
            elif le & 1 == 0 and (target + le // 2) % le == 0:
                start = (target + le // 2) // le - le // 2
            else:
                continue
            if start > 0:
                res.append(list(range(start, start + le)))
            else:
                break
        return res[::-1]
```