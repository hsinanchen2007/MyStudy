### 解题思路
堆栈的 使用

### 代码

```python3
class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        class Stack(object):
            def __init__(self, limit=10):
                self.stack = [] #存放元素
                self.limit = limit #栈容量极限
            def push(self, data): #判断栈是否溢出
                if len(self.stack) >= self.limit:
                    print('StackOverflowError')
                    pass
                self.stack.append(data)
            def pop(self):
                if self.stack:
                    return self.stack.pop()
                else:
                    raise IndexError('pop from an empty stack') #空栈不能被弹出
            def peek(self): #查看堆栈的最上面的元素
                if self.stack:
                    return self.stack[-1]
            def is_empty(self): #判断栈是否为空
                return not bool(self.stack)
            def size(self): #返回栈的大小
                return len(self.stack)
            
        pos_stk=Stack(10000)
        ans=[]
        #print(List.items())
        #print(type(List),List[0])
        for data in asteroids:
            if data>0:
                pos_stk.push(data)
            else:
                if pos_stk.size() ==0:
                    ans.append(data)
                else:
                    while(pos_stk.size()):
                        pos=pos_stk.pop()
                        if pos> abs(data):
                            pos_stk.push(pos)
                            break
                        elif pos==abs(data):
                            break

                    if pos_stk.size()==0 and pos != abs(data):
                        ans.append(data)
        return (ans+pos_stk.stack)
            
        
```