### 解题思路
感觉属于纯工程性的题目

### 代码

```python
class StackOfPlates(object):

    def __init__(self, cap):
        """
        :type cap: int
        """
        self.cap=cap
        self.allstacks=[]
        self.allstacks.append([])


    def push(self, val):
        """
        :type val: int
        :rtype: None
        """
        if self.cap<1:
            return
        if len(self.allstacks[-1])<self.cap:
            # print self.allstacks[-1]
            self.allstacks[-1].append(val)
            # print self.allstacks[-1]
        else:
            self.allstacks.append([val])
        # print self.allstacks


    def pop(self):
        """
        :rtype: int
        """
        if not self.allstacks[-1]:
            return -1
        res=self.allstacks[-1].pop()
        if  not self.allstacks[-1] and len(self.allstacks)>1:
            self.allstacks.pop()
        # print 'pop',res
        return res


    def popAt(self, index):
        """
        :type index: int
        :rtype: int
        """
        if index>len(self.allstacks)-1 or  not self.allstacks[index]:
            return -1
        else:
            res=self.allstacks[index].pop()
            if not self.allstacks[index] and len(self.allstacks)>1:
                self.allstacks.pop(index)
            # print res,'pop'
            return res



# Your StackOfPlates object will be instantiated and called as such:
# obj = StackOfPlates(cap)
# obj.push(val)
# param_2 = obj.pop()
# param_3 = obj.popAt(index)
```