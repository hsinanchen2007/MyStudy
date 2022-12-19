### 解题思路
![image.png](https://pic.leetcode-cn.com/bf79ce7e0b80f2f4914ac4f70ae690b0e5dcface7e5c66471c19f4a06c476f3d-image.png)

滑动窗口求解。

右指针遍历短的列表（A）:
(1) 如果此时的局部列表（tmp_list）在另一个列表（B）中，计算局部列表（tmp_list）的长度；
(2) 否则，向右移动左指针（此处是伪左指针）；

### 代码

```python3
class Solution:
    def findLength(self, A: List[int], B: List[int]) -> int:
        m = len(A)
        n = len(B)

        if m>n:
            m, n, A, B = n, m, B, A

        tmp_list = []
        result = 0

        str_B = ',' + ','.join([str(i) for i in B]) + ','

        for r in A:
            tmp_list.append(str(r))

            if ',' + ','.join(tmp_list) + ',' in str_B:
                result = max(result, len(tmp_list))

            else:
                tmp_list = tmp_list[1:]

        return result
```