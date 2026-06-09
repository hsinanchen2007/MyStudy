### 19. 删除链表的倒数第N个节点  

Emmm，我扫描了两遍。方法很直接，即第一遍获取长度，第二遍遍历到指定节点，删除！  

```c
执行用时 :4 ms, 在所有 C 提交中击败了88.91%的用户  
内存消耗 :7.1 MB, 在所有 C 提交中击败了79.70%的用户  


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(head == NULL)return head;
    struct ListNode* header = (struct ListNode*)malloc(sizeof(struct ListNode));
    header->next = head;
    struct ListNode* curr = head;
    struct ListNode* pre = header;
    int length = 0;
    while(curr){
        curr = curr->next;
        length++;
    }
    curr = head;
    n = length - n;
    while(n > 0){
        pre = curr;
        curr = curr->next;
        n--;
    }
    pre->next = curr->next;
    free(curr);
    return header->next;
}

```

```c
快慢指针： 先让快指针前移n步，然后快慢指针再同时前进，当快指针到达终点时，慢指针的位置恰好是被删除的位置。 

Emmm，这也扫描了两遍把~

执行用时 :4 ms, 在所有 C 提交中击败了88.91%的用户  
内存消耗 :7 MB, 在所有 C 提交中击败了86.78%的用户  

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(head == NULL)return head;
    struct ListNode* header = (struct ListNode*)malloc(sizeof(struct ListNode));
    header->next = head;
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* pre = header;
    while(n > 0){
        fast = fast->next;
        n--;
    }
    while(fast){
        fast = fast->next;
        pre = slow;
        slow = slow->next;
    }
    pre->next = slow->next;
    free(slow);
    return header->next;
}
```