// 如果感觉有启发，欢迎点赞，让我知道题解帮助到了大家😊。

// ### Method1:暴力法
// 对于链表A中的每个节点，都对链表B进行遍历，判断是否有相同的节点

// ### code

// ```cpp
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *cur1=headA;
        while(cur1)
        {
            ListNode *cur2=headB;
            while(cur2)
            {
                if(cur1==cur2)
                    return cur1;
                cur2=cur2->next;
            }
            cur1=cur1->next;
        }
        return nullptr;
    }
};
// ```
// ### Method2:使用set
// 使用set存链表A中的节点，然后遍历链表B，检查set中是否有相同的节点

// ### code
// ```
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> s;
        while(headA)
        {
            s.insert(headA);
            headA=headA->next;
        }
        while(headB)
        {
            if(s.find(headB)!=s.end())
                return headB;
            headB=headB->next;
        }
        return nullptr;
    }
};
// ```

// ### Method3:双指针
// 使用两个指针分别指向headA和headB，当一个指针先到达末尾时，就让它指向另一个指针的头部，如果相遇的话就是交点；否则的话两个指针都走了两个链表的长度，返回null。

// ### code
// ```
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA=headA,*curB=headB;
        while(curA != curB)
        {
            if(curA==NULL)
                curA=headB;
            else
                curA=curA->next;
            if(curB==NULL)
                curB=headA;
            else
                curB=curB->next;
        }
        return curA;
    }
};
// ```

