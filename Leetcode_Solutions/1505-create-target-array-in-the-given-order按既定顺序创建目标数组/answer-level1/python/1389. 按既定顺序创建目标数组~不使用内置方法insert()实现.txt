### 解题思路
我们每次去判断index[i]中的元素值和target长度，去判断是直接在尾部增加（不需要移动元素），还是在中间插入（需要移动元素）
当然直接使用list.insert(position, value)也能很快得出答案
### 代码

```python3
class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        target = []
        for i in range(len(nums)):
            idx = index[i]
            if target == []:
                target.append(nums[i])
            else:
                print(idx, len(target), target)
                if idx >= len(target):
                    target.append(nums[i])
                elif idx < len(target):
                    target = target[:idx] + [nums[i]] + target[idx:]
                    print("sdad", target)

        return target
```