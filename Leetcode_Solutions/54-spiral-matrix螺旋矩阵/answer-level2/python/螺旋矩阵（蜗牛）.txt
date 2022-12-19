### 解题思路
1. 设置四个变量，标识上下左右四个方向
2. 从左往右，上减一
3. 从上到下，右减一
4. 从右到左，下减一
5. 从下到上，左减一
6. 重复2-5步骤，直至无法移动

### 代码

```python3
class Solution:
    def spiralOrder(self, snail_map: List[List[int]]) -> List[int]:
        if not snail_map or not snail_map[0]:
            return []
        n = 0  # 上
        s = len(snail_map)  # 下
        w = 0  # 左
        e = len(snail_map[0])  # 右
        r_l = []
        while True:
            if w < e:
                i = n
                while i < e:
                    r_l.append(snail_map[n][i])
                    i += 1
                n += 1
            else:
                break
            if n < s:
                j = n
                while j < s:
                    r_l.append(snail_map[j][e - 1])
                    j += 1
                e -= 1
            else:
                break
            if w < e:
                k = e - 1
                while k >= w:
                    r_l.append(snail_map[s - 1][k])
                    k -= 1
                s -= 1
            else:
                break
            if n < s:
                l = s - 1
                while l >= n:
                    r_l.append(snail_map[l][w])
                    l -= 1
                w+=1
            else:
                break
        return r_l
```