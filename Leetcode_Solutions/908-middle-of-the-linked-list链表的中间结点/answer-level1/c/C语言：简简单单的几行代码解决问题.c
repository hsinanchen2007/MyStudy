![QQ截图20190726222745.png](https://pic.leetcode-cn.com/dff8fb74186665e4d66e2d36e9e419ac39f6a5fa3b7cfa0448160c6e909f954c-QQ%E6%88%AA%E5%9B%BE20190726222745.png)
```
struct ListNode* middleNode(struct ListNode* head){
    if (head == NULL || head->next == NULL) return head;
    struct ListNode* fir = head;
    struct ListNode* sec = head->next->next;
    while (sec != NULL) {
        sec = sec->next;
        if (sec == NULL) return fir->next;
        sec = sec->next;
        fir = fir->next;
    }
    return fir->next;
}
```
