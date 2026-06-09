### 解题思路
分四种情况讨论：
l1下一个为NULL，l2下一个不为NULL；
l1下一个为NULL，l2下一个为NULL；
l1下一个不为NULL，l2下一个不为NULL；
l1下一个不为NULL，l2下一个为NULL；

### 代码

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result=l1;
        int carry=0,tempCarry,tempVal;
        while(true){
            tempCarry=(l1->val+l2->val+carry)/10;
            tempVal=(l1->val+l2->val+carry)%10;
            carry=tempCarry;
            l1->val=tempVal;
            if(l1->next==NULL){
                if(l2->next==NULL){
                    (carry!=0)?l1->next=new ListNode(carry):0;
                }else{
                    l2=l2->next;
                    tempVal=(l2->val+carry)%10;
                    tempCarry=(l2->val+carry)/10;
                    l2->val=tempVal;
                    carry=tempCarry;
                    l1->next=l2;
                    while(l2->next!=NULL){
                        l2=l2->next;
                        tempVal=(l2->val+carry)%10;
                        tempCarry=(l2->val+carry)/10;
                        carry=tempCarry;
                        l2->val=tempVal;
                    }
                    (carry!=0)?l2->next=new ListNode(carry):0;
                }
                break;
            }else{
                if(l2->next==NULL){
                    l1=l1->next;
                    tempVal=(l1->val+carry)%10;
                    tempCarry=(l1->val+carry)/10;
                    l1->val=tempVal;
                    carry=tempCarry;
                    while(l1->next!=NULL){
                        l1=l1->next;
                        tempVal=(l1->val+carry)%10;
                        tempCarry=(l1->val+carry)/10;
                        l1->val=tempVal;
                        carry=tempCarry;
                    }
                    (carry!=0)?l1->next=new ListNode(carry):0;
                    break;
                }else{
                    l1=l1->next;
                    l2=l2->next;
                }
            }
        }
        return result;
    }
};
```