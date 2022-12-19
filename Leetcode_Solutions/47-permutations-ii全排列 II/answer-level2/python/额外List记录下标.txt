### 解题思路
不重复全排列那道题基础上加个loc列表记录下标，下标不重复就往下走，之后在res里去重复

记得“ res.append(route.copy()) ”把route的**值**拷贝到res里，直接append个引用的话一会走别的路径的时候route指向的内容被搞乱了（最后回到[]） 

### 代码

```python3
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = []
        route = []
        loc = []
        def quanpai(route,nums):
            if len(route) == len(nums) and route not in res:
                res.append(route.copy())
            else:
                for key,i in enumerate(nums):
                    if key not in loc:
                        loc.append(key)
                        route.append(i)
                        quanpai(route,nums)
                        loc.pop()
                        route.pop()
        quanpai(route,nums)
        return res
```