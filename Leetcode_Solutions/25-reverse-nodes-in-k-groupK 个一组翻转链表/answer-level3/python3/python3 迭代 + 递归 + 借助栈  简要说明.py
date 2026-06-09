## 切题
一、Clarification

1、每组k个元素翻转后，每组之间的衔接。[1,k] 与 [k+1,2k]之间衔接

2、注意 剩余元素的处理

二、Possible Solution

1、迭代

遍历链表 找出每组的 首尾以及下一组的首，借助单链表翻转获得翻转后的首尾，对首尾节点衔接处理，对哨兵节点移位处理

时间复杂度 O(N)

2、递归

递归终止条件：

剩余节点 < k

递归从里向外出来，每层递归返回当前层级链表翻转后的头节点，那么每层递归中我们知道当前层级翻转后的头尾节点以及下一个k元素组的头节点（递归的上一层级），可以很轻松地将翻转后的链表衔接起来


3、借助栈

将k个元素压入栈，通过出栈翻转，注意剩余元素处理


### 迭代 借助单链表翻转 
```python
# @author:leacoder
# @des: 迭代 借助单链表翻转  k个一组翻转链表
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        cur = head #由于遍历
        dim = ListNode(0) #新建一节点 
        dim.next = head #next指向head
        pre = dim #pre 赋值为 dim  1、记录和获取 k个一组的头 2、方便统一处理
        count = 1
        while cur: #遍历链表
            if count % k == 0: #k个一组 对这里面的数据翻转
                nextstart = cur.next #记录 后一个 k个一组的 头节点
                cur.next = None #赋值为None 前面 k个一组数据 为新的链表 以 None结束 这个新链表可以采用206的处理方式
                end, start = self.reverse(pre.next)  #翻转新链表 返回翻转的  尾 和 头  注pre.next 为新链表翻转前的头
                # 衔接处理，哨兵的next指向翻转后的头， 翻转后的尾的next指向nextstart
                # pre 和 cur 依次下移k个元素 变为 end 和 nextstart下一轮处理就变成本轮一样了
                pre.next,end.next,pre,cur = start,nextstart,end,nextstart
            else:
                cur = cur.next #我们关心k个一组的首尾
            count += 1
        return dim.next
    
    def reverse(self, head): #翻转链表
        dim1,cur,pre = head,head,None
        while cur: #遍历
            cur.next,pre,cur  = pre,cur,cur.next
        return dim1,pre    #翻转后end 和 start
```
### 递归

```python
# @author:leacoder
# @des: 递归  k个一组翻转链表
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
       
        if self.isEnd(head,k):
            return head
        pre = ListNode(None) # 哨兵
        pre.next,cur,count =  head,head,1  

        while count <= k: # 翻转 k个元素链表  处理类似 206
            cur.next,pre,cur,count  = pre,cur,cur.next,count + 1 
        # 循环结束后 cur 指向 下一组 k个元素(未翻转)的头 ;pre指向当前组在翻转后的头节点
        nexthead = self.reverseKGroup(cur,k) # nexthead 下一组翻转后的头节点

        head.next = nexthead #当前组的head在翻转后成为尾节点，其next指向nexthead 下一组翻转后的头节点
        return pre  # 返回 翻转后的头节点

    # 递归终止判断：
    def isEnd(self,head,k):
        count,cur = 0,head
        while cur:
            count = count + 1
            cur = cur.next
            if count >= k:
                return False # 
        return True
```

###   借助栈

***求教在用例 [1,2,3,4,5] 2 没有问题，但是 在用例[1,2] 2 或者 [1,2,3] 3 (元素为 k的整数倍时) 却会出现 超出时间限制，这是为什么呢？***

```python

# @author:leacoder
# @des: 借助栈  k个一组翻转链表
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        result= ListNode(None)
        cur,result.next = head,head
        tmpresult = result
        stack = [] # 列表实现栈的 先入后出功能
        count = 0

        while cur:
            count = count + 1
            stack.append(cur) # 入栈
            cur = cur.next
            if count % k == 0: # 已存储k个元素
                count = 0
                while stack: # 出栈倒换
                    tmpresult.next = stack.pop()
                    tmpresult = tmpresult.next

        # 处理 stack 中剩余元素
        while stack:
            tmpresult.next = stack.pop(0) # 
            tmpresult = tmpresult.next 
        return result.next
```