第一眼想到符合先入先出的性质，队列打了一段
```
ListNode* partition(ListNode* head, int x) {
        //创建两个队列
        queue<int> small,big;
        ListNode* cur = head;
        while(head!=nullptr){
            if(head->val<x)//小于节点值的队列
                small.push(head->val);
            else//大于节点值的队列
                big.push(head->val);
            head = head->next;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next  = cur;
        while(!small.empty()){
            cur->val = small.front();
            small.pop();
            cur = cur->next;
        }
        while(!big.empty()){
            cur->val = big.front();
            big.pop();
            cur = cur->next;
        }
        return dummy->next;
    }
```
