#### 解题思路：
我们使用两个指针 `node1`，`node2` 分别指向两个链表 `headA`，`headB` 的头结点，然后同时分别逐结点遍历，当 `node1` 到达链表 `headA` 的末尾时，重新定位到链表 `headB` 的头结点；当 `node2` 到达链表 `headB` 的末尾时，重新定位到链表 `headA` 的头结点。

这样，当它们相遇时，所指向的结点就是第一个公共结点。

<![幻灯片1.JPG](https://pic.leetcode-cn.com/f56b2942e83e7c7cd968771cf8b05720319e8628644bae86d5afa865f34f9b55-%E5%B9%BB%E7%81%AF%E7%89%871.JPG),![幻灯片2.JPG](https://pic.leetcode-cn.com/f6572ac3036f5b8635f6e7f7ed74129c2bfd779d9d3d77a93c3bd487f24ca75d-%E5%B9%BB%E7%81%AF%E7%89%872.JPG),![幻灯片3.JPG](https://pic.leetcode-cn.com/1e71047417d3fe70af13001889448ca7fc87f14628f9f8b3b2036663c5e7a861-%E5%B9%BB%E7%81%AF%E7%89%873.JPG),![幻灯片4.JPG](https://pic.leetcode-cn.com/8aea495c41163e3a0e38a1793d00101bbf513fc8207fb259d8c74536e85ca729-%E5%B9%BB%E7%81%AF%E7%89%874.JPG),![幻灯片5.JPG](https://pic.leetcode-cn.com/462d77ca078a7fab19e4123dd2d62d1e51191424e3f363c4935f4e06360fa5d8-%E5%B9%BB%E7%81%AF%E7%89%875.JPG),![幻灯片6.JPG](https://pic.leetcode-cn.com/51d1c09be07b6315d196272c35bc859fefff8c92e08af93605e0aedba634acbf-%E5%B9%BB%E7%81%AF%E7%89%876.JPG),![幻灯片7.JPG](https://pic.leetcode-cn.com/be37b827f0255fdc2c13ece5f10852205d6e5c0022124fad0e1c8741bff8ae97-%E5%B9%BB%E7%81%AF%E7%89%877.JPG),![幻灯片8.JPG](https://pic.leetcode-cn.com/bec16ff27968913d2d74e1f8f601df25fc514c55af1ead50f5b5db537aa6a7de-%E5%B9%BB%E7%81%AF%E7%89%878.JPG),![幻灯片9.JPG](https://pic.leetcode-cn.com/4cb9652789ae7d9a9d7c2292e50ef718230403e6cf8d8862c2ce218d0b60e05d-%E5%B9%BB%E7%81%AF%E7%89%879.JPG)>


#### 代码：

```python []
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        node1, node2 = headA, headB
        
        while node1 != node2:
            node1 = node1.next if node1 else headB
            node2 = node2.next if node2 else headA

        return node1
```
```c++ []
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *node1 = headA;
        ListNode *node2 = headB;
        
        while (node1 != node2) {
            node1 = node1 != NULL ? node1->next : headB;
            node2 = node2 != NULL ? node2->next : headA;
        }
        return node1;
    }
};
```


#### 复杂度分析
- 时间复杂度：$O(M+N)$。
- 空间复杂度：$O(1)$。

欢迎批评指正~