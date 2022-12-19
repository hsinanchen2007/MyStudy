### 解题思路
从头开始遍历，如果这组情侣不满足要求，则从后面找到满足要求的1个情侣交换过来。

### 代码

```python3
class Solution:
    def minSwapsCouples(self, row: List[int]) -> int:
        change_count = 0
        for i in range(0, len(row), 2):
            original_val = row[i]
            if original_val % 2 == 0:
                expect_val = original_val + 1
            else:
                expect_val = original_val - 1

            if row[i+1] != expect_val:
                right_loc = row.index(expect_val)
                row[right_loc] = row[i+1]
                row[i+1] = expect_val
                change_count += 1

        return change_count
```