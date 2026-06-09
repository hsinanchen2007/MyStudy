我用的是一种非常容易实现的方法，当时这就牺牲了很多时间和空间。
将节点逐个添加到列表中，然后交换列表中相邻两节点，最后将其串起来。
还有就是不要忘了给最后一个节点置空，不然电脑很有可能死机
```
def swapPairs(head: ListNode) -> ListNode:
    link = []
    p = head
    while p:
        link.append(p)
        p = p.next
    for i in range(0, len(link)-1, 2):
        link[i], link[i+1] = link[i+1], link[i]

    p = ListNode(-1)
    ans = p
    for node in link:
        p.next = node
        p = p.next
    p.next = None
    return ans.next
```
