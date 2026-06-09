### 解题思路

![image.png](https://pic.leetcode-cn.com/6cca10f0cacc37e87c274761040f045db7da43006cbeb4d3550df9d36762c702-image.png)

### 代码

```python
class Solution(object):
    def permutation(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        result = [S[0]]

        for i in range(1, len(S)):
            temp = []
            for value in result:
                for j in range(len(value) + 1):
                    temp.append(value[:j] + S[i] + value[j:])
            result = temp
        return result
```