递归和迭代两种方法，貌似递归考核的可能性会大一点。
这一题题解估计大家都差不多。
迭代方法就是头插法，把新节点插到最前面即可。
```
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = new ListNode(-1);
        while(head){
            ListNode* tmp = head->next;
            head->next = newHead->next;
            newHead->next = head;
            head = tmp;
        }
        return newHead->next;
    }
};
```

递归方法就这一个套路了，记住比什么都管用
```
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode*h= reverseList(head->next);
        head->next->next = head;
        head->next=NULL;
        return h;
    }
};
```
