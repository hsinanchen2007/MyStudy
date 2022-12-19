1、以A列表为基准，依次遍历和B列表对比；
2、如果A的最大值小于B的最小值，则直接进行A的下一个循环；
3、else，比较A和B的index=0，取max得到left；比较A和B的index=1，取min得到right；如果right>=left，则写入结果中；
4、返回结果。
以下是代码：
```python
def intervalIntersection(self, A, B):
        """
        :type A: List[List[int]]
        :type B: List[List[int]]
        :rtype: List[List[int]]
        """
        result = []
        for i in range(len(A)):
            for j in range(len(B)):
                if A[i][1] < B[j][0]:
                    break
                left = max(A[i][0], B[j][0])
                right = min(A[i][1], B[j][1])
                if right >= left:
                    result.append([left, right])
        return result