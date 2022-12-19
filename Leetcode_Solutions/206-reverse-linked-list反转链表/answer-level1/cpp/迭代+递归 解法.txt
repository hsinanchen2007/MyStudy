迭代：

![image.png](https://pic.leetcode-cn.com/9f6494176f34caa6cf342ef8652810b5d8c61dfd20fb8cc6d5a5495ad789d552-image.png)
```
ListNode* reverseList(ListNode* head) {
        if(!head){
            return nullptr;
        }
        ListNode* first = head;//始终指向原链表的首位元素
        ListNode* target = head->next;//始终指向即将要放到当前链表首元素之前的目标元素
        while(target != nullptr){
            first->next = target->next;
            ListNode* temp = target->next;
            target->next = head;
            head = target;
            target = temp;
        }
        return head;
    }
```
递归：
```
ListNode* reverseList(ListNode* head) {
        if(!head){
            return nullptr;
        }
        return reverse(head, head, head->next);        
    }
    
    ListNode* reverse(ListNode* head, ListNode* first, ListNode* target){
        if(!target){
            return head;
        }
        first->next = target->next;
        ListNode* temp = target->next;
        target->next = head;
        return reverse(target, first, temp);
    }
```

