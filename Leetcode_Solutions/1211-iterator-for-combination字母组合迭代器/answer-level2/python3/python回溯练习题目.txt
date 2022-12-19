### 解题思路
此处撰写解题思路
特别简单的回溯，就是从b开始了，就不考虑b以前的元素进行组合。

### 代码

```python3
class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        # self.com = itertools.permutations(characters,combinationLength)
        # self.stack = []
        self.com = collections.deque()
        def helper(characters,res=''):
            if len(res)==combinationLength:
                self.com.append(res)
            
            for i in range(len(characters)):
                helper(characters[i+1:],res+characters[i])
            
        helper(characters)

        
    def next(self) -> str:
        # if not self.stack:
        #     return "".join(next(self.com))
        # else:
        #     return self.stack.pop(0)
        return self.com.popleft()
        
    def hasNext(self) -> bool:
        return len(self.com)!=0

        # try:
        #     b = "".join(next(self.com))
        #     self.stack.append(b)
        #     return True
        #     print(self.stack)
        # except:
        #     return False

        


        


# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()
```