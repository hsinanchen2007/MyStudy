### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        result = []
        for i in range(len(nums1)):
            flag = 0
            for j in range(nums2.index(nums1[i]), len(nums2)):
                if nums2[j] > nums1[i]:
                    result.append(nums2[j])
                    flag = 1 
                    break
            if flag == 0:
                result.append(-1)
        return result

            
            
```