### 解题思路
谁能告诉我第一个return为啥不行啊
![image.png](https://pic.leetcode-cn.com/ee89a7ce3dbc384631bddd3cdd60b869ec7b704ffd3ae30330a4ba9b066cbf19-image.png)

### 代码

```python3
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        # if m == 0: return nums2 ### 好气啊，不知道为什么，return命令失效
        
        num = m + n - 1
        m, n = m-1, n-1
        while m >= 0 and n >= 0:
            if nums1[m] > nums2[n]:
                nums1[num] = nums1[m]
                m -= 1
            else:
                nums1[num] = nums2[n]
                n -= 1
            num -= 1
        if n >= 0: 
            nums1[:n+1] = nums2[:n+1] # 一定要用n+1，否则n+1位会不替换
        return nums1
        
```