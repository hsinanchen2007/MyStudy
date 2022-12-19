### 解题思路
解题思路见代码中

### 代码

```python
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        dic = {}
        res = []
        for num in nums:
            #以nums列表中的元素作为键，元素出现的次数作为值
            dic[num]=dic.get(num,0) +1
        #把正数和负数存储在两个列表中
        pos = [i for i in dic if i>0]
        neg = [j for j in dic if j<0]
        #对neg进行从小到大的排序
        neg.sort()
        #大于等于3个0的情况
        if 0 in dic and dic[0]>=3:
            res.append([0,0,0])
        
        for i in pos:
            for j in neg:
                k=-(i+j)
                if k in dic:
                    if j<k<i:
                        res.append([j,k,i])
                    #如果有k与i或者j相同，那么确认的k可能就是i或者j本身，但是如果k的键大于等于2，那么成立
                    if (i==k or j==k) and dic[k]>=2:
                        res.append([j,k,i])
                    if k<j:#为什么只能写K<j,不能写k>i，因为对neg进行的从小到大的排序，如果对pos进行从大到小的排序，就可以写k>i
                        break
        return res
```