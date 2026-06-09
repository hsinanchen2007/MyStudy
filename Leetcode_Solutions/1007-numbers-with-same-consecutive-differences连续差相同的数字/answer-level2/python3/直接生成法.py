
-   从第一位开始生成
-   每次添加下一位有效位即可



```python
class Solution:
    def numsSameConsecDiff(self, N, K):
        """
        :type N: int
        :type K: int
        :rtype: List[int]
        """
        if N == 1:
            return list(range(10))
        temp_set = set()
        for i in range(1, 10):
            if 0 <= i - K <= 9 or 0 <= i + K <= 9:
                temp_set.add(str(i))

        for i in range(1, N):

            next_step = set()

            for cur in temp_set:
                num = int(cur[-1])
                if 0 <= num + K <= 9:
                    next_step.add(cur + str(num + K))
                if 0 <= num - K <= 9:
                    next_step.add(cur + str(num - K))
            temp_set = next_step
        return list(map(int, temp_set))
```


