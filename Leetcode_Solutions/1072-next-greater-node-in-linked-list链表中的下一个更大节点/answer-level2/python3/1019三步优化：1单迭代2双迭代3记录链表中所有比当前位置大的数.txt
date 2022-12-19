### 方法1单迭代 
1、如果不存在下一个数，返回0
2、其他情况先返回前一个数的结果队列
3、第一个值和上一个值比较，依据结果在前一个数的结果队列前插入值。
4、如果第一个值比前一个值大，就需要在队列中找更大的值，找不到的话就插入0。依据是，如果存在比前一个数还大的数存在在链表中的话，一定也存在在结果队列中。
（该实现效率很慢，供参考）
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:202003071650
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def nextLargerNodes(self, head: ListNode) -> List[int]:
        if not head.next:return [0]
#1、如果不存在下一个数，返回0
        else:
#2、其他情况先返回前一个数的结果队列
            rst=self.nextLargerNodes(head.next)
#3、第一个值和上一个值比较，依据结果在前一个数的结果队列前插入值。
            if head.val < head.next.val :rst.insert(0,head.next.val)
            elif head.val == head.next.val :rst.insert(0,rst[0]) 
            else:
#4、如果第一个值比前一个值大，就需要在队列中找更大的值，找不到的话就插入0
                if max(rst)>head.val:
                    for i in rst:
                        if i>head.val:
                            rst.insert(0,i)
                            break
                else:rst.insert(0,0)
        return rst
```
### 方法2双迭代
1、如果不存在下一个数，返回0
2、其他情况先返回前一个数的结果队列
3、第一个值和上一个值比较，依据结果在前一个数的结果队列前插入值。
4、如果第一个值比前一个值大，前一个值的结果队列的第一个值记录了比前值大的节点，依据head.next.val=rst[0]找到这个节点。
5、将当前节点和head.next.val=rst[0]组成一个新的链表，返回结果队列，取结果队列的第一个插入rst的头部。
（该实现效率很慢，供参考）

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:202003071650
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def nextLargerNodes(self, head: ListNode) -> List[int]:
        if not head.next:return [0]
#1、如果不存在下一个数，返回0
        else:
#2、其他情况先返回前一个数的结果队列
            rst=self.nextLargerNodes(head.next)
#3、第一个值和上一个值比较，依据结果在前一个数的结果队列前插入值。
            if head.val < head.next.val :rst.insert(0,head.next.val)
            elif head.val == head.next.val :rst.insert(0,rst[0]) 
            else:
#4、如果第一个值比前一个值大，前一个值的结果队列的第一个值记录了比前值大的节点，依据head.next.val=rst[0]找到这个节点。
                while head.next.val!=rst[0]:
                    if not head.next.next:
                        head=head.next
                        break
                    else:head.next=head.next.next
#5、将当前节点和head.next.val=rst[0]组成一个新的链表，返回结果队列，取结果队列的第一个插入rst的头部。
                rst.insert(0,self.nextLargerNodes(head)[0])
        return rst
```
### 方法3记录链表中所有比当前位置大的数
别人的解，不在赘述。参见： 
[python 单调栈 附上单调栈的其他题目](https://leetcode-cn.com/problems/next-greater-node-in-linked-list/solution/python-dan-diao-zhan-by-jackwener/)