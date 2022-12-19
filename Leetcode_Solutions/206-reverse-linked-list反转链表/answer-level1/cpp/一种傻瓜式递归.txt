```
class Solution {
public:
    ListNode* res = NULL;
    ListNode* reverseList(ListNode* head) {
        if (! head) return res;
        dfs(head);
        return res;
    }

    ListNode* dfs(ListNode* head) {
        if (! head->next) {
            res = new ListNode(head->val);
            return res;
        }
        ListNode* tmp =  dfs(head->next);
        tmp->next = new ListNode(head->val);
        return tmp->next;
    }
};
```
首先定义res成员, 这个res是为了记录链表的头位置，深度优先搜索首先搜索到最末尾的位置，之后每次返回把之前的返回作为下一个节点。
这种接法使用了额外的内存空间，所以内存占用会高，但是确实是比较傻瓜的递归解法了。
