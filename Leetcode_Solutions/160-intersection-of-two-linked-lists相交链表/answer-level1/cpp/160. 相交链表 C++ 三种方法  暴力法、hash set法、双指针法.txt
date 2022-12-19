```cpp
方法一: 暴力法 
对链表A中的每一个结点 ai​，遍历整个链表 B 并检查链表 B 中是否存在结点和 ai​ 相同。
时间复杂度O(m * n)   空间复杂度O(1)

class Solution {
public:
    //返回相交的节点
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* cur_a = headA;
        
        while (cur_a)
        {
            ListNode* cur_b = headB;
            while (cur_b)
            {
                if (cur_a == cur_b)
                {
                    return cur_a;
                }
                cur_b = cur_b->next;
            }
            cur_a = cur_a->next;
        }

        return nullptr;
    }
};


方法二: 哈希表法
使用一个hash set  遍历一个链表，set中存放其所有指针， 遍历另一个链表，去set中找相同指针
时间复杂度O(m + n)    空间复杂度O(m) 或 O(n)

class Solution {
public:

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        std::unordered_set<ListNode*> set;

        ListNode* cur_a = headA;
        
        while (cur_a)
        {
            set.insert(cur_a);
            cur_a = cur_a->next;
        }

        ListNode* cur_b = headB;

        while (cur_b)
        {
            if(set.find(cur_b) != set.end()) //找到了
            {
                return cur_b;
            }
            cur_b = cur_b->next;
        }

        return nullptr;
    }
};


方法三：双指针法

A的指针遍历完A 接着从headB开始遍历
B的指针遍历完B 接着从headA开始遍历
两个指针都最多走m + n + 1步。
当两个指针同时为空时，表示不相交；当两个都非空且相等时，表示相交

时间复杂度O(m + n)  空间复杂度O(1)

动画展示：
https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/lian-biao-xiang-jiao-shuang-zhi-zhen-onshi-jian-fu/

class Solution {
public:
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if(headA == nullptr || headB == nullptr) 
            return nullptr;

        ListNode* cur_a = headA;
        ListNode* cur_b = headB;

        while(cur_a != cur_b)
        {
            cur_a = (cur_a == nullptr ? headB : cur_a->next);
            cur_b = (cur_b == nullptr ? headA : cur_b->next);
        }

        return cur_a;
    }
};