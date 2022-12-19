如题：
```
ListNode* middleNode(ListNode* head) {
        unordered_map<int,ListNode*> hash;
        int num=1;
        while(head!=nullptr)
        {
            hash[num++]=head;
            head=head->next;
        }
        return num%2==0?hash[num/2]:hash[(num+1)/2];
    }
```
