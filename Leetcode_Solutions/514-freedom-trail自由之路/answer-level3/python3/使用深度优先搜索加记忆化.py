### 解题思路
使用回溯枚举所有可能的情况，因为可能有重复值，用一个数组记录每次旋转，选择每个值的总步数，输出数组最小值就是要求的结果。
第一次没有记忆化超时了，自己使用字典进行记忆化，结果不太对（只考虑了index做为标识），lru_cache真香。


### 代码

```python3
class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        from functools import lru_cache

        @lru_cache(None)
        def dfs(ring, key, index):
            if index >= len(key):
                return 0

            res = 0
            # 找到所有能旋转的位置
            l_index = ring.find(key[index])

            min_val = []
            while l_index != -1:
                # 如果当前位置在字符串左半边，使用逆时针旋转 + 1 是拼写操作
                if l_index <= len(ring) // 2:
                    min_val.append(l_index + 1)
                else:
                    # 否则使用顺时针旋转
                    min_val.append(len(ring) - l_index + 1)
                # 获得旋转后的新表盘
                new_ring = ring[l_index:] + ring[:l_index]

                # 寻找下一个旋转点
                min_val[-1] += dfs(new_ring, key, index + 1)
                l_index = ring.find(key[index], l_index + 1)

            res = res + min(min_val) if min_val else 0
            return res

        return dfs(ring, key, 0)
```