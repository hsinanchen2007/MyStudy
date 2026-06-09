![01a88fedee394c2a9cb08c34fc73fc1.png](https://pic.leetcode-cn.com/e000aac7590142dd8f6bc9caa3a3f3e70975a65618bca70206ef4ba2cfa67022-01a88fedee394c2a9cb08c34fc73fc1.png)

```python []

class Solution:
    def convertToTitle(self, n: int) -> str:
        excel_num = ''
        while n:
            temp = (n-1) % 26
            excel_num = chr(temp + 65) + excel_num
            n -= temp
            n //= 26
        return excel_num

```