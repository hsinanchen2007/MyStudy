### 解题思路

解题思路很简单，判断 a+b = -c 是否成立就可以，成立了，并且不重复就加入到结果集当中。但是重点要解决重复问题。下面是我的方法，绝对巧妙。

如代码，我把结果集res设置为一个字典，key为某一个解的三个数字的字符串组合，比如解[1,2,3] ，对应字典里面一项就是 a['123'] = [1,2,3] value是一个列表，我们的最终结果。这样，当判断当前解是否重复时，只需要判断 三个数字的字符串组合是否在字典之中就可以，O(1)复杂度，注意拼接之前先排序一下。

### 代码

```python3
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        if n < 3:
            return []
        for i in range(n):
            if nums[i] != 0:
                break
            if i == n-1:
                return [[0,0,0]]
        hax = {}
        for i in range(n):
            hax[nums[i]] = i
        res = {}
        for c in range(n):
            for b in range(c+1,n):
                target = (-1)*(nums[c]) - nums[b]
                if target in hax:
                    if hax[target] != b and hax[target] != c:
                        temp = [nums[c],nums[b],target]
                        temp.sort()
                        result = ''
                        for i in temp:
                            result += str(i) 
                        if result not in res:
                            res[result] = temp
        return list(res.values())


```