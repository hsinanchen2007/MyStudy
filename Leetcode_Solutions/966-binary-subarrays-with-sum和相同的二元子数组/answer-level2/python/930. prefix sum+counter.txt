### 解题思路
用counter比用字典快太多了，这是怎么回事？ comment掉的部分是拿字典写的，超出了时间限制，但拿counter写就很快。
思路如下：先算出array的prefix sum，注意要在开头补个0. 然后遍历prefix sum数组，当遍历到元素item时，我们只需要统计item-S出现了多少次即可，而item-S已经在前面的遍历中得到了。
### 代码

```python
class Solution(object):
    def numSubarraysWithSum(self, A, S):
        """
        :type A: List[int]
        :type S: int
        :rtype: int
        """
        sumArr = []
        sumArr.append(0)
        for num in A:
            sumArr.append(sumArr[-1]+num)
        ans = 0

        #multiDic = {}
        count = collections.Counter()

        for item in sumArr:
            '''
            if item-S in multiDic.keys():
                ans += multiDic[item-S]
            if item not in multiDic.keys():
                multiDic[item] = 1
            else:
                multiDic[item] += 1
            '''
            ans += count[item-S]
            count[item] += 1

        return ans
```