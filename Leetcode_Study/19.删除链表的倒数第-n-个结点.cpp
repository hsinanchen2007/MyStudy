/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

/*

https://leetcode.cn/problems/remove-nth-node-from-end-of-list/

19. 删除链表的倒数第 N 个结点

中等
2.4K
company
字节跳动
company
亚马逊
company
谷歌 Google

给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

示例 1：

输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]

示例 2：

输入：head = [1], n = 1
输出：[]

示例 3：

输入：head = [1,2], n = 1
输出：[1] 

提示：

链表中结点的数目为 sz
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 
进阶：你能尝试使用一趟扫描实现吗？

*/

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution100 {
public:
    // 2023.2.21, from https://www.acwing.com/activity/content/code/content/346852/
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        auto dummy = new ListNode(-1);
        dummy->next = head;

        int n = 0;
        for (auto p = dummy; p; p = p->next) n ++ ;

        auto p = dummy;
        for (int i = 0; i < n - k - 1; i ++ ) p = p->next;
        p->next = p->next->next;

        return dummy->next;
    }
};


class Solution99 {
public:
    // 2023.2.21, from https://walkccc.me/LeetCode/problems/0019/
    // Time: O(n)
    // Space: O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (n--)
        fast = fast->next;
        if (fast == nullptr)
        return head->next;

        while (fast->next) {
        slow = slow->next;
        fast = fast->next;
        }
        slow->next = slow->next->next;

        return head;
    }
};


class Solution98 {
public:
    // 2023.2.21, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/19.%20Remove%20Nth%20Node%20From%20End%20of%20List
    // OJ: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *q = head;
        while (n--) q = q->next;
        if (!q) return head->next;
        while (q->next) {
            p = p->next;
            q = q->next;
        }
        p->next = p->next->next;
        return head;
    }
};


class Solution97 {
public:
    // 2023.2.21, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/remove-nth-node-from-end-of-list.cpp
    // Time:  O(n)
    // Space: O(1)
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy{0};
        dummy.next = head;
        auto slow = &dummy;
        auto fast = &dummy;

        // fast is n-step ahead.
        while (n > 0) {
            fast = fast->next;
            --n;
        }

        // When fast reaches the end, slow must be nth to last node.
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        auto node_to_delete = slow->next;
        slow->next = slow->next->next;
        delete node_to_delete;

        return dummy.next;
    }
};


class Solution96 {
public:
    // 2023.2.21, from https://github.com/grandyang/leetcode/issues/19
    /*
        这道题让我们移除链表倒数第N个节点，限定n一定是有效的，即n不会大于链表中的元素总数。还有题目要求一次遍历解决问题，
        那么就得想些比较巧妙的方法了。比如首先要考虑的时，如何找到倒数第N个节点，由于只允许一次遍历，所以不能用一次完整的
        遍历来统计链表中元素的个数，而是遍历到对应位置就应该移除了。那么就需要用两个指针来帮助解题，pre 和 cur 指针。首先 
        cur 指针先向前走N步，如果此时 cur 指向空，说明N为链表的长度，则需要移除的为首元素，那么此时返回 head->next 即可，
        如果 cur 存在，再继续往下走，此时 pre 指针也跟着走，直到 cur 为最后一个元素时停止，此时 pre 指向要移除元素的前
        一个元素，再修改指针跳过需要移除的元素即可，参见代码如下：    
    */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) return NULL;
        ListNode *pre = head, *cur = head;
        for (int i = 0; i < n; ++i) cur = cur->next;
        if (!cur) return head->next;
        while (cur->next) {
            cur = cur->next;
            pre = pre->next;
        }
        pre->next = pre->next->next;
        return head;
    }
};


class Solution95 {
public:
    // 2023.2.21, from https://zxi.mytechroad.com/blog/?s=LeetCode+19.
    // Solution 0: Cheating! store the nodes in an array
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head) return nullptr;
        vector<ListNode *> nodes;
        ListNode *cur = head;
        while (cur) {
            nodes.push_back(cur);
            cur = cur->next;
        }
        if (n == nodes.size()) return head->next;
        ListNode* nodes_to_remove = nodes[nodes.size()-n];
        ListNode* parent = nodes[nodes.size() - n - 1];
        parent->next = nodes_to_remove->next;
        delete nodes_to_remove;
        return head;
    }
};


class Solution94 {
public:
    // 2023.2.21, from https://zxi.mytechroad.com/blog/?s=LeetCode+19.
    // Author: Huahua
    // Solution 1: Two passes
    // Time complexity: O(L)
    // Space complexity: O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = 0;
        ListNode* cur = head;
        while (cur) {
            ++l;
            cur = cur->next;
        }
        if (n == l) {
            ListNode* ans = head->next;
            delete head;
            return ans;
        }    
        l -= n;
        cur = head;
        while (--l) cur = cur->next;
        ListNode* node = cur->next;
        cur->next = node->next;
        delete node;
        return head;
    }
};


class Solution93 {
public:
    // 2023.2.21, from https://zxi.mytechroad.com/blog/?s=LeetCode+19.
    // Author: Huahua
    // Solution 2: Fast/Slow Pointers + Dummy Head / Prev
    // Fast pointer moves n steps first, and then slow pointer starts moving.
    // When fast pointer reaches tail, slow pointer is n-th node from the end.
    // Time complexity: O(L)
    // Space complexity: O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        for (int i = 0; i < n; ++i) 
            fast = fast->next;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        while (fast) {
            fast = fast->next;
            prev = prev->next;
        }
        ListNode* node = prev->next;
        prev->next = node->next;
        delete node;
        return dummy.next;
    }
};


class Solution92 {
public:
    // 2023.2.21, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0019.%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E5%80%92%E6%95%B0%E7%AC%ACN%E4%B8%AA%E8%8A%82%E7%82%B9.md
    /*
        思路
        《代码随想录》算法公开课：链表遍历学清楚！ | LeetCode：19.删除链表倒数第N个节点，相信结合视频在看本篇题解，
        更有助于大家对链表的理解。双指针的经典应用，如果要删除倒数第n个节点，让fast移动n步，然后让fast和slow同时移动，
        直到fast指向链表末尾。删掉slow所指向的节点就可以了。

        思路是这样的，但要注意一些细节。

        分为如下几步：

        首先这里我推荐大家使用虚拟头结点，这样方便处理删除实际头结点的逻辑，如果虚拟头结点不清楚，可以看这篇： 链表：
        听说用虚拟头节点会方便很多？
        定义fast指针和slow指针，初始值为虚拟头结点，如图：

        fast首先走n + 1步 ，为什么是n+1呢，因为只有这样同时移动的时候slow才能指向删除节点的上一个节点（方便做删除操作），
        如图： 

        fast和slow同时移动，直到fast指向末尾，如题： 

        删除slow指向的下一个节点，如图： 

        此时不难写出如下C++代码：    
    */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        while(n-- && fast != NULL) {
            fast = fast->next;
        }
        fast = fast->next; // fast再提前走一步，因为需要让slow指向删除节点的上一个节点
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next; 
        
        // ListNode *tmp = slow->next;  C++释放内存的逻辑
        // slow->next = tmp->next;
        // delete nth;
        
        return dummyHead->next;
    }
};


class Solution {
public:
    // 2023.2.21, from https://github.com/azl397985856/leetcode/blob/master/problems/19.removeNthNodeFromEndofList.md
    /*
        思路
        这里我们可以使用双指针算法，不妨设为指针 A 和 指针 B。指针 A 先移动 n 次， 指针 B 再开始移动。当 A 到达 null 的时候， 
        指针 B 的位置正好是倒数第 n。这个时候将 B 的指针指向 B 的下下个指针即可完成删除工作。

        算法：

        设置虚拟节点 dummyHead 指向 head（简化判断，使得头结点不需要特殊判断）
        设定双指针 p 和 q，初始都指向虚拟节点 dummyHead
        移动 q，直到 p 与 q 之间相隔的元素个数为 n
        同时移动 p 与 q，直到 q 指向的为 NULL
        将 p 的下一个节点指向下下个节点

        19.removeNthNodeFromEndOfList

        (图片来自： https://github.com/MisterBooo/LeetCodeAnimation)

        关键点解析
        链表这种数据结构的特点和使用

        使用双指针

        使用一个 dummyHead 简化操作    
    */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *q = head;
        while (n--) q = q->next;
        if (!q) {
            head = head->next;
            delete p;
            return head;
        }
        while (q->next) p = p->next, q = q->next;
        q = p->next;
        p->next = q->next;
        delete q;
        return head;
    }
};


// @lc code=end

