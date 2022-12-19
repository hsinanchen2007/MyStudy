![QQ截图20190724091927.png](https://pic.leetcode-cn.com/336b8ed99e16b43106089f3dd13e1d24c6c64b1866e4a7f5e6de4e15e422f84d-QQ%E6%88%AA%E5%9B%BE20190724091927.png)
```
struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL || head->next == NULL) return head;
    struct ListNode HEAD = {NULL, 0};
    struct ListNode* p1 = head;
    struct ListNode* p2 = &HEAD;
    int n,value;
    while (p1) {
        struct ListNode* tmp = p1;
        for (n = 0,value = p1->val; p1 != NULL && p1->val == value; ++n) //计算值为 value 的节点数量
            p1 = p1->next;
        if (n == 1) {  //节点数量等于1，就加入返回链表
            p2->next = tmp;
            p2 = tmp;
        }
    }
    p2->next = NULL;
    return HEAD.next;
}
```
