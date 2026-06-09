
对于固定n,首先思考k最小的情况：
                            [1, 2, 3, ..., n-1, n]
然后想到，最小的情况时，每对调一对数组，k应增大2（个别情形时1）

对于k最大的情形，应为
                    [1, n, 2, n-1, 3, n-2, ..., (n+1）//2]

考虑k从最小到最大的变化过程，每次应该将最尾部的元素n-i插入到(2*i + 1)的位置
每进行一次这样的操作，k的值将增加2

若要求的k为奇数，则进行(k - 1) // 2次上述操作即可；
否则， 在进行了进行(k - 1) // 2次操作之后，将队尾的最末元素对换即可满足条件。

由于用到插入，菜鸟第一反应写了个双向链表。修修补补得到的代码如下：（事实上在写这篇题解时忽然想到python列表自带insert操作，用起来应该比这个舒服很多，有兴趣的可以自行实现以下。只是从时间复杂度的观点来说，链表好像的确更有优势一点。）
```

class BiListNode:
    def __init__(self, val):
        self.val = val
        self.pre = None
        self.next = None
    
class Solution:
    def constructArray(self, n: int, k: int) -> List[int]:
        head = BiListNode(None)
        p = head
        for i in range(n):
            node = BiListNode(i + 1)
            p.next = node
            node.pre = p
            p = p.next
        tail = p
        p = head.next
        q = tail

        insertTimes = (k - 1) // 2
        for i in range(insertTimes):
            p.next.pre = q
            q.next = p.next
            p.next = q
            qpre = q.pre
            q.pre = p
            p = p.next.next
            q = qpre
            q.next = None
        
        if k % 2 == 0:
            qprepre = q.pre.pre
            qpre = q.pre
            qprepre.next = q
            q.pre = qprepre
            q.next = qpre
            qpre.pre = q
            qpre.next = None
        
        p = head.next
        res = []
        while p:
            res.append(p.val)
            p = p.next
        return res    
            
```