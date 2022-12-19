
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
        ListNode* l = head;
        ListNode* r = head;
        int len = 1;
        bool flg = true; 
        //让两个指针间的间隔为k
        while(k > 0)
        {
            r = r->next;
            k--;
            // 处理k大于链表长度的情况
            if(r == NULL) 
            {
                r = head;
                k = k % len;
                flg = false;
            }
            if(flg) len++;
        }
        //不断向后移动l与r指针，保持间隔不变。当r指针指向链表末尾时，l指针的位置正是需要截断的node之前
        while(r->next != NULL)
        {
            l = l->next;
            r = r->next;
        }
        //截断
        r->next = head;
        head = l->next;
        l->next = NULL;
        return head;
    }
};
```
![屏幕快照 2019-12-27 08.55.58.png](https://pic.leetcode-cn.com/62b5296033a17724ec63c7a04411d0313c3b1ca300bdc7f9f2c06be43c06afc1-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-12-27%2008.55.58.png)

