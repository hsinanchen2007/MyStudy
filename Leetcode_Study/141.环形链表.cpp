/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

/*

https://leetcode.cn/problems/linked-list-cycle/

141. 环形链表
给你一个链表的头节点 head ，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 
pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。

如果链表中存在环 ，则返回 true 。 否则，返回 false 。


示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。

示例 2：

输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。

示例 3：

输入：head = [1], pos = -1
输出：false
解释：链表中没有环。
 

提示：

链表中节点的数目范围是 [0, 104]
-105 <= Node.val <= 105
pos 为 -1 或者链表中的一个 有效索引 。
 

进阶：你能用 O(1)（即，常量）内存解决此问题吗？

通过次数756,467提交次数1,470,493

*/

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution100 {
public:
    // 2022.5.30, from LG solution
    //   1. Use slow and fast pointers, starts from 1st and 2nd nodes
    //   2. If slow and fast are at same node, there is a cycle
    //   3. If slow and fast are at different nodes, no cycle yet, 
    //      so flow will go to next node, and fast will go to next next node
    //   4. Stop while loop when fast or fast->next is NULL, that means there
    //      is no cycle in this linked list
    bool hasCycle(ListNode *head) {
        // nullptr head, no cycle
        if (head == NULL) {
            return false;
        }

        // define starting point from the beginning
        ListNode* slow = head;
        ListNode* fast = head->next;

        // if fast == nullptr or fast->next == nullptr, stop
        while (fast != NULL && fast->next != NULL) {
            if (fast == slow) {
                // detect cycle
                return true;
            } else {
                // slow will take 1 step, fast will take 2 steps
                slow = slow->next;
                fast = fast->next->next;
            }
        }
        return false;
    }
};


class Solution99 {
public:
    // 2022.5.30, from soulmachine
    //   1. The solution eliminates such null head or sinle node check
    //      and put such check into while loop, so it will take care of 
    //      NULL head or single node condition
    //   2. The first thing into while loop is to set next node, then 
    //      check if slow and fast pointers are at same node or not
    bool hasCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        
        return false;
    }
};


class Solution98 {
public:
    // 2022.6.5, from AcWing https://www.acwing.com/video/1513/
    bool hasCycle(ListNode *head) {
        // if NULL head or no next, no loop for sure
        if (!head || !head->next) return false;

        // define slow and fast pointers, here it uses fast pointer
        // start from head->next, so there is no need to do above
        // next->next check
        auto s = head, f = head->next;
        
        while (f) {
            s = s->next, f = f->next;

            // if fast pointer reaches NULL pointer, end
            // it also prepares for next statement, which
            // will do f->next, in case of NULL pointer
            if (!f) return false;

            // here is tricky part, fast pointer will go next
            // but slow will not until next iteration
            f = f->next;

            // if fast and slow are same, cycle detected
            if (s == f) return true;
        }

        return false;
    }
};


class Solution97 {
public:
    // 2022.6.8, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/linked-list-cycle.cpp
    // Time:  O(n)
    // Space: O(1)
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next, fast = fast->next->next;
            if (slow == fast) {  // There is a cycle.
                return true;
            }
        }
        return false;  // No cycle.
    }
};


class Solution96 {
public:
    // 2022.7.25, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0141.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8.md
    /*
        可以使用快慢指针法， 分别定义 fast 和 slow指针，从头结点出发，fast指针每次移动两个节点，slow指针每次移动一个节点，
        如果 fast 和 slow指针在途中相遇 ，说明这个链表有环。为什么fast 走两个节点，slow走一个节点，有环的话，一定会在环内
        相遇呢，而不是永远的错开呢？

        首先第一点： fast指针一定先进入环中，如果fast 指针和slow指针相遇的话，一定是在环中相遇，这是毋庸置疑的。
        那么来看一下，为什么fast指针和slow指针一定会相遇呢？

        可以画一个环，然后让 fast指针在任意一个节点开始追赶slow指针。
        会发现最终都是这种情况， 如下图：

        fast和slow各自再走一步， fast和slow就相遇了
        这是因为fast是走两步，slow是走一步，其实相对于slow来说，fast是一个节点一个节点的靠近slow的，所以fast一定可以和slow重合。

        动画如下：
        141.环形链表
    */
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            // 快慢指针相遇，说明有环
            if (slow == fast) return true;
        }
        return false;
    }
};


class Solution95 {
public:
    // 2022.7.25, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/141.%20Linked%20List%20Cycle
    // OJ: https://leetcode.com/problems/linked-list-cycle/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    bool hasCycle(ListNode *head) {
        ListNode *p = head, *q = head;
        while (q && q->next) {
            p = p->next;
            q = q->next->next;
            if (p == q) return true;
        }
        return false;
    }
};


class Solution94 {
public:
    // 2022.7.25, from https://walkccc.me/LeetCode/problems/0141/
    // Time: O(n)
    // Space: O(1)
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }

        return false;
    }
};


class Solution93 {
public:
    // 2022.7.25, from https://www.guozet.me/leetcode/Leetcode-141-Linked-List-Cycle.html?h=hascycle
    /*
        虽然我刷题不够多，但是还是知道这个经典的检查链表中是否有环的快慢指针方式。设置两个指针，一个快一个慢，
        快的指针一次走两格，慢的指针一次走一格。

        为什么如果有环的话，快的指针一定可以追上慢的指针呢, 难道不会刚好错过么 快的指针一次走两格，慢的指针一次
        走一格，他们的相对速度只差是1个格子，那我们这样分析。如果链表中间有环，那么快的在追到慢的之前的话，他们
        之间之可能相差一个格子或者两个格子：

        如果他们相差一个格子，那么下一步就能够追上
        如果他们相差两个格子，那么两步之后也可以追上。
    */
    bool hasCycle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) return true;
        }
        return false;
    }
};


class Solution92 {
public:
    // 2022.7.27, from https://github.com/MaskRay/LeetCode/blob/master/linked-list-cycle.cc
    bool hasCycle(ListNode *head) {
        set<ListNode *> s;
        while (head && ! s.count(head)) {
            s.insert(head);
            head = head->next;
        }
        return !!head;
    }
};


class Solution {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/141
    /*
        这道题是快慢指针的经典应用。只需要设两个指针，一个每次走一步的慢指针和一个每次走两步的快指针，
        如果链表里有环的话，两个指针最终肯定会相遇。实在是太巧妙了，要是我肯定想不出来。代码如下：
    */
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

