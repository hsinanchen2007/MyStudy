不考虑进位问题，直接求出两个链表所代表的数字， 再将计算所得数字存进链表返回即刻，但是感觉这么搞失去了这个题的意义。耗时64ms，也不是很快
代码如下：
```
def twoSum(l1: ListNode, l2: ListNode) -> ListNode:
    num1 = 0
    num2 = 0

    # 计算l1所代表的真实值
    idx = 0
    while l1.next is not(None):
        num1 += 10 ** idx * l1.val
        l1 = l1.next
        idx += 1
    num1 += 10 ** idx * l1.val

    # 计算l2所代表的真实值
    idx = 0
    while l2.next is not(None):
        num2 += 10 ** idx * l2.val
        l2 = l2.next
        idx += 1
    num2 += 10 ** idx * l2.val

    ret = num1 + num2

    tmpNode = ListNode(0)
    l3 = tmpNode
    # 将计算结果转为Listnode返回
    for num in reversed(list(str(ret))):
        tmpNode.next = ListNode(int(num))
        tmpNode = tmpNode.next

    return l3.next
```

