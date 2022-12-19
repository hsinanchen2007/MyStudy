先从头到尾遍历一遍链表，统计链表中元素的个数，在从头到尾保存到数组中
```
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
         ListNode *temp=head;
         int count=0;
         while(temp!=nullptr)
         {
            count++;
            temp=temp->next;
         }
         vector<int> ans(count);
         ListNode *temp1=head;
         for(int i=count-1;i>=0;--i)
         {
             ans[i]=temp1->val;
             temp1=temp1->next;
         }
     
         return ans;
    }
};
```
