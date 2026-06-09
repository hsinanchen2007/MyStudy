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
    ListNode* deleteDuplicates(ListNode* head) {
        if(NULL == head)
        {
            return head;
        }
        
        set<int> s;
        return Recursion(head, s);
    }
    
    ListNode * Recursion(ListNode * head, set<int> &s)
    {
        if(head->next == NULL)                      //最后一个节点 返回自己 并且把自己的值加入set
        {
            s.insert(head->val);
            return head;
        }
        
        
        head->next = Recursion(head->next, s);      //递归到头
        
        if( !s.count(head->val))                    //如果set里没这个值 ， 那么把当前值加进set ，返回自己
        {
            s.insert(head->val);
            return head;
        }
        else                                        //如果这个值原来有过， 那么就返回自己下一个 ，由于上一行接的时候是head->next的接 此时返回的相当于上一个节点的下下个 相当于删除了自己
        {
            return head->next;
        }
    }
};
```

set值是不允许重复的，所以s.count要么1 要么0
递归有点慢