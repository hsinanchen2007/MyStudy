### 解题思路
（1）.根据题目要求首先可以想到的是既然三个非空部分相等，那么每部分的和sumi就等于总和sumall的三分之一。
反过来想所以如果总和不能被3整除，则整个listA不可被划分

（2）.可以顺着整体listA中元素一个一个向后推，并记录构成的sumi的i的个数，如果sumi != 0,则i最大为3，如果恰好等于3，则说明可以构成，返回True。如果i小于3，则说明不能构成，返回False
（3）.特殊的情况为，如果 sumi == 0 ，（此时，∑sumi = 0）则各个sumi可随意组合，此时i可能大于3。由于  sumi可以随意组合，所以也可构成3个非空部分，所以返回True

### 代码

```python
class Solution(object):
    def canThreePartsEqualSum(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """

        #（1）
        if sum(A) % 3 != 0:
            return False
        
        sumi = sum(A)/3
        sumiCopy = sumi

        #（2）
        i = 0
        for x in A:
            sumi -= x
            if targsum == 0:
                i += 1
                sumi = sumiCopy

        if i == 3:
            return True
        #（3）
        elif i > 3 and sumiCopy == 0:
            return True
        else:
            return False



```