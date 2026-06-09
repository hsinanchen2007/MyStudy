```python []
class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        rightMax = -1
        for i in reversed(range(len(arr))):
            rightMax, arr[i] = max(rightMax, arr[i]), rightMax
        return arr
```
![image.png](https://pic.leetcode-cn.com/a06ad920376a096cced9650ceab83d3e2549805664c8c7f253ca5a8cc26a0f0e-image.png)
