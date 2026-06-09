```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//第一种方法（写的冗长）使用C++中的set（一条链表没循环的情况下不会发生重复地址的情况）表将第一条链表的地址存储起来
//记录第二条链表在第一条中的相同地址个数，使得A链表长度减去个数，得到第一个交点的位置
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //特殊性判断
        if(headA == nullptr || headB == nullptr ) return NULL;
       
        set<ListNode*>s;
        for(ListNode* it = headA ; it != nullptr ; it = it-> next)  //注意测试以下i++可不可以
        {
            s.insert(it);
        }
        int count = 0;
        for(ListNode* it = headB ; it != nullptr ; it = it->next)
        {
            if(s.count(it))
            count++;
        }
        if(count == 0) return NULL;

        ListNode* ans = headA;
        for(int i = 0 ; i < s.size()-count ; i++)
        {
            ans = ans->next;
        }
        return ans;
    }
};
```
