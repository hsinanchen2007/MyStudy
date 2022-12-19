### 解题思路
用一个vector将两个链表的值存入，利用sort方法，将vector进行排序，
之后对这个容器创建链表。

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* L = nullptr;
        ListNode* p =L;
        vector<int> data;
        while(l1 != nullptr){
            data.emplace_back(l1->val);
            l1 = l1->next;
        }
        while(l2 != nullptr){
            data.emplace_back(l2->val);
            l2 = l2->next;
        }  
        sort(data.begin(),data.end());
        for(int i=0;i<data.size();i++){
            if(i==0){
                L = new ListNode(data[0]);
                p = L;
            }else{
                ListNode* temp = new ListNode(data[i]);
                p->next = temp;
                p = temp;
            }

        }      
        return L;
    }
};
```