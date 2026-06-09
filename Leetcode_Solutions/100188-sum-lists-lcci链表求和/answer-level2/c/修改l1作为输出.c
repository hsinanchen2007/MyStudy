把l2串在l1后面，然后进行修改和截断。
![image.png](https://pic.leetcode-cn.com/9c223c49da6e7308420a4ab7d3dab383bc8749cda2c1a7190971e4883ce04145-image.png)


```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode Node;
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    
    Node* p1 = l1;
    Node* p2 = l2;
    Node* p = l1;
    Node* temp = NULL;
    int c = 0;
    int x, y, s;
    bool flag = false;

    while (p1->next)
        p1 = p1->next;
    p1->next = l2;
    p1 = l1;
    while (p1 || p2)
    {
        // if (p1->next == l2)
            // temp = p;
        if (p1 == l2)
            flag = true;
        if (flag && p2 == NULL)
            break;
        if (flag) 
            x = 0;
        else
        {
            x = p1->val; 
            p1 = p1->next;
        }
        if (p2 == NULL) 
            y = 0;
        else 
        {
            y = p2->val; 
            p2 = p2->next;
        }
        s = c + x + y;
        c = s / 10;
        s = s % 10;
        p->val = s;
        temp = p;
        p = p->next; 
    }
    p = temp;
    if (c > 0) 
    {   
        p = p->next;
        p->val = 1;
        p->next = NULL;
    }
    else 
        p->next = NULL;

    return l1;
}
```

