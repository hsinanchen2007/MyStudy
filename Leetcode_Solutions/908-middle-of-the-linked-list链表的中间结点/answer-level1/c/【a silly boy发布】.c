![DB705703-0E1D-48D2-984B-7AED2FF74843.jpeg](https://pic.leetcode-cn.com/cf8a6a7a184c5aec433912a1c5315ed279906d188cc715c527843e3b293f6dfa-DB705703-0E1D-48D2-984B-7AED2FF74843.jpeg)

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    int i = 0;
    int pos;
    struct ListNode *listNodeCpy = head;
    int listNodeNum = 0;
    while (listNodeCpy != NULL) {
        listNodeCpy = listNodeCpy->next;
        listNodeNum++;
    }
    if (listNodeNum == 0) {
        return NULL;
    }
    if (listNodeNum % 2 == 0) {
        //4 4/2 + 1 = 2 + 1 =3
        pos = listNodeNum / 2;
    } else {
        pos = listNodeNum / 2;
    }

    for (i = 0; i < pos; i++) {
        head = head->next;
    }
    
    return head;
}
```
