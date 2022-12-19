### 解题思路
1.遍历，得到表长，将k对表长取余；
2.取相隔k个节点的两个指针，同时移动直到后者到达表尾，此时前者即为断点，外加pre辅助指针；
3.原表首尾相接，定义新表头，pre处断开。
![捕获.PNG](https://pic.leetcode-cn.com/1662dc052bb27bd2057f555b9840ad2a0835d2956bee080204a23f089fc5ae20-%E6%8D%95%E8%8E%B7.PNG)

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head; //空链表或只有一个节点的链表，直接返回
        int len = 0, count;
        ListNode* p = head, *pre;
        while(p) //遍历得到表长
        {
            p = p->next;
            len++;
        }
        k = k % len; 
        if(k == 0) return head; //若k为表长倍数，也直接返回
        pre = head; p = head;
        while(k--) p = p->next; //p移动到第k个节点处
        while(p->next) //当p到达尾节点时，pre即为断点
        {
            pre = pre->next; p = p->next;
        }
        p->next = head; //首尾相接
        head = pre->next; //新表头
        pre->next = NULL; //断开
        return head;
    }
};
```