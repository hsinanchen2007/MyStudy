### 解题思路
方法1: 遍历两编，第一遍求出n,第二遍找到第n-k+1个节点
方法2: 递归至尾部，再计数k--，直到k==1弹出
方法3:恒差双指针，先移动出差额(要求的数)，再同步遍历直至右节点q到尾部，返回左节点p。
ps:总结一下目前遇到的双指针法。
    双指针法：
        1.**相邻**双指针————单链表*逆序*
        2.**二倍速**双指针————找*对称*中心结点/形成对称链表/对称链表取一半
        3.**恒差**双指针————找*倒数*第K个结点

### 代码
方法3：恒差双指针
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    //双指针，两倍，恒差
    if(k<=0||head==NULL)return NULL;
    struct ListNode *p=head,*q=head;
    while(q->next!=NULL){           //q最终指向最后一个节点
        q=q->next;
        k>1?k--:(p=p->next);        //k最终等于1
    }
    return p;
}
```
时间复杂度O(N),空间复杂度O(1)