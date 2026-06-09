### 解题思路
我解决这个问题总共花费了大约5个小时。

第一次 尝试，以为只是简单的去除重复值而已。给出题解大概花费了10分钟。
提交的时候出现错误，发现题目是要求要去除所有的重复数字，就像[1,1,2]，结果要只保留[2]
![image.png](https://pic.leetcode-cn.com/2dd524213a922af05e1f843b0c86c3be9eceb3e0e9a0cc582be2f764b5fdc7e3-image.png)

第二次修改了代码，大概花费了30分钟。提交之后又发现了一个错误，原来我的思路是
发现重复的元素，指针就后移的做法，对于一开始就是重复的元素[1,1,,1,2,3]，肯定会保留一个至少一个[1]，因为指针挪到[2]元素的时候，发现currentP.val并不等于nextP.val 所以指针继续挪移，并没有移除[1]元素。
![image.png](https://pic.leetcode-cn.com/508149fb33102548e470da8be698530e8eb34b61e5d525fdf8bd86ee22fbfe6e-image.png)

第三次不断尝试解决这种一开始就重复的表比如[1,1,1,2]问题，大约花费了4个小时，仍然不能够很好的解决。后来参考了一些别人的思路，发现可以自己虚拟化一个head表头。问题一下子就明朗了，最开始的思路指针不断后移也是没有问题的，于是问题就解决了一半，最后的时候还遇见了一个问题，就是对于[1,1]的链表，实际输出的时候还是输出[1,1],在while循环的时候，nextP最后的指针的值为None，但是while循环外面应该设置，当前的指针指向nextP的指针。curentP.next = nextP 问题就解决了。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        #链表为空或者只有一个值，直接返回。
        if head == None or head.next == None:
            return head
        #为了避免，链表的一开始就是重复，设置一个虚假的表头，设置值为负无穷大。
        virtulHead = ListNode('-inf')
        virtulHead.next = head
        #当前指针，指向虚假的表头
        curentP = virtulHead
        #下一个指针，指向原来的表头
        nextP = virtulHead.next
        
        while nextP:
            #如果链表中当前元素和下一个元素相同
            if  nextP.next and nextP.next.val == nextP.val:
                #因为可能会重新多个重复元素并列存在的情况，设置了临时值
                tmp = nextP.val
                #只要元素仍然是临时值，下一个元素指针后移
                while nextP and tmp == nextP.val:
                    nextP = nextP.next
            #否则链表中则不是重复元素，则当前指针和下一指针都后移，并且重新拼接元素。
            else:
                curentP.next = nextP
                curentP = nextP
                nextP = nextP.next
        #如果真实链表中一直都是重复的元素，比如[1,1]的样式，最后nextP的值为None，此时应该让当前指针指向None
        curentP.next = nextP
        #返回真实表头
        return virtulHead.next
```