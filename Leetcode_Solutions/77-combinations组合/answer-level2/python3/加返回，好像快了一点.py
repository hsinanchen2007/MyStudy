### 解题思路
此处撰写解题思路

### 代码

```python
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        def backtrack(first = 1, curr = []):
            # if the combination is done
            if len(curr) == k:  
                output.append(curr[:])
                return 
            for i in range(first, n + 1):
                # add i into the current combination
                curr.append(i)
                # use next integers to complete the combination
                backtrack(i + 1, curr)
                # backtrack
                curr.pop()
        
        output = []
        backtrack()
        return output
```

### 什么时候可以省略冒号啊，前面就不可以

```python
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        def backtrack(first = 1, curr = []):
            # if the combination is done
            if len(curr) == k:  
                output.append(curr)#note here
                return 
            for i in range(first, n + 1):
                # add i into the current combination
                #curr.append(i)
                # use next integers to complete the combination
                backtrack(i + 1, curr+[i])
                # backtrack
                #curr.pop()
        
        output = []
        backtrack()
        return output
```