### 解题思路
注意點：判斷進位，此處采取補零的方法。
代碼注意點：
1.不能使用連等式，否則會報錯（沒有重載）li=l2=p;(X)

2.ListNode* ans=NULL;(X)
原因：把null變成指向結構體的指針需要重載
  ListNode* ans=ListNode(-1);(正解)

3.ListNode* ans=ListNode(-1),tail = ans;(x)
原因：報錯，格式錯誤（暫時不知道爲什麽會讓指針變成結構體導致賦值錯誤）
ListNode* ans=ListNode(-1)；
ListNode* tail = ans;(正解)



### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*情況:
    [5]
    [5]
    處理：如果進位仍存在（jinwei==true）則在尾節點加上新節點val=1
    [9,8]
    [1]
    處理：補零
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode(-1);
        ListNode* tail = ans;
        bool empty = true;
        ListNode* p1=l1;
        ListNode* p2=l2;
        bool jinwei=false;
       while(p1!=NULL||p2!=NULL){
           if(p1==NULL) p1=new ListNode(0);
           if(p2==NULL) p2=new ListNode(0);
            int tempVal=p1->val+p2->val;
            if(jinwei){ tempVal++;jinwei=false;}
            if(tempVal>9)
            {
                jinwei=true;
                tempVal-=10;
            };           
            if(empty)
            {
                ans->val=tempVal;
                empty=false;
                }
            else
            {
                tail->next=new ListNode(tempVal);
                tail=tail->next;
            };
            p1=p1->next;
            p2=p2->next;
        };
    /*    while(p1!=NULL){
            tail->next=p1;
            p1=p1->next;
            tail=tail->next;
        };
        while(p2!=NULL){
            tail->next=p2;
            p2=p2->next;
            tail=tail->next;
        };*///如果將剩下的直接連在尾部，此處代碼邏輯相加無法處理尾部進位，所以采用補零的方法，這樣就可以讓兩數位數對齊，進入循環中判斷進位的if語句。
        if(jinwei) tail->next=new ListNode(1);
        return ans;
    };
};
```