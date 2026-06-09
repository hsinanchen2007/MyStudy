### 解题思路
此题数组位置固定且为乱序, 故不能使用双指针. 用数组题经典的哈希解法, 四个数分为两组双循环时间复杂度最低, 第一组存哈希表, 第二组找哈希表.

### 代码

```python
class Solution(object):
    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        count = 0
        dic = {}
        for a in A:
            for b in B:
                if a+b in dic:
                    //同一结果但不同组合
                    dic[a+b] += 1
                else:
                    dic[a+b] = 1
        for c in C:
            for d in D:
                if -c-d in dic:
                    count+= dic[-c-d]
        return count
```