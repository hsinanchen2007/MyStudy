### 解题思路
1. 对数组排序
2. 使用 Map 统计每个数字出现的次数，因为使用的 python3 在遍历时，输出 key 的顺序为添加时的顺序，所以直接使用即可，不用再经过数组转存。
3. 遍历时，得到当前数字出现的次数，则其后的 k 个记录（包含本身），都必须大于或等于当前的次数，使用循环进行检查，无法通过检查时直接返回 false，并在循环里修改 map 的值，经测试，在遍历时修改其值可以得到正确结果
4. 循环结束后，循环一遍值集合，如果都是 0 ，则可以返回 true

#### 坑，慎用循环

* 感觉这道题容易超时，在解这题期间，想出了两种使用循环解题的方法，并不是单纯的暴力解题，也做了各种优化，实现后都在第35个测试用例上 TLE 了

### 代码

```python3
class Solution:
    def isPossibleDivide(self, nums: list, k: int) -> bool:
        nums.sort()
        if len(nums) % k != 0:
            return False
        val_map = {}
        for num in nums:
            if val_map.get(num):
                val_map[num] += 1
            else:
                val_map[num] = 1
        for key, value in val_map.items():
            if value == 0:
                continue
            for now_k in range(key, key+k):
                if not val_map.get(now_k) or val_map[now_k] < value:
                    return False
                val_map[now_k] -= value
        for v in val_map.values():
            if v != 0:
                return False
        return True
```

### 测评结果

480ms（100%），27.2MB（100%），应该是提交的人不多