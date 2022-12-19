### 解题思路
执行用时 :1140 ms, 在所有 Python 提交中击败了5.88%的用户
内存消耗 :16.2 MB, 在所有 Python 提交中击败了100.00%的用户
此题最大的难点是读题
1.首先需要理解示例：
  第一个队列是操作名，第二个队列是元素，第三个队列是结果
2.还需要理解题意：
  题目要求实现这几个类函数，只要按照他规定的要求将其实现即可
  （python中也就考察queue的实现，很简单）
3.主函数并不需要你写：
  这点我看不出来，主要不知道在哪里写主函数，就试试看的执行了一下，竟然结果一样
  再试试看提交一下吧，竟然通过了

### 代码

```python
class MaxQueue(object):

    def __init__(self):
        self.items=[]

    def max_value(self):
        """
        :rtype: int
        """
        if self.items==[]:
            return -1
        else:
            return max(self.items)


    def push_back(self, value):
        """
        :type value: int
        :rtype: None
        """
        self.items.append(value)
        return None


    def pop_front(self):
        """
        :rtype: int
        """
        if self.items==[]:
            return -1
        else:
            return self.items.pop(0)



# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```