/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

/*

https://leetcode.cn/problems/remove-duplicates-from-sorted-list/

83. 删除排序链表中的重复元素

简单
940
company
亚马逊
company
谷歌 Google
company
字节跳动
给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。

示例 1：

输入：head = [1,1,2]
输出：[1,2]

示例 2：

输入：head = [1,1,2,3,3]
输出：[1,2,3] 

提示：

链表中节点数目在范围 [0, 300] 内
-100 <= Node.val <= 100
题目数据保证链表已经按升序 排列

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
    // 2023.2.18, from Labuladong https://labuladong.github.io/algo/di-ling-zh-bfe1b/shuang-zhi-fa4bd/
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL) {
            if (fast->val != slow->val) {
                slow->next = fast;
                slow = slow->next;
            }
            fast = fast->next;
        }
        slow->next = NULL;
        return head;
    }
};


class Solution99 {
public:
    // 2023.2.18, from https://github.com/grandyang/leetcode/issues/83
    /*
        这道题让我们移除给定有序链表的重复项，那么可以遍历这个链表，每个结点和其后面的结点比较，如果结点值相同了，
        只要将前面结点的 next 指针跳过紧挨着的相同值的结点，指向后面一个结点。这样遍历下来，所有重复的结点都会被跳
        过，留下的链表就是没有重复项的了，代码如下：
    */
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head;
        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};


class Solution98 {
public:
    // 2023.2.18, from https://github.com/grandyang/leetcode/issues/83
    /*
        我们也可以使用递归的方法来做，首先判断是否至少有两个结点，若不是的话，直接返回 head。否则对 head->next 调用递归
        函数，并赋值给 head->next。这里可能比较晕，先看后面一句，返回的时候，head 结点先跟其身后的结点进行比较，如果值相
        同，那么返回后面的一个结点，当前的 head 结点就被跳过了，而如果不同的话，还是返回 head 结点。可以发现了，进行实质
        上的删除操作是在最后一句进行了，再来看第二句，对 head 后面的结点调用递归函数，那么就应该 suppose 返回来的链表就
        已经没有重复项了，此时接到 head 结点后面，在第三句的时候再来检查一下 head 是否又 duplicate 了，实际上递归一直走
        到了末尾结点，再不断的回溯回来，进行删除重复结点，参见代码如下：    
    */
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        head->next = deleteDuplicates(head->next);
        return (head->val == head->next->val) ? head->next : head;
    }
};


class Solution97 {
public:
    // 2023.2.18, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/remove-duplicates-from-sorted-list.cpp
    // Time:  O(n)
    // Space: O(1)
    ListNode* deleteDuplicates(ListNode* head) {
        auto iter = head;
        while (iter) {
            auto runner = iter->next;
            while (runner && runner->val == iter->val) {
                runner = runner->next;
            }
            iter->next = runner;
            iter = runner;
        }
        return head; 
    }
};


class Solution96 {
public:
    // 2023.2.18, from https://github.com/lzl124631x/LeetCode/blob/master/leetcode/83.%20Remove%20Duplicates%20from%20Sorted%20List/s1.cpp
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head;
        while (p) {
            ListNode *q = p->next;
            while (q && q->val == p->val) {
                p->next = q->next;
                delete q;
                q = p->next;
            }
            p = p->next;
        }
        return head;
    }
};


class Solution95 {
public:
    // 2023.2.18, from https://walkccc.me/LeetCode/problems/0083/
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while (curr) {
            while (curr->next && curr->val == curr->next->val)
                curr->next = curr->next->next;
            curr = curr->next;
        }

        return head;
    }
};


class Solution {
public:
    // 作者：yxc
    // 链接：https://www.acwing.com/solution/content/167/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    /*
        算法
        (线性扫描) O(n)
    
        从前往后扫描整个链表，如果一个节点和其后继节点相同，则直接删除后继节点，否则指针移动到后继节点。
        时间复杂度分析：整个链表只扫描一遍，所以时间复杂度是 O(n)
    */
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode* p = head;
        while (p->next)
        {
            if (p->val == p->next->val) p->next = p->next->next;
            else p = p->next;
        }
        return head;
    }
};


// @lc code=end

