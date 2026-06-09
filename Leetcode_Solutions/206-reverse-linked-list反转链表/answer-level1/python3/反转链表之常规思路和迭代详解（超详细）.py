# 链表和数组
**尊重知识产权**
[图解数组和链表](https://www.cnblogs.com/jiqing9006/p/7615467.html)

链表的插入和删除只需改变指针即可，而数组需要挪位置，所以相对的复杂度会高`O(n)`。
但是链表的查找需要一个一个的找，而数组根据下标直接就找到了。
## 链表

### 反转链表

[反转链表](<https://leetcode-cn.com/problems/reverse-linked-list/submissions/>)

- 最直接的思路是：
  - [ ] 先转化为数组
  - [ ]  然后在生成链表

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # 得到原来的数据
        if head==None:
            return None      
        res_origin = []       
        first = head
        while first:
            res_origin.append(first.val)
            first = first.next
        #反转数组
        #res_rev = res_origin[::-1]
        #生成链表
        head = ListNode(res_origin.pop())
        laste = head
        
        while laste.next:
            laste = laste.next
        #这里极易出错！！！！当然现在就是错的。
        laste = ListNode(res_origin.pop())
        
        return head
```

但是这么写会报错！

![链表-0001.png](https://pic.leetcode-cn.com/b52edad3f60633a66932564f5e2ccce1ced541e72c4059ccd0471357b068dc63-%E9%93%BE%E8%A1%A8-0001.png)

为什么会这样呢？ 因为没有转起来啊。

```python
laste = head
while laste.next:
    laste = laste.next
laste = ListNode(res_origin.pop())
```

看这段代码，有初始节点吗？有啊！`laste = head`。转起来了吗？`while`看起来好像转起来了，但是并没有！为什么呢？
![链表-0002.png](https://pic.leetcode-cn.com/a6e147afe30cecd18cbf2a51cace872df5b9059aeb9e27b0ee8442115b6cea96-%E9%93%BE%E8%A1%A8-0002.png)


那这是哪里错了呢？怎么样才能转起来了呢？

```python
#将laste = ListNode(res_origin.pop()) 修改
laste.next = ListNode(res_origin.pop()) 
```
转起来了吗？
![链表-0003.png](https://pic.leetcode-cn.com/81158a0cc950285d4171c31378aa42193f673ed111832c922a48449f19dbd460-%E9%93%BE%E8%A1%A8-0003.png)

看！好像是转了一点，然后就停止了呀！
为什么呢？因为列表的`pop`操作并不是一个连续的过程，而是离散的。
所以我们需要修改为连续的过程！

```python
while res_origin!=[]:
            while laste.next:
                laste = laste.next
            laste.next = ListNode(res_origin.pop())  
```
通过了，也就是转起来了！
![链表-0004.png](https://pic.leetcode-cn.com/169ec7b430a305fe0df1733202e9291ed8e68aba2e9285d6640ba46fd2b8ad6b-%E9%93%BE%E8%A1%A8-0004.png)

在这里要注意！不可以是:`if res_origin!=[]:`。 `if`只是判断，不能循环的。
总体代码如下：

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # 得到原来的数据
        if head==None:
            return None
        
        res_origin = []
        
        first = head
        
        while first:
            res_origin.append(first.val)
            first = first.next
        #反转数组
        #res_rev = res_origin[::-1]
        #生成链表
        
        head = ListNode(res_origin.pop())
        laste = head
        
        while res_origin!=[]:
            while laste.next:
                laste = laste.next
            laste.next = ListNode(res_origin.pop())  
        
        return head
```

- 其实题目也提示我们了，是不是可以迭代或是递归的算法呢？

其实是可以的，为什么呢？因为反转是链表中的所有的节点都必须执行的操作，而终止信号是NULL。这是典型的迭代。

```python
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    # 返回ListNode
    def ReverseList(self, pHead):
        # write code here
        current_node, pre = pHead, None
        
#         while current_node:
#             current_node, pre = current_node.next, current_node

#         return pre_next
        while current_node:
        	#这里容易出错！！！
            laste = current_node.next
            laste.next=current_node
            #循环条件
            current_node = current_node.next
        return new_head
```
这么写是不对的，为什么呢？
![链表-0005.png](https://pic.leetcode-cn.com/6d9552270dc7aa1c2647ebd0f915ebc6c8dbde8ae2098d8ea872ff41ce9e7220-%E9%93%BE%E8%A1%A8-0005.png)


那该怎样呢？找一个中间桥梁啊！也就是我们设置一个前向指针。

```python
current_node, pre = head, None
```
然后去迭代：

```python
while current_node:
            current_node.next, pre, current_node  = pre, current_node, current_node.next

        return pre
```
是不是还是有点懵？没关系，咱画一个比较直观的图。
![链表-0006.png](https://pic.leetcode-cn.com/0d6b387513b15fbd80fbd5b4f56a72962e5c71d91ae3c4853bdd0bab1c18118e-%E9%93%BE%E8%A1%A8-0006.png)

那么大概就是这样一个过程。字有点丑，我知道，你不必告诉我啊。


那么能不能动态规划做呢？
当然可以啊！

```python
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        #动态规划
        if head==None:
            return head
        pre = head
        head = head.next
        if self.reverseList(head)==None:
            return pre
```
有去有回呀！
![链表-0009.png](https://pic.leetcode-cn.com/464e5725a9617f4fabcb7e1cfe0d0bff35f25ef6cbda65a0aeb260d461d4fe49-%E9%93%BE%E8%A1%A8-0009.png)
