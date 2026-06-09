### 解题思路
思路就是照着leetcode标准解法

### 代码
为了能本地运行。我自己写了一个`linkedlist.py` 这样非常方便测试
```python3
from linkedlist import *


def addTwoNumbers(l1: ListNode, l2: ListNode) -> ListNode:
    ans = []
    toNext = 0
    while l1 is not None or l2 is not None:
        # 如果非空则赋值
        x = y = 0
        if l1 is not None:
            x = l1.val
        if l2 is not None:
            y = l2.val

        thisNumber = x + y + toNext # 这一轮的和
        toNext = thisNumber // 10  # 括号内部是上一轮的 进位 （tonext）
        ans.append(thisNumber % 10)  # 把个位数留下

        # 如果可以则继续读取
        if l1 is not None:
            l1 = l1.next
        if l2 is not None:
            l2 = l2.next

    if toNext > 0:
        ans.append(toNext)
    return ToLinkedList(ans)


if __name__ == '__main__':
    ll1 = ToLinkedList([1, 8])
    ll2 = ToLinkedList([0])
    print("answer is : ")
    prettyPrintLinkedList(
        addTwoNumbers(ll1, ll2)
    )

```
附  `linkedlist.py`
```python3
# Definition for singly-linked list.

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def ToLinkedList(input):
    # Generate list from the input
    # numbers = stringToIntegerList(input)
    numbers = input
    # Now convert that list into linked list
    dummyRoot = ListNode(0)
    ptr = dummyRoot
    for number in numbers:
        ptr.next = ListNode(number)
        ptr = ptr.next

    ptr = dummyRoot.next
    return ptr

def prettyPrintLinkedList(node):
    while node and node.next:
        print(str(node.val) + "->", end='')
        node = node.next

    if node:
        print(node.val)
    else:
        print("Empty LinkedList")

def main():
    x= [1,2,3,4,5]
    prettyPrintLinkedList(ToLinkedList(x))

if __name__ == '__main__':
    main()
```