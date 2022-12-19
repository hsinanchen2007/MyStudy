![TIM截图20191216195152.png](https://pic.leetcode-cn.com/8a414d85ed42a238e989a1175b2c093720e89f4384b2fda37b0a85d1f1b6d9c2-TIM%E6%88%AA%E5%9B%BE20191216195152.png)

### 解题思路
* 可以把整个链表想成两部分：已经两两交换过的前链，还没有交换的后链，每次迭代对后链相邻两个节点交换。
* 使用三个辅助指针：end指向前链的最后一个节点；pre，cur分别指向当前交换的前节点和后节点。
* 核心代码：
```
    tmp = cur.next    # 临时节点用于存储后续要交换的节点
    end.next = cur    # 前链指向后节点
    cur.next = pre    # 后节点指向前节点
    
    end = pre    # 更新三个指针
    pre = tmp
    cur = tmp.next
```
* 循环结束时进行特殊处理
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        end = ListNode(0)    # end初始化为头结点
        res = head.next    # 返回结果首节点   
        pre, cur = head, head.next    # 当前要交换的前节点，后节点
        while cur:
            tmp = cur.next
            end.next = cur    
            cur.next = pre
            end = pre
            if not tmp:    # 节点数为偶数的结束条件
                end.next = None
                break
            pre = tmp
            cur = tmp.next
        if not cur:    # 节点数为奇数的处理
            end.next = pre
        return res
```