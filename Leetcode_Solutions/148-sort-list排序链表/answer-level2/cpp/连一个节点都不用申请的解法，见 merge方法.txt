### 解题思路

 // 思路： 要想排序，就得获取到所有的元素，然后进行排序。一般数组可以方便的进行比较，然后排序，
 // 对于链表要想排序，可以把链表分成两段，每段分别排序，然后拍好序后，再组合起来。

 // 其实最关键的是要想到归并排序： 分成两段，递归排序，合并两端 ==》组成排序好的数组。
 // 分成两段：快慢指针，快的走俩，慢的走一个。当快的到底时，慢的也就走到中间了， 然后断开与上一个的链接，就是第二段了。
 // 递归的去对每段链表排序，这是难点，咋排呢？？？？
 // 合并两段： 这个只要保存好第二段的头指针，第一段的尾指针，不难。
### 代码

```cpp
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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *mid = splitList(head); // 得到中点
        ListNode *left = sortList(head); // 对左右两边开始递归调用排序
        ListNode *right = sortList(mid);

        return merge2(left, right);

    }
    ListNode* splitList(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *pre = NULL; // slow指针的前一个节点
        while ((fast != NULL) && (fast->next != NULL)) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;

        }
        pre->next = NULL; // 让第一个第二个链表断开。
        return slow; // 链表奇数：slow就是最中间的那个。 偶数时:slow是中间两个节点中右边的那个。
        
    }
     // merge2合并，申请了一个空间。
     ListNode* merge2(ListNode* l1, ListNode* l2) {
        ListNode *header = new ListNode(-1);
        ListNode *p = header;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }

        p->next = l1 == NULL ? l2 : l1;

        return header->next;
    }

    // merge方法合并，没申请空间，但是总是超时，不理解为啥？？？？？？？？？？？？？求大佬解答。
    // ListNode *myHead = NULL; // 返回的最终链表头部。
    // ListNode *myHeadTmp = NULL; // 往最终链表添加一个个节点时，此指针不断后移。
    // void append(ListNode *node) { // 用于往链表尾部添加节点
    //     if(myHead != NULL) {
    //         myHeadTmp->next = node;
    //         myHeadTmp = myHeadTmp ->next; // 不断移动，以便添加新的指针
    //     } else {
    //         myHead = node;
    //         myHeadTmp = node;
    //     }
    // }
    // ListNode* merge(ListNode* first, ListNode *second) { // 合并两个有序的链表
    //      while (first != NULL || second != NULL) {
    //         if (first == NULL) { // 说明第一段链表已经全部插入到了lastList, 所以将第二段插入即可。
    //             append(second);
    //             second = second->next;
    //         } else if (second == NULL) {
    //             append(first);
    //             first = first->next;
    //         } else { // 说明两个都不为空。
    //             if(first->val < second->val) {
    //                 append(first);
    //                 first = first->next;
    //             } else { 
    //                 append(second);
    //                 second = second->next;
    //             }
    //         } 
    //      }

    //     return myHead;
    // }
};
```