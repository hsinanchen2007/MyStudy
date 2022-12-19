 C++实现

```
/**
由于是使用O(1)空间复杂度：否则可以用把后半部分入栈来对比

1. 获取中间的节点
2. 中间节点的右边段反转
3. 比较左边和右边的节点是否一致，不一致直接false

    1->2->3->2->1  mid=3
*/
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;

        ListNode* mid = midNode(head);
        ListNode* rNode = reversalNode(mid->next);
        mid->next = rNode;

        ListNode* cur = head;
        ListNode* rightNode = mid->next;
        while(rightNode != nullptr) {
            if (rightNode->val != cur->val) return false;

            cur = cur->next;
            rightNode = rightNode->next;
        }

        return true;
    }

      // 快慢指针来找中间节点
    ListNode* midNode(ListNode *head) {
        if (head == nullptr) return head;

        ListNode* fastNode = head;  
        ListNode* slowNode = head;  
        while(fastNode && fastNode->next != nullptr && fastNode->next->next != nullptr) {
            fastNode = fastNode->next->next;
            slowNode = slowNode->next;
        }

        return slowNode;
    }

   // 翻转链表
    ListNode* reversalNode(ListNode* head) { // 1-2-3
        ListNode* cur = head; // 1-2-3
        ListNode* pre = nullptr; 

        while(cur != nullptr) {
            ListNode* tempNextNode = cur->next; // 2-3
            cur->next = pre;  // 1-NULL
            pre = cur;  // 1-NULL
            cur = tempNextNode; // 2-3
        }

       return pre;
    }
```
