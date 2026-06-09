

**solution**

![深度截图_选择区域_20191017220646.png](https://pic.leetcode-cn.com/57a8ae2555aacb3f6021b0d44e26170a1315edc05758a0847e3352990786285c-%E6%B7%B1%E5%BA%A6%E6%88%AA%E5%9B%BE_%E9%80%89%E6%8B%A9%E5%8C%BA%E5%9F%9F_20191017220646.png)


1. 使用vector<char>a1,a2 分别保存l1,l2各自的位
2.  将从最后一个数开始a1、a2对应位数相加，再与进位相加的，结果保存到vector<char> res中
3. 将进位以及对应的res转化成链表


```


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<char> a1,a2,res;
        char carry = 0;
        char temp;
        while(l1){
            a1.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2){
            a2.push_back(l2->val);
            l2 = l2->next;
        }
        int i1 = a1.size();
        int i2 = a2.size();        
        while(i1 || i2){ 
            if(i1 && i2){
                temp = a1[i1-1] + a2[i2-1] + carry;
                i1--;
                i2--;
            }
            else if( i1 && (!i2) ){
                temp = a1[i1-1] + carry;
                i1--;
            }
            else if((!i1) && i2){
                temp = a2[i2-1] + carry;
                i2--;
            }
            carry = temp>=10? true:false;
            res.push_back(temp%10);
        }
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        if(carry){
            p->next = new ListNode(1);
            p = p->next;
        }
        for(int i=res.size()-1; i>=0; i--){
            p->next = new ListNode(res[i]);
            p = p->next;
        }
        return head->next;
    }
```
