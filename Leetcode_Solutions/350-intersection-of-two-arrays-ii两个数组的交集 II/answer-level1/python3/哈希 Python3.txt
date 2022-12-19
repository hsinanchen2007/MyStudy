### 解题思路
![截屏2020-03-17下午5.40.19.png](https://pic.leetcode-cn.com/6f460ad8196d103d03377f18843b7d3fb566dde38b451874596876244c5989a6-%E6%88%AA%E5%B1%8F2020-03-17%E4%B8%8B%E5%8D%885.40.19.png)


### 代码

```python []
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if len(nums1) > len(nums2): 
            return self.intersect(nums2, nums1)
        hash = {}
        for num in nums1:
            if num not in hash:
                hash[num] = 1
            else: 
                hash[num] += 1

        res = []
        for num2 in nums2:
            if num2 in hash and hash[num2] > 0:
                res.append(num2)
                hash[num2] -= 1
        return res
```