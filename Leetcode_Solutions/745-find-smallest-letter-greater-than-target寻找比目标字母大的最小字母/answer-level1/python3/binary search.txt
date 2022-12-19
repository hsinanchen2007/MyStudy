### 解题思路
注意区间划分边界

### 代码

```python3
class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        # O(n)+O(1) -> O(n)+O(26) -> O(lgn)+O(1)
        if len(letters) == 1:return letters[0]
        l,r=0,len(letters)
        while l<r:
            m = l + (r-l)//2
            if letters[m]<=target: 
                l=m+1 # 目标在 [m+1,]
            else:  
                r=m # 目标在 [,m]
        return letters[l%len(letters)] #最后一定相遇, ==n，没有一个大的
```