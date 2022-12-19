### 解题思路
![image.png](https://pic.leetcode-cn.com/07a637d1305b3a6ad55ee42c7fffdd02042a271d8eb0287d2bff9c7a74fe29eb-image.png)

暴力两层循环。
1. 先用一个数组index存储对应nums2位置的结果。
2. 再在nums2中找nums1对应数字的下标a，则该数字答案就是index[a]

### 代码

```python3
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        index = []
        for i in range(len(nums2)):
            flag = True
            for j in range(i, len(nums2)):
                # 找到了，就添加结果，并修改flag标志，退出循环
                if nums2[j]>nums2[i]:
                    flag = False
                    index.append(nums2[j])
                    break
            # 如果没找到，就添加-1
            if flag:
                index.append(-1)

        res = []
        # 在index数组中找答案
        for num in nums1:
            res.append(index[nums2.index(num)])
        return res

```