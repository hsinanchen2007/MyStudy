### 解题思路
此处撰写解题思路
利用数据结构中的双端队列实现回问检查
![截屏2020-04-0421.44.51.png](https://pic.leetcode-cn.com/8b6b8067a94b2c4e7cd2a783573a8edc24b0558087b1d64aef5e5b2587f7f2ee-%E6%88%AA%E5%B1%8F2020-04-0421.44.51.png)


### 代码

```python3
class Deque:
    def __init__(self):
        self.items = []
    
    def isEmpty(self):
        return self.items == []
    
    def addFront(self, item):
        self.items.append(item)
    
    def addRear(self, item):
        self.items.insert(0, item)
    
    def removeFront(self):
        return self.items.pop(0)
    
    def removeRear(self):
        return self.items.pop()
    
    def size(self):
        return len(self.items)


class Solution:
    def isPalindrome(self, x: int) -> bool:
        d = Deque()
        for i in str(x):
            d.addRear(i)
        
        isEqual = True
        while d.size() > 1 and isEqual:
            if d.removeFront() == d.removeRear():
                pass
            else:
                isEqual = False
                return False
        return True

```