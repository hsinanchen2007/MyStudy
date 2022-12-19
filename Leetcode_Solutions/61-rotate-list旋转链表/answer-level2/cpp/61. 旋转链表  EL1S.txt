![image.png](https://pic.leetcode-cn.com/f1e4049dcd889113b3d03f2d6359595848671302d6881dd7fd4e898786c0fe1e-image.png)

把链表的尾部和头部连一起，方便查找
然后根据位置的关系找出来新的尾部，新的尾部的下一个就是新的头部
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
        if(!head) return head;
        auto h = head, tail = head;
        int len = 0;
        while(tail->next) 
        {
            tail = tail->next;
            len++;
        }
        len++;


        k = k % len;
        if(k == 0) return head;

        tail->next = h;
        int move = len - k - 1;//向前移动idx找tail
        tail = h;
        while(move--)
            tail = tail->next;
        h = tail->next;
        tail->next= nullptr;
        return h;

    }
};
```
