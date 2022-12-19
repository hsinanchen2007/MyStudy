### 解题思路
此处撰写解题思路
核心思想：设置双指针，一快一慢，利用等差数列公式，判断大于、小于两种情况，分别调整快、慢指针
如果等于的话，另写for循环先输出满足条件的一个数组，再输出全部数组。
易错点：输出满足条件的一个数组之后，快慢指针分别+1继续搜索下一个指针
### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        l = 1
        r = 2
        res = []

        while(l<r):
            a = []
            sum =(l+r)*(r-l+1)/2
            if sum < target:
                r += 1
            elif sum > target:
                l += 1
            else:
                for i in range (l,r+1):
                    a.append(i)
                res.append(a)
                l += 1
                r += 1
        return res
```