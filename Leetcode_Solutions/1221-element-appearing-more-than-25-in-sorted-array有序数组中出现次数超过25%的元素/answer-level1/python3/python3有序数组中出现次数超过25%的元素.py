### 解题思路
一次遍历

### 代码

```python3
class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        t=len(arr)//4+1
        pre = arr[0]
        cur=1
        for i in range(1,len(arr)):
            if arr[i]==pre:
                cur+=1
                if cur>=t:
                    return arr[i]
            else:
                pre=arr[i]
                cur=1
        return pre
```

![image.png](https://pic.leetcode-cn.com/e428c71dd81b0c27fbc2c2db5c1cbffd7db45690f0b202958e62547c1cf94a84-image.png)
