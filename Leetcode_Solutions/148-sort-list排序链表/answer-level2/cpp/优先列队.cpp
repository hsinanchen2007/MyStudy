## 思路
堆排序的复杂度是$n\log n$，而且可以用于非顺序存储的结构。
所以可以借用优先队列进行实现。
## 代码
```
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
    struct node{
        ListNode* data;
        int val;
        node(ListNode* data,int val)
        {
            this->data = data;
            this->val = val;
        }
        bool operator<(node x)const
        {
            return val > x.val;
        }
    };
    ListNode* sortList(ListNode* head) {
        priority_queue<node> que;
        ListNode* p = head;
        while(p != NULL)
        {
            node tmp(p,p->val);
            que.push(tmp);
            p = p->next;
        }
        ListNode* res = new ListNode(0);
        ListNode* r = res;
        while(!que.empty())
        {
            node tmp = que.top();
            r->next = tmp.data;
            que.pop();
            r = r->next;
            r->next = NULL;
        }
        ListNode* tmp = res;
        res = res->next;
        delete tmp;
        return res;
    }
};
```
