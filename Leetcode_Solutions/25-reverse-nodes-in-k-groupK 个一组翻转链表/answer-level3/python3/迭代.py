### 解题思路
常数的空间，就想到指针了。
![微信图片_20200128195955.jpg](https://pic.leetcode-cn.com/618f8dfcb784d95a45e8c28961c39024be751d0bacedbc070faf9b89447ecb8a-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200128195955.jpg)

### 代码

```python3
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        prehead = ListNode(-1)
        prehead.next = head
        p = prehead

        p_list = [None for _ in range(k)]
        while True:
            # 构建前驱节点
            prenode = p
            # 构建交换节点
            for i in range(k):
                if p == None:
                    break
                p = p.next
                p_list[i] = p
            if p == None:
                break
            # 翻转
            prenode.next = p_list[k-1]
            p_list[0].next = p_list[k-1].next
            for i in range(k-1,0,-1):
                p_list[i].next = p_list[i-1]
            p = p_list[0]
        return prehead.next
```