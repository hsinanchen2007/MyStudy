一般情况下，链表问题中设计到了位置都应该考虑通过构造双指针的移动规则来解决，因为链表无法知晓长度也无法随机访问。

本题可使用快慢双指针解决:
1. 初始时两个指针均指向头指针。
2. 如果快指针为空或者快指针的next为空，那么此时慢指针即为答案，移动结束。
3. 每轮移动，快指针需要移动两次，慢指针需要移动一次。跳转步骤二。

尝试证明一下：
如果链表只有一个元素，那么不会触发移动逻辑，此时慢指针指向head，显然正确。
设链表总共有n个元素，且n > 1。当算法结束时，必然进行了 $\lfloor\frac{n}{2}\rfloor$ 轮移动。此时慢指针必然指向第 $1+\lfloor\frac{n}{2}\rfloor$ 个元素。

以 [1,2,3,4,5,6] 为例，移动过程如下图：
![快慢指针.png](https://pic.leetcode-cn.com/2c8b8f5f0e663e3c27ee3960e0aae0c6b32d8b3a81c5f6346e1cda4621b415c5-%E5%BF%AB%E6%85%A2%E6%8C%87%E9%92%88.png)

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *p = head, *q = head;
        while(q != nullptr && q->next != nullptr) {
            p = p->next;
            q = q->next->next;
        }
        return p;
    } 
};
```


# 扫码关注 快乐加倍
![qrcode_for_gh_6e5f8557b1f8_258.jpg](https://pic.leetcode-cn.com/6eb3a036ebf59be0f665392a8df6fbb0fe671cea5774cc0559ac2f6c290fe15d.jpg)
