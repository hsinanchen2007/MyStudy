### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    int len = n - m + 1;//计算出需要逆置的个数
    struct ListNode *pre = NULL;
    struct ListNode *res = head;
    while(--m && head){
        pre = head;
        head = head->next;//将head向前移动到需要逆置的位置
    }
    struct ListNode *mod = head;
    struct ListNode *new = NULL;
    while(head && len){
        struct ListNode *next = head->next;
        head->next = new;//逆置节点
        new = head;
        head = next;
        len--;//每完成一个，需要的个数减1
    }
    mod->next = head;//连接逆置段的尾部与原链表不需要逆置尾部
    if(pre){
        pre->next = new;//如果pre不为空，说明不是从第一个开始的，则将前半段不逆置的与逆置的链接起来
    }else{
        res = new;//说明从第一个开始，直接链头
![捕获.PNG](https://pic.leetcode-cn.com/bf7ce7411dc550c50b0326b149621c45102e3eae2f7fd7374605b4ba16e086ba-%E6%8D%95%E8%8E%B7.PNG)
    }
    return res;
}
```