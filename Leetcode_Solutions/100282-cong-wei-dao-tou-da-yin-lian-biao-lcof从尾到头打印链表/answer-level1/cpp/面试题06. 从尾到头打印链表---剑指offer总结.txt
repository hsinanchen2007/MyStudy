`剑指offer---P58-59`
1. 把链表中链接节点的指针反转过来，改变链表的方向，这个方法取决于面试官是否允许改变链表原来的结构。
2. 用栈实现，每经过一个节点的时候，把这个节点放到栈中。当遍历完整个链表后，再从栈顶开始逐个输出节点的值。
3. 递归在本质上也是一个栈结构，可以用递归实现。每访问到一个节点的时候，先递归输出它后面的节点，再输出该节点自身。但是当链表非常长的时候，会导致函数调用的层级很深，有可能导致函数调用栈溢出。所以用栈实现的鲁棒性最好。


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
    vector<int> reversePrint(ListNode* head) {
        if(!head)return {};
        vector<int>res;
        stack<ListNode*>nodes;
        ListNode* node=head;
        while(node)
        {
            nodes.push(node);
            node=node->next;
        }
        while(!nodes.empty())
        {
            res.push_back(nodes.top()->val);
            nodes.pop();
        }
        return res;
    }
};
```