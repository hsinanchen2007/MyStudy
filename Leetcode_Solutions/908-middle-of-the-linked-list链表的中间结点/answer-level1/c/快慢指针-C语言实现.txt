> 返回链表的中间节点  
给定一个带有头结点 head 的非空单链表，返回链表的中间结点。  
如果有两个中间结点，则返回第二个中间结点。  

思路：快慢指针，当循环结束后，slow指针指的要么是中间节点，要么是第二个中间节点（如果节点数为偶数的话）  

```c
执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户  
内存消耗 :6.9 MB, 在所有 C 提交中击败了41.05%的用户  

struct ListNode* middleNode(struct ListNode* head){
    if(head == NULL)return;
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

```
