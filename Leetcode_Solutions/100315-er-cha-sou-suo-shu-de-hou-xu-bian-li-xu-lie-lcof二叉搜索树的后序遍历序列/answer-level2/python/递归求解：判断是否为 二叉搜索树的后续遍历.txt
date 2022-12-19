### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:
        if len(postorder) <= 1:
            return True
        root_val = postorder.pop()
        mid = 0
        while mid < len(postorder):
            if postorder[mid] <= root_val:
                mid = mid + 1
            else:
                break
        mid_ind = mid
        while mid < len(postorder):
            if postorder[mid] < root_val:
                return False
            mid += 1
        return self.verifyPostorder(postorder[:mid_ind]) and \
            self.verifyPostorder(postorder[mid_ind:])

        

        
```