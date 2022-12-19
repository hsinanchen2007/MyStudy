## 思路一：链表拼接
通过链表拼接消除差值，如果一个链表先走到尾部，则指向另一个链表。

### 代码
时间复杂度：O(n + m)
空间复杂度：O(1)
```c++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB){
            return nullptr;
        }
        ListNode *pA = headA, *pB = headB;
        while (pA != pB) {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
    }
}
```

## 思路二：双指针
如果链表相交，则链表公共节点都在尾部。
1. 先计算两个链表长度。
2. 让长链表指针先走多出长度，然后两个链表同时走，如果相遇则为相交节点。

### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```c++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        int len1 = len(headA), len2 = len(headB);        
        if (len1 >= len2) {
            int move = len1 - len2;
            while (move--) {
                headA = headA->next;                
            }     
        } else {
            int move = len2 - len1;
            while (move--) {
                headB = headB->next;
            }
        }
        while (headA != headB) {            
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }

    int len(ListNode *head) {
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }
        return len;
    }
};
```

