/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
 */

/*

https://leetcode.cn/problems/middle-of-the-linked-list/

876. 链表的中间结点

简单
801
company
亚马逊
company
谷歌 Google
company
Facebook

给你单链表的头结点 head ，请你找出并返回链表的中间结点。

如果有两个中间结点，则返回第二个中间结点。

示例 1：

输入：head = [1,2,3,4,5]
输出：[3,4,5]
解释：链表只有一个中间结点，值为 3 。

示例 2：

输入：head = [1,2,3,4,5,6]
输出：[4,5,6]
解释：该链表有两个中间结点，值分别为 3 和 4 ，返回第二个结点。
 
提示：

链表的结点数范围是 [1, 100]
1 <= Node.val <= 100

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
    // 2023.2.21, from https://www.acwing.com/activity/content/code/content/1247032/
    ListNode* middleNode(ListNode* head) {
        auto p = head, q = head;
        while (q && q->next) {
            p = p->next;
            q = q->next->next;
        }
        return p;
    }
};


class Solution99 {
public:
    // 2023.2.21, from https://walkccc.me/LeetCode/problems/0876/
    // Time: O(n)
    // Space: O(1)
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};


class Solution98 {
public:
    // OJ: https://leetcode.com/problems/middle-of-the-linked-list/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    ListNode* middleNode(ListNode* head) {
        auto slow = head, fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};


class Solution97 {
public:
    // 2023.2.21, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/middle-of-the-linked-list.cpp
    // Time:  O(n)
    // Space: O(1)
    ListNode* middleNode(ListNode* head) {
        auto slow = head, fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};


class Solution96 {
public:
    // 2023.2.21, from https://github.com/grandyang/leetcode/issues/876
    /*
        这道题给了一个链表，让我们找其中间结点。由于链表不像数组，不能通过坐标位置来直接访问元素，而是只能从头结点开始，
        使用 next 指针来访问之后的结点，为了知道当前结点的位置，还得使用计数器来记录。由于在不知道链表的总长度之前，是无
        法知道中间结点的位置的，那么可以首先遍历一遍，统计出链表的长度，此时长度有了，除以2就是中间结点的位置了，再从头
        遍历一遍，就可以找出中间结点的位置了，参见代码如下：
        解法一：    
    */
    ListNode* middleNode(ListNode* head) {
		ListNode *cur = head;
        int cnt = 0;
		while (cur) {
			++cnt;
            cur = cur->next;
		}
        cnt /= 2;
        while (cnt > 0) {
            --cnt;
            head = head->next;
        }
		return head;
    }
};


class Solution95 {
public:
    // 2023.2.21, from https://github.com/grandyang/leetcode/issues/876
    /*
        由于链表无法通过坐标位置来访问元素，但我们可以将所有的结点按顺序存入到一个数组中，那么之后就可以直接根据坐标位置
        来访问结点了，参见代码如下：
        解法二：    
    */
    ListNode* middleNode(ListNode* head) {
		vector<ListNode*> vec(100);
        int cur = 0;
        while (head) {
            vec[cur++] = head;
            head = head->next;
        }
        return vec[cur / 2];
    }
};


class Solution94 {
public:
    // 2023.2.21, from https://github.com/grandyang/leetcode/issues/876
    /*
        上面两种方法一个多用了时间，一个多用了空间，其实都不是最优的解法，最好的方法其实是使用快慢指针来做。在之前那道 
        Linked List Cycle 链表中找环的题，我们介绍过快慢指针，就是两个指针，慢指针一次走一步，快指针一次走两步，那么
        这里当快指针走到末尾的时候，慢指针刚好走到中间，这样就在一次遍历中，且不需要额外空间的情况下解决了问题，参见代
        码如下：
        解法三：    
    */
    ListNode* middleNode(ListNode* head) {
		ListNode *slow = head, *fast = head;
		while (head && head->next) {
			slow = slow->next;
			head = head->next->next;
		}
		return slow;
    }
};


class Solution93 {
public:
    // 2023.2.21, from https://zxi.mytechroad.com/blog/?s=LeetCode+876.
    // Author: Huahua
    // Running time: 0 ms
    ListNode* middleNode(ListNode* head) {
        if (!head || !head->next) return head;
        auto slow = head;
        auto fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};


class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        // 设置两个指针，一开始都指向链表的头节点
        ListNode* slow = head;

        ListNode* fast = head;

        // 接下来，让这两个指针向前移动
        // 如果可以移动，那么就会让快指针每次移动两步，慢指针每次移动一步
        // 而快指针可以移动两步的前提就是当前节点不为空，同时下一节点也不为空
        // 这样才能保证 fast.next 有值、fast.next.next 有值
        while(fast != NULL && fast->next != NULL){

            // 慢指针每次移动一步
            slow = slow->next;

            // 快指针每次移动两步
            fast = fast->next->next;
        }

        // 最后，slow 指向的就是中间节点
        return slow;

    }
};


// @lc code=end
