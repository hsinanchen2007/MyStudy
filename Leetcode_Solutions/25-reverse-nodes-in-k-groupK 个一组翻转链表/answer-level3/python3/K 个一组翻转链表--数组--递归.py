我们来看这一题
[25：K 个一组翻转链表](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/)
具体的题是什么，请您自己打开链接看即可。这里主要关注的是逻辑和思维。
`给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。`

最直接的思路是什么呢？数组。

- 把所有节点的值都记录到数组中
- 切分数组，反转
- 然后，再创建链表即可

```python
class Solution(object):  
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head == None:
            return head
        if k==1:
            return head
        res = []
        s =head
        while head:
            res.append(head.val)
            head = head.next
        lens = len(res)
        if lens<k:
            return s
        #print(res)
        a=[]
        surplus = lens%k
        #print(surplus)
        for i in range(0,lens-surplus,k):
            a.append(res[i:i+k][::-1])
        c =[]
        if len(a)>1:
            for j in range(len(a)):
                c = c+a[j]
        else:
            c = a[0]
        res = c +res[len(res)-surplus:]
        #print(res)
        head = ListNode(res[0])
        laste = head
        j = 1
        while head and j<lens:
  
            head.next=ListNode(res[j])
            j+=1
            head = head.next
        return laste
            
```
虽然我将代码放出来了，但是这样的方法可能不能满足面试的基本要求。因为思路是很清晰的，主要考察的是代码的能力。

----------
那么怎么做呢？

我们是不是可以递归处理呢？
- 通过设置cur，把原先的链表切成几段，每一段在一个递归体里面进行处理

```python
class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        cur = head
        count = 0
        while cur and count != k:
            cur = cur.next
            count += 1
        #通过设置cur，把原先的链表切成几段，每一段在一个递归体里面进行处理。
        if count == k:
            cur = self.reverseKGroup(cur,k)
            while count:
                tmp = head.next
                head.next = cur
                cur = head
                head = tmp
                count -= 1
            head = cur
        return head

```
我们一步一步的讲。

```python
count = 0
        while cur and count != k:
            cur = cur.next
            count += 1
```
这是告诉我们怎么找切分点。

```python
if count == k:
	cur = self.reverseKGroup(cur,k)
```
这是告诉我们切分之后下一个的起始点。

```python
while count:
     tmp = head.next
     head.next = cur
     cur = head
     #print(head.val)
     head = tmp
     count -= 1
#以上是告诉我们怎么着反转。
```
确实有点绕。多做几遍吧。
