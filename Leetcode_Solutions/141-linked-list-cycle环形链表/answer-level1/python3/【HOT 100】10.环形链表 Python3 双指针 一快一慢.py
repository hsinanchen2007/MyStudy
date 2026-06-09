
### 0.更新

依然是看到判断是否有环，就考虑双指针，一快一慢，判断两个指针是否会相遇：
只是现在写的时候是在while循环里以`p and q and q.next`作为条件，内部判断`if p == q`，不再是在以`while p != q`作为条件：

```
class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if not head or not head.next:
            return False
        
        p = head.next
        q = head.next.next
        
        '''多层结构一定要判断到上一层级'''
        while p and q and q.next:
            if p == q:
                return True
            p = p.next
            q = q.next.next
            
        return False
```

![image.png](https://pic.leetcode-cn.com/fd9cc66eb1c681b3e8afe0d5fe98b1b0528988fbb56290d884bb11abb55a0a1c-image.png)



### 1.while判断的另一种形式：

看到环，就想到一个人走快点，一个人走慢点，走快点的人总会追上走得慢的这个人

所以用**双指针**，一个每次走一步，一个每次走两步，如果他们能相遇，说明有环，相遇表示为p==q，如果不能相遇，那肯定没有环，不能相遇表示为走得快的就走完了都还没遇上，那么就可以写代码了：

```
class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if not head or not head.next:
            return False
        
        p = head.next
        q = head.next.next
        
        while p != q:
            '''多层级结构的判断，判断到上一层级就可以了'''
            if p and q and q.next:
                p = p.next
                q = q.next.next
            # 这个表已经被走完了但是还没有相遇
            else:
                return False
        
        return True
```



![image.png](https://pic.leetcode-cn.com/195d915b0f310415ba328e0ad88c7a889d8172b7d8a0d632acafd31335be5945-image.png)
