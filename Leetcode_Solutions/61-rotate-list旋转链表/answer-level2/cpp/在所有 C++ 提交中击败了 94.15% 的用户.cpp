### 解题思路
注意如果k>链表长度，直接用余数


### 代码

```cpp
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||k==0){
            return head;
        }
        int n = 1;
        ListNode* temp = head;
        while(temp->next){
            n++;
            temp = temp->next;
        }
        k = k%n;
        if(k==0) return head;
        ListNode* temp1 = head;
        for(int i=1;i<n-k;i++){
            temp1 = temp1->next;
        }
        temp->next = head;
        ListNode* res = temp1->next;
        temp1->next = NULL;
        return res;
    }
};
```