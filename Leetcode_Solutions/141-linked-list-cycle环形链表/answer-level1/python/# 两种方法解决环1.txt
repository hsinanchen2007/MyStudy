# 两种方法解决环1
法一 存储走过的节点（鬼打墙做标记）
```
        alist = []
        cur = head
        flag = False
        while cur:
            if cur in alist:
                flag = True
                break
            alist.append(cur)
            cur = cur.next
        return flag
```
法二 快慢双指针
利用try包括快指针，因为在无环的情况下，quick.next可能为None，所以会报错！
```
        slow = head
        quick = head
        flag = False
        while slow:
            slow = slow.next
            try:
                quick = quick.next.next
            except:
                break
            if quick == slow:
                flag = True
                break
        return flag
```


