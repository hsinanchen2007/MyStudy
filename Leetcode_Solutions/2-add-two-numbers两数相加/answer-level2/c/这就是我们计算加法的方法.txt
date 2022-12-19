这个倒叙方法刚好是我们加法求和的计算思路，我们都是从低位向高位计算的，并进位。基本思路就是：
1. 同时遍历链表，只要有一个不为空（两个链表长度不一样）都要计算，此时为空的链表对应结点使用零代替；
2. 同一结点相加，所得新结点的值为最低位，高位进位（用于下一个结点计算）。
3. 直到链表都为空，则判断是不是还存在进位的情况，存在则重新新增一个结点。

代码如下：
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* pSumList = NULL;
    struct ListNode* pNode; 
    struct ListNode* p1 = l1;    
    struct ListNode* p2 = l2;
    struct ListNode* pInsert;

    int highbit;
    pNode = malloc(sizeof(struct ListNode));
    pNode->val = (p1->val + p2->val) % 10;
    highbit = (p1->val + p2->val) / 10;
    pNode->next = NULL;
    pSumList = pNode;
    pInsert = pNode;

    p1 = p1->next;
    p2 = p2->next;

    while ((p1 != NULL) || (p2 != NULL)) {
        pNode = malloc(sizeof(struct ListNode));
        if (p1 != NULL) {
            if (p2 != NULL) {
                pNode->val = (p1->val + p2->val + highbit) % 10;
                highbit = (p1->val + p2->val + highbit) / 10;
                p1 = p1->next;
                p2 = p2->next;
            } else {
                pNode->val = (p1->val + highbit) % 10;
                highbit = (p1->val + highbit) / 10;
                p1 = p1->next;
            }
        } else {
            if (p2 != NULL) {
                pNode->val = (p2->val + highbit) % 10;
                highbit = ( p2->val + highbit) / 10;
                p2 = p2->next;
            }         
        }
        pNode->next = NULL;
        pInsert->next = pNode;
        pInsert = pNode;
    }

    if (highbit) {
        pNode = malloc(sizeof(struct ListNode));
        pNode->val = highbit;
        pNode->next = NULL;
        pInsert->next = pNode;
        pInsert = pNode;
    }
    
    return pSumList;
}