![image.png](https://pic.leetcode-cn.com/e4d7e3c8d010362bcabb191b5189847d4a76b415293749891400a05c177eba2d-image.png)


先递归复制下一个节点，再复制随机节点，避免未声明的状态

```
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        d={}
        def f(nod):
            if nod:
                if nod not in d:
                    d[nod]=Node(nod.val,None,None)
                    d[nod].next=f(nod.next)
                    d[nod].random=f(nod.random)
                    return d[nod]
                else:
                    return d[nod]
        return f(head)
```
