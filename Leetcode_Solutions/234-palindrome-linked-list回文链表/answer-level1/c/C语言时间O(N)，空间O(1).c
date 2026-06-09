### 解题思路
1、使用快慢指针将单链表一分为二。
2、慢指针前进的同时，进行指针的反转。
3、根据快慢指针到达尾巴的情况，区分奇数偶数个元素的单链表的情况。如果是回文链表的话，慢指针继续往前走，以及往回走的元素应该是相等的。

### 代码

```c
bool isPalindrome(struct ListNode* head){
    
struct ListNode* slow = head;
struct ListNode* fast = head;
struct ListNode* nextNode = NULL;
struct ListNode* oldNode = NULL;

//前三个，按照特殊情况处理
if ((NULL == head) || (NULL == head->next)) {
    return true;
}
if (NULL == head->next->next) {
    if (head->val == head->next->val) {
        return true;
    } else {
        return false;
    }
}

nextNode = slow->next;
//根据快慢指针，将链表对半分
while ((NULL != fast->next) && (NULL != fast->next->next)) {
    //因为slow的next会被反向指，因此要先处理fast
    fast = fast->next->next;
    oldNode = slow;
    //因为slow的next会被反向指，因此要特殊处理nextNode
    slow = nextNode;
    nextNode = nextNode->next; 
    slow->next = oldNode;  
}

//根据奇数偶数个元素，比较链表。
if (NULL == fast->next)
{
    //说明有奇数个元素，慢指针指在中间
    slow = slow->next;
    //按理说，这两个应该是同时到达尾端的。
    while ((NULL != slow) && (NULL != nextNode)) {
        if (slow->val != nextNode->val) {
            return false;
        }
        slow = slow->next;
        nextNode = nextNode->next;
    }
} else {
    //说明有偶数个元素
    while ((NULL != slow) && (NULL != nextNode)) {
        if (slow->val != nextNode->val) {
            return false;
        }
        slow = slow->next;
        nextNode = nextNode->next;
    }
}
return true;

}
```