### 解题思路
![QQ截图20200408221756.png](https://pic.leetcode-cn.com/dc24eabc493ff2367476c46d82a5eae6997e9f83a608a04ee3320c0ae1cb410d-QQ%E6%88%AA%E5%9B%BE20200408221756.png)
感觉写的挺啰嗦的，能优化的地方请指教


### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int kthToLast(struct ListNode* head, int k){
    struct ListNode* p;
    int count=0;
    p=head;
    while(p){
        p=p->next;
        count++;
    }
    int i=count-k;
    while(i--)
    {
        head=head->next;
    }
    return head->val;
}
```