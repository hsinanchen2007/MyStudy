C语言时间99空间100，难道只有我这种不会高级语言的弱鸡在用c么。。
之前一直测试超出时间限制，后来在一位大佬的题解中看到了断链才想起自己没有做好翻转前后的处理。
每次翻转前要先将待翻转的那一段的尾结点的后继存下来，然后将此段与其断开，翻转后还需要再链接上，因此还需要记录待翻转那段的头，也就是翻转后的尾结点，这样翻转后才能链回去
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//输入为待翻转链表的前一个结点，输出仍为此结点，但链表已翻转
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode *curfront,*cur,*curnext;
    if (head->next == NULL) {
        return NULL;
    }

    curfront = head->next;
    cur = curfront->next;
    curfront->next = NULL;

    while (cur) {
        curnext = cur->next;
        cur->next = curfront;
        curfront = cur;
        cur = curnext;
    }
    head->next = curfront;
    return head;
}
struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode* dummyhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *curfront = NULL,*curnext = NULL,*cur = NULL;
    int i = 1;
    if (head == NULL) return NULL;
    dummyhead->next = head;
    curfront = dummyhead;
    cur = dummyhead->next;

    while (cur) {
        if ((cur = cur->next) == NULL) break;
        if (++i == k) {
            curnext = cur->next;
            cur->next = NULL;//之前漏掉了断开链接这一步
            cur = curfront->next;//存下翻转后的尾
            reverse(curfront);
            cur->next = curnext;//断开链接之后还要链上
            curfront = cur;
            cur = curnext;
            i = 1;
        }
    }

    return dummyhead->next;

    
 }
```
