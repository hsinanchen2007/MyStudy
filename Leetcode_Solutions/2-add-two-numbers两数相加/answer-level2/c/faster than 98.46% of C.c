C版本实现： 
 Runtime: 8 ms, faster than 98.46% of C online submissions for Add Two Numbers.


```
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = NULL;
    struct ListNode *curNode = NULL;
    //记录上一个节点的和是否有进位
    int addNum = 0;
    //每个节点当前位的和
    int sum = 0;
    
    while (l1!=NULL || l2!=NULL || addNum==1) {
        
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = 0;
        node->next = NULL;
        
        if (l1!=NULL&&l2!=NULL) {
            //两个链表长度都覆盖到的节点
            sum = l1->val + l2->val;
            sum += addNum;
            int val = sum%10;
            node->val = val;
            
            l1 = l1->next;
            l2 = l2->next;
            
        }else if (l1!=NULL) {
            
            sum = l1->val;
            sum += addNum;
            int val = sum%10;
            node->val = val;
            
            l1 = l1->next;
            
        }else if (l2!=NULL) {
            
            sum = l2->val;
            sum += addNum;
            int val = sum%10;
            node->val = val;
            
            l2 = l2->next;
            
        }else {//两个链表都遍历结束但尾节点相加还有进位
            
            node->val = 1;
            addNum = 0;
            sum = 0;
        }
        
        addNum = sum>=10 ? 1 : 0;
        
        if(head==NULL){
            head = node;
        }else{
            curNode->next = node;
        }
        curNode = node;
        
    }
    
    return head;
}
```