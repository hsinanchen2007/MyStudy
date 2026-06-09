### 解题思路
先去掉目标字母位于所给数组两侧这一特殊情况，其次再用二分法求解。

### 代码

```python3
class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        right = len(letters)-1
        left=0
        if target>=letters[right] or target<letters[left]:
            return letters[0]
        while right-left>1:
            mid=(right+left)//2
            if letters[mid]>target:
                right=mid
            elif letters[mid]<=target:
                left=mid
        return letters[right]
```

![image.png](https://pic.leetcode-cn.com/35d2486c3fb429e6fe07f838839f492f3039060b1139b47d43dd9685ee2388a4-image.png)
