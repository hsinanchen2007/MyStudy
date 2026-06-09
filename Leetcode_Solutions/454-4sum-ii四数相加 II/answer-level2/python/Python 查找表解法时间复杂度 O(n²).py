### 解题思路
选择两个数组如 A， B 。计算 A， B 所有元素两两相加的和存入字典查找表（sumNum）， 并将结果与 C， D 的两两求和进行比较。其中 sumNum 的 k 为A， B元素两两求和和的数值， v 为两元素相加和为 k 的数量
此题的关键就是要找到查找表中存放的 k， v 合适的含义。

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
        # 遍历A， B 计算A， B 所有元素两两相加的和， 并将计算结果存入 dict sumNum 中， sumNum 的 k 为和的数值， v 为两元素相加和为 k 的数量
        sumNum = dict()
        res = 0
        for a in A: # 时间复杂度 O(n²)
            for b in B:
                s = a + b
                if s not in sumNum:
                    sumNum[s] = 1
                else:
                    sumNum[s] += 1
        
        # 计算 C， D 的和为 k , 并检查 sumNum 中是否存在 -k， 存在则累计 sumNum[-k]
        for c in C:
            for d in D:
                k = c + d
                if -k in sumNum:  # -k 存在则 -k + k 即为 0
                    res += sumNum[-k]
        return res
```