### 解题思路
利用python的生成器 ，生成正向的列表，然后切片反转列表

生成器可以节省空间

### 代码
![微信截图_20200327125108.png](https://pic.leetcode-cn.com/1a0f63b2e32c8d95b58fd03708e771f421397938f85982f5bbab00183ec1e38a-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200327125108.png)


```python3
class ListNode2iter:
    def __init__(self, head):
        self.head = head

    def __iter__(self):
        return self
    
    def __next__(self):
        head = self.head
        try:
            self.head = self.head.next
        except:
            raise StopIteration
        return head
        
class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        iterClass = ListNode2iter(head)
        myiter = iter(iterClass)
        return [i.val for i in myiter][::-1]
```