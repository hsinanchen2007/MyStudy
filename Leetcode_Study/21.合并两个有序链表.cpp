/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

/*

https://leetcode.cn/problems/merge-two-sorted-lists/

21. 合并两个有序链表

简单
2.9K
company
亚马逊
company
Facebook
company
谷歌 Google
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 

示例 1：


输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]

示例 2：

输入：l1 = [], l2 = []
输出：[]

示例 3：

输入：l1 = [], l2 = [0]
输出：[0]
 

提示：

两个链表的节点数目范围是 [0, 50]
-100 <= Node.val <= 100
l1 和 l2 均按 非递减顺序 排列

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
class Solution {
public:
    // 2023.1.22 by Hsin-An
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // sanity check
        if (list1 == NULL && list2 == NULL) return NULL;
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        // check which list node first based on first value, and assign head
        ListNode *head = NULL;
        if (list1->val <= list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }

        // assign curr to head at the beginning
        ListNode *curr = head;

        while (list1 != NULL && list2 != NULL) {
            // check value, next, and assign curr
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        // need to check if any ListNode is not empty
        if (list1 != NULL) {
            curr->next = list1;
        } else {
            curr->next = list2;
        }
        
        return head;
    }
};

// @lc code=end

