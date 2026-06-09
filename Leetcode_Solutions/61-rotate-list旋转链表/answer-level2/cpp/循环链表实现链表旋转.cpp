- 将链表的最后一个元素的next指向链表头部，形成单向链表
- 时间复杂度：O(N)，需要遍历一遍链表
- 空间复杂度：O(1)，只用到两个指针
**需要注意：**
1. 循环链表中，指针的移动相当于逆时针，而向右旋转是顺时针，两个方向是反的
2. 对于k>size的情况，实际需要循环的次数是在[0, size]内，size是链表的大小
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }
        ListNode* cur = head;
        int size = 1;
        while(cur->next != NULL){   //得到链表中最后一个元素的位置，以及链表的大小
            cur = cur->next;
            size++;
        }
        cur->next = head;   //构成一个循环链表

        int n = size - k % size;
        //这儿有两个意思：
        //1. 循环链表中，指针的移动相当于逆时针，而向右旋转是顺时针，两个方向是反的
        //2. 对于k>size的情况，实际需要循环的次数是在[0, size]内

        while(n>0){
            head = head->next;
            cur = cur->next;
            n--;
        }
        cur->next = NULL;
        return head;

    }
};
```
