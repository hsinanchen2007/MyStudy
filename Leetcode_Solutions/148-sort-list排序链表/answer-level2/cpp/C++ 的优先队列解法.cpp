这题借助一个优先队列，先将链表逐个放入优先队列，然后出队建立返回链表。
```
class Solution {
public:
    struct cmp{
        bool operator() ( ListNode* a, ListNode* b ){return a->val < b->val;}
    };
    ListNode* sortList(ListNode* head) {
        priority_queue<ListNode*, vector<ListNode*>,cmp> que;
        if(!head) return head;
        while(head)
        {
            que.push(head);
            head = head->next;
        }
        cout<<"1"<<endl;
        ListNode *newhead = new ListNode(0); 
        ListNode *p;
        p = newhead;
        while(!que.empty())
        {
            p->next = que.top();
            que.pop();
            p = p->next;
        }
        return newhead->next;
    }
};
```
这里直接存入ListNode* 有问题，不知道我是不是有些语法没搞懂，有懂的同学可以帮忙改成节点入队
