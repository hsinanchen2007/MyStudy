### 解题思路
记录一下问题：
1.一遍代码写下来处理编译错误，大概是"malloc vs delete"，这里释放内存用的是delete，而我用的是malloc,于是我改用了new, 
```
ListNode *head = new ListNode(0);
ListNode *p = new ListNode(visit[i]);
```
第一行我觉得可以用
```
ListNode *head = new ListNode();
```
但是编译错误，不知道为什么。
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> visit;
        ListNode *p;
        for(int i=0;i<lists.size();i++){
            p = lists[i];
            while(p!=NULL){
                visit.push_back(p->val);
                p = p->next;
            }
        }
        sort(visit.begin(), visit.end());
        ListNode* head = new ListNode(0), *temp;
        p = head;
        p->next = NULL;
        for(int i=0;i<visit.size();i++){
            //temp = (ListNode*)malloc(sizeof(struct ListNode));
            temp = new ListNode(visit[i]);
            //temp->val = visit[i];
            p->next = temp;
            p = temp;
        }
        p->next = NULL;
        return head->next;
    }
};
```