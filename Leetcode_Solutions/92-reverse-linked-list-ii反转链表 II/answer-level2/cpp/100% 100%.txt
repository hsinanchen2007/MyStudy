### 解题思路
此处撰写解题思路

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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* result=NULL;
        ListNode* temp ;
        ListNode* front,*back ;
        ListNode* head_buf = head;
        front = head;
        for (int i = 1 ; i < m ; ++i ){
            front = head ;
            head=head->next ;
        }
        back = head ;
        int cnt =0;
        while(head && (cnt++<n-m+1)){
            temp = head->next ;
            head->next = result ;
            result =head;
            head=temp;
        }
        if(m==1){
            head_buf = result ;
        }else{
            front->next = result ; 
        }
        back->next=temp;
        return head_buf;
        
    }
};
```