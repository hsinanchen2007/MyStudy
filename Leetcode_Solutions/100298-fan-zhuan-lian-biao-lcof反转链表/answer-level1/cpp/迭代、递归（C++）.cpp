# 迭代
1. 创建新的空链表（res=NULL）；
2. 从头依次遍历原链表（head），利用tmp指针记录当前节点，将其 ***头插法*** 插入到新链表中；
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
    ListNode* reverseList(ListNode* head) {
        ListNode *res, *tmp;
        res = NULL;
        while(head){
            tmp = head;
            head = head->next;
            tmp->next = res;
            res = tmp;
        }
        return res;
    }
};
```

# 递归
1. 递归终止条件：(head == NULL) || (head->next==NULL)
2. 递归对象：head->next；
3. 递归过程：head->next->next = head;  head->next = NULL;
图示：
![23851583155229_.pic_hd.jpg](https://pic.leetcode-cn.com/413ad08c900bd9775682c7f1b7b8104af27b2d94495113f8c8229594b18a02be-23851583155229_.pic_hd.jpg)


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
    ListNode* reverseList(ListNode* head) {
        if((head == NULL) || (head->next==NULL)){
            return head;
        }
        ListNode *newhead;
        newhead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
};
```

