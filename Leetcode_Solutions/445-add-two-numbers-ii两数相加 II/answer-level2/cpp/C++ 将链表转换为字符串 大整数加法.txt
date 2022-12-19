//大整数加法
```
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {  
        // 链表 —> 字符串
        string s1, s2;  
        while(l1){  
            s1 += to_string(l1->val);
            l1 = l1->next;
        }
        while(l2){
            s2 += to_string(l2->val);
            l2 = l2->next;
        }
        //大整数加法
        string ans;
        int cur = 0;
        int i = s1.size()-1, j = s2.size()-1;
        
        while(cur || i >= 0 || j >= 0){
            if(i >= 0) cur += s1[i--] - '0';
            if(j >= 0) cur += s2[j--] - '0';
            ans = to_string(cur % 10) + ans;
            cur /= 10;
        }
        // 字符串 —> 链表
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        for(auto i : ans){
            ListNode* t = new ListNode(i-'0');
            p->next = t;
            p = t;
        }
        
        return head->next;
    }
```