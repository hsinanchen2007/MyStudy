思路：先遍历链表长度，为n，如果k%n == 0其实不用移动直接返回，如果不为0，则k = k - (k%n)，向左移动k次

![image.png](https://pic.leetcode-cn.com/baf81fefe8a159df094928f51f7858ad8258d51af7ca38aaf1b268335657e2b2-image.png)


```
ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL) {
        return head;
    }
    int length = 0;
    ListNode* p = head;
    while (p) {
        length++;
        p = p->next;
    }
    k = k % length;
    if (k == 0) {
        return head;
    }
    k = length - k;
    for (int i = 0; i < k; i++) {
        p = head;
        int val = p->val;
        while (p->next) {
            p->val = p->next->val;
            p = p->next;
        }
        p->val = val;
    }
    return head;
}
```

欢迎关注算法微信公众号'码农黑板报', 一起学习交流更多算法题解