### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *node1 = headA;
        ListNode *node2 = headB;
        
        while (node1 != node2) {
            node1 = (node1 != NULL) ? node1->next : headB;
            //链表1向后遍历直到结束后 跳到链表2头结点 
            node2 = (node2 != NULL) ? node2->next : headA;
            //链表2向后遍历直到结束后 跳到链表1头结点
        } //相遇 得到解
        return node1;
    }
};

//作者：z1m
//链接：https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/solution/shuang-zhi-zhen-fa-lang-man-xiang-yu-by-ml-zimingm/
//来源：力扣（LeetCode）

//浪漫相遇法 
```