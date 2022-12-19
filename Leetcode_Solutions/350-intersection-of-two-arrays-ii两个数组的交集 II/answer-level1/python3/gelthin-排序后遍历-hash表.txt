### 解题思路

官方题解中复用了数组 nums1， 把最终结果存储在了 nums1 中

#### 1. 排序后简单遍历
check 对特殊样例， nums1 为 [], 代码仍然能够 work 即可。

倒是这一题的进阶问题值得好好思考。

类似之前 [392. 判断子序列](https://leetcode-cn.com/problems/is-subsequence/) 查找 s1 在 s2 中出现的字母子序列的进阶问题。

#### 2. Hash 表
``` python3
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if len(nums1) > len(nums2):
            return self.intersect(nums2, nums1)

        my_dict = dict()
        for x in nums1:
            if x in my_dict:
                my_dict[x] += 1
            else:
                my_dict[x] = 1

        # 把 result 存储在 nums1 上面
        k = 0
        for x in nums2:
            if x in my_dict and my_dict[x] > 0:
                nums1[k] = x
                k += 1
                my_dict[x] -= 1

        return nums1[:k]
```

### 进阶题目

1. 排序后直接遍历
2. 对小数组使用 hash 表 （set, dict）
3. 当前的方法都是内部排序（把整个数组装入到内存中），当要进行外部排序时，可以使用归并排序。


### 代码

```python3
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()
        i, j = 0, 0
        result = []
        while i<len(nums1) and j<len(nums2):
            if nums1[i] == nums2[j]:
                result.append(nums1[i])
                i += 1
                j += 1
            elif nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1

        return result
```