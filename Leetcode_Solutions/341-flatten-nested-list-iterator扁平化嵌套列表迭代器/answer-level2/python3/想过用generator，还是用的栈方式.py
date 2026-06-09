时间上超80% 空间上也还可以60%
```
class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        self.stack=[]
        self.traverse(nestedList)
    def traverse(self,nested_list):
        while nested_list:
            x=nested_list.pop() if isinstance(nested_list,list) else nested_list.getList()
            if x.isInteger():
                self.stack.append(x.getInteger())    
            else:
                self.traverse(x.getList())      
    
    def next(self) -> int:
        return self.stack.pop()
    
    def hasNext(self) -> bool:
        return len(self.stack)!=0
```
