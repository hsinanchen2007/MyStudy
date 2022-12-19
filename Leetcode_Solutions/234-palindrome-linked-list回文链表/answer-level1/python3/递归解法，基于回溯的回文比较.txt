比较p，q两个指针，如果只一次遍历的话，可以利用递归的回溯特性，回溯处理q节点。

```python3
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        # p表示当前比较的左节点
        # size表示链表长度
        # p_size表示p节点移动的长度
        p, size, p_size = head, 0, 0
        def back_track(q):
            nonlocal p, size, p_size
            
            # 走到最后，返回递归，回溯比较
            if not q:
                return True
            
            # 没有走到最后，继续递归找到最后的节点
            size += 1
            if not back_track(q.next):
                return False
                
            # 1. 回溯第一步，想判断是否已经移动过半，如果一定过半，计算成功
            p_size += 1
            if p_size > size // 2:
                return True
            
            # 2. 回溯第二步，比较数值是否相同，如果不同，短路，返回失败
            if p.val != q.val:
                return False
            
            # 3. 回溯第三步，p右移一个位置，到上一层和q节点比较
            p = p.next
            return True
        
        return back_track(head)
```
