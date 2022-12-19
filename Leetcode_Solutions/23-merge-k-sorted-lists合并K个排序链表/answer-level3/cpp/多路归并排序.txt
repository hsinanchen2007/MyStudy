### 解题思路
使用优先队列维护所有链表的头部，每次找值最小的一个节点作为下一个节点，将该节点从队列中移除，如果该节点还有后继节点，则将其后继节点加入队列。

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
    struct Node {
        ListNode* ptr;
        int val;
        Node(ListNode* a, int b) {
            ptr = a;
            val = b;
        }
    };
    struct cmp {                // 使用class要注意class的成员默认是私有的
        bool operator()(const Node& a, const Node& b) {
            return a.val > b.val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;

        ListNode *head = new ListNode(NULL, 0), *cur = head;    // 头部加一个哨兵节点
        priority_queue<Node, vector<Node>, cmp> q;
        for (auto i : lists) {
            if (i)
                q.push(Node(i, i->val));
        }

        while(!q.empty()) {
            Node tmp = q.top();
            q.pop();
            cur->next = tmp.ptr;
            cur = cur->next;
            if (cur->next)
                q.push(Node(cur->next, cur->next->val));
        }

        head = head->next;
        return head;
    }
};
```