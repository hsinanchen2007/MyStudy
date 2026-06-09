> 61. 旋转链表  

[61. 旋转链表](https://leetcode-cn.com/problems/rotate-list/)  

给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

```c

执行用时 :8 ms, 在所有 C 提交中击败了71.83%的用户  
内存消耗 :7.3 MB, 在所有 C 提交中击败了86.84%的用户  

思路：分析得一规律，即移动k步，链表的头指针应移动 len - k%len步    
1. 一趟循环，确定链表的首尾节点及长度，并将链表改成单项循环链表  
2. 移动首尾指针，循环结束后断开循环链表  

struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head == NULL)return head;
    struct ListNode *end = NULL;
    struct ListNode *curr = head;
    int len = 0;
    // 第一趟循环，确定链表长度及首尾节点
    while(curr->next){
        curr = curr->next;
        len++;
    }
    // 循环结束，此时curr为最后一个节点
    end = curr;
    len++;
    // 将最后一个节点指向首元节点，形成循环链表
    end->next = head;
    // head指针前移，x为前移的步数
    int x = len - k%len;
    // head指针前移，end指针前移
    while(x > 0){
        head = head->next;
        end = end->next;
        x--;
    }
    // 循环结束，此时head指向首元节点，end指向最后一个节点
    // 断开循环
    end->next = NULL;
    return head;
}


```
