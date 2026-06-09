为了大到O(1)空间负责度的目的，只能在原有链表上进行操作。

整体思路：将整个链表分为两截，将后半截进行反转，反转之后和第一截进行比较，如果一致则代表是回文序列。

注意： 
1. 注意处理链表长度为奇数和偶数的情况。
2. 要将第一截链表在合适的地方断开。

具体代码如下： 

```
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return true;
        }
        
        ListNode* h = head;
        int length = 0;
        // 获取长度
        while(h != NULL) {
            h = h->next;
            length += 1;
        }
        // 长度的一半
        int half = length / 2;
        // 奇数在中间跳过一个，偶数不跳
        int skip = length%2;
        
        ListNode* l1 = head;
        ListNode* l2 = head;
        ListNode* cut = NULL;       // l1应当断开的地方
        
        // 目的 
        // 1. 将l2遍历到链表2 开始反转的地方
        // 2. 将l1在合适的位置(half-1)处断开
        for(int i = 0; i < half+skip; i++) {
            if(i == half-1) {
                cut = l2;
            } 
            l2 = l2->next;
        }
        
        // 断开l1
        cutList(l1, cut);
        
        // l2遍历到了开始反转的地方.
        auto newHead = reverseList(l2);
        
        // 比较，返回
        return compareList(l1, newHead);
        
    }
    static void cutList(ListNode* head, ListNode* cutNode) {
        while(head != cutNode) {
            head = head -> next;
        }
        head->next = NULL;
    }
    static ListNode* reverseList(ListNode* head) {
        ListNode* newHead = NULL;
        while(head != NULL) {
            ListNode* nextNode = head->next;
            head->next = newHead;
            newHead=head;
            head=nextNode;
        }
        return newHead;
    }
    static bool compareList(ListNode* l1, ListNode* l2) {
        while(l1 != NULL && l2 != NULL) {
            // 数值不一致
            if(l1->val != l2->val) {
                return false;
            }
            l1 = l1->next; l2 = l2->next;
        }
        // 长度不一致
        if(l1 != NULL || l2 != NULL) {
            return false;
        }
        // 完全一致，返回
        return true;
    }
};
```