//以下是我的一些思路，供参考谢谢！
    
```
if (!l1 || !l2) return l1==nullptr?l2:l1;
    queue<int> q1,q2;
    while (l1) {
        q1.push(l1->val);
        l1 = l1->next;
    }
    while (l2) {
        q2.push(l2->val);
        l2 = l2->next;
    }
    int n1 = 0,n2 = 0,carry = 0,sum = 0;
    ListNode *End = new ListNode(-1);
    ListNode *Head = End;
    End->next = nullptr;
    ListNode *Tmp = nullptr;
    while (!q1.empty() || !q2.empty() || carry) {
        if (q1.empty()) n1 = 0;
        else {
            n1 = q1.front();
            q1.pop();
        }
        if (q2.empty()) n2 = 0;
        else {
            n2 = q2.front();
            q2.pop();
        }
        sum = n1 + n2 + carry;
        ListNode *Tmp = new ListNode(sum%10);
        End->next = Tmp;
        End = Tmp;
    
        carry = sum/10;
    }
    
    End->next = nullptr;
    ListNode *Q = Head->next;
    delete Head;

    return Q; 
```

