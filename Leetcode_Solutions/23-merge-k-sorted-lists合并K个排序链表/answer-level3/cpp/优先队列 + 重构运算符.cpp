### 解题思路
思路并不难，就是采用优先队列，第一次取所有链表的头部，然后放进去。找到最小的，然后放到一个链表中，然后将最小的对应的那个链表后面的节点放入到队列中继续往下执行。麻烦的主要是优先队列中优先级如何进行定义。可以通过定义一个结构体，再结构体中重构运算符
```
struct cmp {
            bool  operator () (ListNode *t1, ListNode* t2) {
                return t1->val > t2->val;
            }
        };
        priority_queue<ListNode*, vector<ListNode*>, cmp > sto;
```

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        struct cmp {
            bool  operator () (ListNode *t1, ListNode* t2) {
                return t1->val > t2->val;
            }
        };
        priority_queue<ListNode*, vector<ListNode*>, cmp > sto;
        ListNode *head, *p, *tmp;
        int i, len;

        len = lists.size();

        for(i = 0; i < len; i++) {
            if(lists[i]) {
            sto.push(lists[i]);
            lists[i] = lists[i]->next;
            }
        }
        
      //  printf("the size of list is %d\n", sto.top()->val);
        if(!sto.empty()) {
        head = new ListNode(sto.top()->val);
        p = head;
        tmp = sto.top();
        sto.pop();
        if(tmp->next)
        sto.push(tmp->next);
        }
        else {
            return NULL;
        }

        while(!sto.empty()) {
                tmp = new ListNode(sto.top()->val);
                p->next = tmp;
                p = tmp;
                tmp = sto.top();
                sto.pop();
                if(tmp->next) {
                    sto.push(tmp->next);
                }
        }
        
        return head;
    }
};
```