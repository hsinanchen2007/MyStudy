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
    ListNode* reverseList(ListNode* head) {
        stack<int> st;
        ListNode*res=new ListNode(0);
        ListNode*result=res;
        ListNode*pNode=head;
        while(pNode!=NULL){
            int temp=pNode->val;
            st.push(temp);
            pNode=pNode->next;
        }
        
        while(!st.empty()){
            int temp=st.top();
            //给res增加节点
            ListNode*pTemp=new ListNode(0);
            pTemp->val=temp;
            res->next=pTemp;

            st.pop();
            res=res->next;
        }
        return result->next;

    }
};
```