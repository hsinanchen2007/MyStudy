思路：两个有序链表的合并，重点就在于比较元素的大小。本文利用向量进行排序，简单不易出错。
1、首先应该考虑到链表为空的情况；
2、将两个链表的元素放到向量中，直接排序，之后再放回链表中即可。

```c
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        std::vector<int> vec;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        if (p1 == NULL){
            return p2;
        }
        if(p2 == NULL){
            return p1;
        }
        while(p1 != NULL){
            vec.push_back(p1->val);
            p1 = p1->next;
        }
        while(p2 != NULL){
            vec.push_back(p2->val);
            p2 = p2->next;
        }
        sort(vec.begin(), vec.end());
        p1 = l1;
        for(int i = 0;i < vec.size(); i++){
            if(p1 == NULL){
                p1 = l2;
            }
            p1->val = vec[i];
            p1 = p1->next;
        }
        return l1;
    }
};
```

官方题解：递归思想

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL){
            return l2;
        }
        else if(l2 == NULL){
            return l1;
        }
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
};
```
