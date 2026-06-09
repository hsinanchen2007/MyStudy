### 解题思路
避免使用bisect库进行二分查找，可以更容易理解二分的精髓。
使用的二分查找实质是查找到数组中从左到右的第一个大于等于目标值的索引，不存在大于等于目标值的索引，会查找到数组的最后一个索引。
判断查找的索引是偶数还是奇数，根据情况来判断。
具体判断逻辑代码中有注释，写的if else比较啰嗦，但是看起来容易理解。

### 代码

```python3
class SummaryRanges:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.data = []

    def addNum(self, val: int) -> None:
        if not self.data:
            self.data.append(val)
            self.data.append(val)
        else:
            idx = self.bsh(val)
            # 二分法查的是从左到右大于等于目标值的第一个索引
            # 需要注意，数组的一对，索引为 偶数奇数，偶数是左边界，奇数是右边界
            if idx % 2 == 1:
                if self.data[idx] < val:
                    # 只会发生在查到了数组的最后一个数字
                    if val - self.data[idx] > 1:
                        self.data.append(val)
                        self.data.append(val)
                    else:
                        self.data[idx] = val
                # 如果 self.data[idx] >= val
                # 因为索引是奇数，说明前一个索引的值肯定比目标值小，此时就在区间内，无需更新
            else:
                # 此时查在偶数数索引上
                if val < self.data[idx]:
                    # 可能情况为 [1, 1, 6, 7] 查 3
                    # 变为 [1, 1, 3, 3, 6, 7]
                    if self.data[idx] - val > 1:
                        self.data.insert(idx, val)
                        self.data.insert(idx, val)
                    else:
                        # 情况为 [1, 4, 6, 7] 查5
                        # 变为 [1, 4, 5, 7]
                        self.data[idx] = val
                # 在变为 [1, 4, 5, 7] 的情况下，需要和前一种合并
                if idx > 0 and self.data[idx] - self.data[idx-1] == 1:
                    self.data.pop(idx)
                    self.data.pop(idx-1)
        
    def getIntervals(self) -> List[List[int]]:
        return zip(self.data[::2], self.data[1::2])
    
    def bsh(self, target):
        l, r = 0, len(self.data) - 1
        while l < r:
            mid = (r+l) >> 1
            if self.data[mid] >= target:
                r = mid
            else:
                l = mid + 1
        return l
        


# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(val)
# param_2 = obj.getIntervals()
```