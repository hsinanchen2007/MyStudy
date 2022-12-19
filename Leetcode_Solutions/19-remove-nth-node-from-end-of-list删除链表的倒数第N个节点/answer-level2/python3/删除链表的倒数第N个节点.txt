好奇怪啊， 我用的双指针，一次遍历实现了算法，结果用的时间却比两次遍历的要长的多。哪位大佬帮我解释下啊！！！

![图片.png](https://pic.leetcode-cn.com/df1686dce69b4a8a155d1d98ca97670df46e951f16a3b15e91d502f31924748a-%E5%9B%BE%E7%89%87.png)

上面的是一位大佬的，两次遍历，时间为26ms，下面的是我的
```
def removeNthFromEnd(head: ListNode, n: int) -> ListNode:
    if n == 0: return head
    p1 = p2 = head      #p1指向所要删除的前一个对象
    while n > 1 and p2:
        p2 = p2.next
        n -= 1
    #1.p1为头节点
    if p2.next == None:
        return head.next
    p2 = p2.next
    while p2.next != None:
        p1 = p1.next
        p2 = p2.next
    p1.next = p1.next.next
    return head
```
这个耗时56ms
