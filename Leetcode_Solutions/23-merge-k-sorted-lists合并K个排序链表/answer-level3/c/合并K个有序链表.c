思路
1、以头结点值最小的链表为基准链表进行两个链表合并
2、采用归并思想，首尾链表合并，直到合并完成
![image.png](https://pic.leetcode-cn.com/22e44e87a490f70246c21ab1f175772add14021e2a65912201a71a7bf13b1261-image.png)


```
static void mergeTwoList(struct ListNode* baselist, struct ListNode* listTwo){
    struct ListNode* list1 = baselist;
    struct ListNode* list2 = listTwo;
    while(list2 != NULL){
        struct ListNode* lastNode = list1;
        struct ListNode* curNode = lastNode->next;
        struct ListNode* nextList1Node = NULL;
        while(curNode != NULL) {
            if(curNode->val < list2->val){
                lastNode = curNode;
                curNode = curNode->next;
            } else {
                   lastNode->next = list2;
                   nextList1Node = list2->next;
                   list2->next = curNode;
                   list1 = list2;
                   break;   
            }
        }
        if(curNode == NULL && list2 != NULL) {
              lastNode->next = list2;
              nextList1Node = list2->next;
              list2->next = curNode;
              list1 = list2;
        }
        list2 = nextList1Node;
    }
}
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
    struct ListNode* headNode;
    if(l1->val <= l2->val) {
        headNode = l1;
        mergeTwoList(headNode, l2);
    }
    else {
        headNode = l2;
        mergeTwoList(headNode, l1);
    }
    return  headNode;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(lists == NULL || listsSize <= 0) {
        return NULL;
    }
    if(listsSize == 1) {
        return lists[0];
    }
    struct ListNode* baselist;
    int n = listsSize;
    while (n > 1) {
        for (int i = 0; i < n/2; i++) {
            baselist = mergeTwoLists(lists[i], lists[n - i - 1]);
            lists[i] = baselist;
        }
        n = n % 2 == 0 ? n / 2 : n / 2 + 1;
    }
    return baselist;
# }
```
