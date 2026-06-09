### 解题思路
第一种：创建列表。遍历nums，第一次碰到的值就加入列表。第二次碰到就从列表删除。最后留下的那一个就是单独存在的。
第二种：哈希表，遍历nums，第一次碰见的就当成key放进d中，第二次碰到就del。最后留下的那个pop出来的key就是答案。

### 代码

```python3
class Solution:
    # def singleNumber(self, nums: List[int]) -> int:
    #     n=len(nums)
    #     temp=[]
    #     k=0
    #     for i in nums:
    #         if i in temp:
    #             temp.remove(i)
    #         else:
    #             temp.append(i)
    #     return temp[0]
    def singleNumber(self, nums: List[int]) -> int:
        d = {}
        n = len(nums)
        for i in nums:
            if i in d:
                del d[i]
            else :
                d[i] = 1
        return d.popitem()[0]






```