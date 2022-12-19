使用两个哈希表：

- 哈希表 `counter` 用于存储元素出现的次数，`counter[n]` 代表 n 出现的次数
- 哈希表 `end` 用于存储以元素结尾的连续子序列（指至少包含三个连续整数的子序列）个数，`end[n]` 代表以 n 结尾的连续子序列的个数

**过程如下**：

遍历数组 `nums`：

- 若元素 `n` 的出现次数 `count[n] == 0`：跳过该元素
- 若元素 `n` 的出现次数 `count[n] > 0`：
  - 存在以元素 `n - 1` 结尾的连续子序列，即 `end[n - 1] > 0`，将元素添加到该子序列的末尾，操作数据：
      1. 以 `n - 1` 结尾的子序列数量减 1：`end[n - 1] -= 1`
      2. 以 `n` 结尾的子序列数量加 1：`end[n] += 1`
  - 不存在以元素 `n - 1` 结尾的连续子序列，此时判断是否能以 `n` 作为开头构建连续子序列，即判断 `counter[n + 1]` 与 `counter[n + 2]` 的值是否均大于 0：
    - 若不能构成：返回 `False`
    - 若可以构成，操作数据：
      1. `n + 1` 元素数量减 1：`counter[n + 1] -= 1`
      2. `n + 2` 元素数量减 1：`counter[n + 2] -= 1`
      3. 以 `n + 2` 元素结尾的子序列数量加 1：`end[n + 2] += 1`

```python
class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        # 记录元素出现次数
        counter = dict()
        for n in nums:
            counter[n] = counter.get(n, 0) + 1
            
        end = dict()
        for n in nums:
            if counter[n] == 0:
                continue
                
            counter[n] -= 1
            if end.get(n - 1, 0) > 0:
                # 添加到已有子序列的末尾
                end[n - 1] -= 1
                end[n] = end.get(n, 0) + 1
            elif counter.get(n + 1, 0) > 0 and counter.get(n + 2, 0) > 0:
                # 添加到子序列头部
                counter[n + 1] -= 1
                counter[n + 2] -= 1
                end[n + 2] = end.get(n + 2, 0) + 1
            else:
                return False
        return True
```