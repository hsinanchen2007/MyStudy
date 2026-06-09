### 解题思路
# 第x行的数据只需要从第x-1行得到，只要在前一行前后各加一个0再把对应位置相加即可
# 例如，假设前一行是[1,3,3,1]，只要把[0,1,3,3,1]和[1,3,3,1,0]对应的位置相加即可，即：
# [0+1,1+3,3+3,3+1,1+1] 得到 [1,4,6,4,1]
# 或者把前一行的相邻两项相加，即[1+3,3+3,3+1] 得到 [4,6,4]，再在前后加1即可
# 两种思路：递归或者迭代
### 代码

```python  递归  12ms,11.8MB
class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        if not rowIndex:
            return [1]
        pre = self.getRow(rowIndex-1)  # 得到前一行的数据
        ans = [1]
        for i in range(len(pre)-1):
            ans.append(pre[i]+pre[i+1])# 相邻两项相加
        ans.append(1)
        return ans



```python  迭代  20ms,11.7MB
class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        if not rowIndex:
            return [1]
        pre = [1,1]
        while len(pre) <= rowIndex:  # 循环体内把前一行前后各加一项0
            line1 = pre + [0]
            line2 = [0] + pre
            cur = [line1[i]+line2[i] for i in range(len(line1))]
            pre = cur[:]
        return pre