### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        ListNode* head=new ListNode(-1);
        ListNode* ans=head;
        for(int i=0;i<arr.size();i++)
        {
            ListNode* x=new ListNode(arr[i]);
            head->next=x;
            if(arr[i]==0) {
            ListNode* y=new ListNode(arr[i]);
            head->next->next=y;
            head=head->next;
            }        
            head=head->next;
        }
        for(int i=0;i<arr.size();i++)
        {
            arr[i]=ans->next->val;
            ans=ans->next;
        }
    }
};
```