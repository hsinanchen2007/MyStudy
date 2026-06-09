### 解题思路
方法1: 分成两段有序数组进行二分, 查找分割点也采用二分查找
方法2: 直接二分查找, 需要判断哪部分有序, 注意如果和某端点相等的话只能确保端点不是结果, 只能端点往里移动1, 因为和端点相等时不能确定左边或右边有序

### 代码

方法1:
```python
class Solution:
    def search(self, arr: List[int], target: int) -> int:
        split = -1
        s, e = 0, len(arr) - 1
        n = len(arr)
        while s <= e:
            m = (s + e) >> 1
            # 找到分隔点
            if m + 1 < n and arr[m] > arr[m + 1]:
                split = m
                break
            if m - 1 >= 0 and arr[m - 1] > arr[m]:
                split = m
                break
            if arr[m] < arr[e]:
                # 右边有序, 往左
                e = m - 1
            elif arr[m] > arr[e]:
                # 右边无序, 往右
                s = m + 1
            else:
                # m和e相等, 需要判断m和s的关系
                if arr[m] > arr[s]:
                    # 左边有序, 往右
                    s = m + 1
                elif arr[m] < arr[s]:
                    # 左边无序, 往左
                    e = m - 1
                else:
                    # 最复杂的情况, s/m/e都相等, 这时候无序点可能在左([3,1,3,3,3])也可能在右([3,3,3,1,3])
                    # 只能循环判断
                    i = m
                    while i > s and arr[i] == arr[m]:
                        i -= 1
                    if i == s:
                        # 左边都相等, 往右
                        s = m + 1
                    else:
                        # 左边无序, 往左
                        e = m - 1

        def bsearch(s, e):
            res = float('inf')
            while s <= e:
                m = (s + e) >> 1
                if arr[m] == target:
                    res = min(res, m)
                    e = m - 1
                elif arr[m] < target:
                    s = m + 1
                else:
                    e = m - 1
            return res

        if split == -1:
            res = bsearch(0, n - 1)
        else:
            res = min(bsearch(0, split), bsearch(split + 1, n - 1))
        return -1 if res == float('inf') else res
```

方法2:
```python
class Solution:
    def search(self, arr: List[int], target: int) -> int:
        s, e = 0, len(arr) - 1
        res = float('inf')
        while s <= e:
            m = (s + e) >> 1
            if arr[m] == target:
                res = min(res, m)
                e = m - 1
            else:
                if arr[s] < arr[m]:
                    # 左边有序, arr[s]<=arr[k]<=arr[m] (s<k<m)
                    if arr[m] < target:
                        # 只能向右, 因为arr[s]<arr[m]<target
                        s = m + 1
                    else:
                        # arr[m] > target
                        if arr[s] <= target:
                            # 只能向左, target不可能在右边, 因为右边最大值>=arr[m]>target, 末尾arr[e]<=arr[s]<=target, 由于求最小下标, 所以假设等于target的话一定在左边
                            e = m - 1
                        else:
                            # arr[s]>target, 整个左边都大于target, 只能向右
                            s = m + 1
                elif arr[s] > arr[m]:
                    # 右边有序, arr[m]<=arr[k]<=arr[e] (m<k<e)
                    if arr[m] > target:
                        # 只能向左, 因为整个右边都大于target
                        e = m - 1
                    else:
                        # arr[m] < target
                        if arr[e] < target:
                            # 只能向左, 因为整个右边都小于target
                            e = m - 1
                        elif arr[e] > target:
                            # 只能向右, target不可能在左边, 因为左边最小值<=arr[m]<target, 开头arr[s]>=arr[e]>target
                            s = m + 1
                        else:
                            # arr[e] == target
                            # 需要额外判断左侧开头是否也为target, 是的话目标在左边
                            if arr[s] == target:
                                res = min(res, s)
                                break
                            else:
                                # 如果不是target的话一定大于target(左侧无序)或者小于arr[m]<target(左侧有序), 向右查找
                                s = m + 1
                else:
                    s += 1
        return -1 if res == float('inf') else res
```