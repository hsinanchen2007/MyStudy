思路：有点类似于大数加法，不需要将整个数的和求出，只需要每一位对应相加，记录下进位，如果最后进位不为零再将进位填进去

![未命名文件.png](https://pic.leetcode-cn.com/1d090afd01a12f741c7e385c9f5bc1fe6d7611c01ca8cd5524624c140870d933-%E6%9C%AA%E5%91%BD%E5%90%8D%E6%96%87%E4%BB%B6.png)


```
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        sum = 0
        i = 0
        c = 0
        l = ListNode(0)
        ll = ListNode(0)
        while True:
            if l1 != None and l2 != None :
                a = l1.val + l2.val
                l1 = l1.next
                l2 = l2.next
            elif l1 != None:
                a = l1.val
                l1 = l1.next
            else:
                a = l2.val
                l2 = l2.next
            a += c
            b = a % 10
            c = a // 10
            if i == 0:
                l = ListNode(b)
                ll = l
            else:
                ll.next = ListNode(b)
                ll = ll.next
            #print(l)
            i+=1
            if l1 == None and l2 == None:
                if c != 0:
                    ll.next = ListNode(c)
                return l
```
