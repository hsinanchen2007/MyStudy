### 解题思路
* 解题思路还是 f[n] = f[n-1] + f[n-2]
* 使用字典存储数据。
* 每次计算完成后，在字典中删除key=i-2的数据，可以使字典hash值的查询速度加快。

### 代码

```python3
#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ylgongPw @ 2020-02-12 13:36:57
class Solution:
    def climbStairs(self, n: int) -> int:
        climb = {}
        climb[0] = 0
        climb[1] = 1
        climb[2] = 2

        for i in range(3,n+1):
            climb[i] = climb[i-1] + climb[i-2]
            climb.pop(i-2)

        return climb[n]

```