### 解题思路
链表，链表，链表！
没有什么难点，但一定要记得进位哦！
一开始是开了一个新的链表，不断new结点，28ms 10.4MB。
优化过后充分利用题目已给的两个链表，将值存储到l1里，这样既可以节省时间复杂度，也可以减少一段l1比l2长时的处理代码。

![image.png](https://pic.leetcode-cn.com/7476ea53ba8ab683c9b6a3107489bcc404f13d6695c4272d01d4fc96e8adeaaf-image.png)

### 代码
```cpp
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // pst中存储表头
        ListNode  *pst;
        pst = l1;
        // 直接将答案存储在l1中，las处理进位
        l1 -> val += l2 -> val;
        int las = l1 -> val / 10;
        l1 -> val %= 10;
        // l1和l2均为非空时的情况处理
        while(l1 -> next != NULL && l2 -> next != NULL)
        {
            l1 = l1 -> next;
            l2 = l2 -> next;
            l1 -> val += l2 -> val + las;
            las = l1 -> val / 10;
            l1 -> val %= 10;
        }
        // l1空而l2非空时的情况处理
        while(l2 -> next != NULL)
        {
            l2 = l2 -> next;
            l1 -> next = new ListNode(l2 -> val + las);
            l1 = l1 -> next;
            las = l1 -> val / 10;
            l1 -> val %= 10;
        }
        // 可以同时处理l1非空而l2空，以及最后las中需要进位的情况处理
        while(las > 0)
        {
            if(l1 -> next == NULL) l1 -> next = new ListNode(las);
            else l1 -> next -> val += las;
            l1 = l1 -> next;
            las = l1 -> val / 10;
            l1 -> val %= 10;
        }
        return pst;
    }
};
```

