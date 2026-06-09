迭代写的头疼

### 递归版本
```c++
class Solution {
public:
    ListNode* sortList_R(ListNode* l){
        if(!l || !l->next) return l;
        if(!l->next->next) {
            if(l->val > l->next->val){
                ListNode* h=l->next; h->next=l; l->next=NULL; return h;
            }else return l;            
        }
        ListNode* pre = l;
        ListNode* fast = l; ListNode* slow = l;
        while(fast && fast->next){
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        
        pre->next = NULL;
        l = MergeTwoList_R(sortList(l), sortList(slow));
        return l;
    }

    ListNode* MergeTwoList_R(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val <= l2->val) {
            l1->next = MergeTwoList(l1->next, l2);
            return l1;
        }else{
            l2->next = MergeTwoList(l1, l2->next);
            return l2;
        }
    }
};
```



### 迭代版本
```c++
class Solution {
public:
    ListNode* sortList(ListNode* l){
        ListNode* headNode = new ListNode(0);
        headNode->next = l;
        
        ListNode* l1=l; ListNode* l2=l;
        int size=0;
        while(l1){l1=l1->next; size++;}
        ListNode* end=headNode;
        for(int intervals=1; intervals<size; intervals*=2){
            end = headNode;
            
            l1=headNode->next; int flag=0;   // flag等于0表示不存在不完整的链
            while(l1){
                l2=l1;
                ListNode* pre=nullptr;
                for(int i=0; i<intervals; i++) {  //  至少能检查l1链的完整
                    if(!l2) {flag=1; break;}    //说明此时l1不完整
                    pre=l2; // pre指向l1的最后一个元素
                    l2=l2->next;
                }
                
                pre->next=nullptr;  // 断开l1
                
                if(flag){   //如果l1不完整，没必要进行l2的相关操作
                    pre->next = nullptr;
                    end->next = MergeTwoList(l1, l2);
                    end = FindEnd(headNode);
                    break;
                }
                // 如果能通过上面的if 说明至少l1是完整的 是有l2的。
                
                ListNode* remain=l2; // remain用来存放剩下的nodes
                for(int i=0; i<intervals; i++) {  //  至少能检查l2链的完整
                    if(!remain) {flag=1; break;}    //说明此时l2不完整
                    pre=remain; //  pre指向l2最后一个元素
                    remain=remain->next;
                }

                pre->next=nullptr;  // 断开l2
                ListNode* ans = MergeTwoList(l1, l2);   // 无论l2是否完整 都可以与l1实现merge
                end->next = ans;
                end = FindEnd(headNode);    // 更新end 得到当前链上最后一个node

                if(flag){   //如果l2不完整，没必要进行remain的相关操作
                    break;
                }
                // 如果能通过上面的if 说明至少l2是完整的 是有remain的 可以继续执行接下来的操作 开启新的循环
                l1 = remain;
            }
        }
        return headNode->next;   
    }
    
    ListNode* FindEnd(ListNode* l){
        ListNode* end = l;
        while(l){
            end=l;
            l=l->next;
        }
        return end;
    }

    ListNode* MergeTwoList(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* head=l1; ListNode *cur=l1;
        if(l1->val <= l2->val) l1=l1->next;
        else{
            head=l2; cur=head; l2=l2->next;
        }
        while(l1 && l2){
            if(l1->val <= l2->val){
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            }else{
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }
        if(!l1) cur->next=l2;
        if(!l2) cur->next=l1;
        return head;
    }
};
```


