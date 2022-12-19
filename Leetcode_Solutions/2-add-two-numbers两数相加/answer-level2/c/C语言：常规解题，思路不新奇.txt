![两数相加.png](https://pic.leetcode-cn.com/6cd292faffd6af49f52c8e8d38e84dfeae39a31524227c7955aa0b7623cc270f-%E4%B8%A4%E6%95%B0%E7%9B%B8%E5%8A%A0.png)


```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

方法1：原创，多次尝试的结果。
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carry = 0;
    struct ListNode *head, *l3, *l4, *incre, *p;
    head = l2;
    while (l1 && l2){
        l2 -> val += l1 -> val + carry;
        if (l2 -> val >= 10){
            l2 -> val %= 10;
            carry = 1;
        }
        else
            carry = 0;
        if (l2 -> next == NULL){
            l3 = l2;//l3指向l2的末尾元素
        }
        l1 = l1 -> next;
        l2 = l2 -> next;
    }
    if (l1){//l1长于l2
        p = l1;
        while (l1){
            l1 -> val += carry;
            if (l1 -> val >= 10){
                l1 -> val %= 10;
                carry = 1;
            }
            else
                carry = 0;
            if (l1 -> next == NULL)
                l4 = l1;
            l1 = l1 -> next;
        }
        if (carry){
            incre =(struct ListNode*)malloc(sizeof(struct ListNode));
            incre -> val = 1;
            //头插法的运用
            incre -> next = l4 -> next;
            l4 -> next = incre;
        }   
        l3 -> next = p;
    }
    else if(l2){//l2长于l1
        while (l2){
            l2 -> val += carry;
            if (l2 -> val >= 10){
                l2 -> val %= 10;
                carry = 1;
            }
            else
                carry = 0;
            if (l2 -> next == NULL)
                l4 = l2;
            l2 = l2 -> next;
        }
        if (carry){
            incre =(struct ListNode*)malloc(sizeof(struct ListNode));
            incre -> val = 1;
            incre -> next = l4 -> next;
            l4 -> next = incre;
        }   
    }
    else{//l1和l2一样长
        if (carry){
            incre =(struct ListNode*)malloc(sizeof(struct ListNode));
            incre -> val = 1;
            incre -> next = l3 -> next;
            l3 -> next = incre;
        }
    }
    return head;
}


```
方法2（学习题解区方法）：时空效率低一些，但代码更好编写。
```
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head, *q, *l3;
    q = (struct ListNode*)malloc(sizeof(struct ListNode));
    int carry = 0, flg = 1;
    
    while (l1 || l2){
        int x = (l1 == NULL) ? 0 : l1 -> val;
        int y = (l2 == NULL) ? 0 : l2 -> val;
        l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
        l3 -> next = NULL;
        if (flg){
            head = l3;
            flg = 0;
        }
        l3 -> val = x + y + carry;
        if (l3 -> val >= 10){
            l3 -> val %= 10;
            carry = 1;
        }
        else
            carry = 0;
        //尾插法的运用
        q -> next = l3;
        q = l3;
        l1 = (l1 != NULL) ? l1 -> next : NULL;
        l2 = (l2 != NULL) ? l2 -> next : NULL;
    }
    if (carry){
        l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
        l3 -> val = 1;
        l3 -> next = NULL;
        q -> next = l3;
    }
    return head;
}
```
方法3（递归）：总给人神奇的感觉，大道至简！
```
int c = 0;
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL && l2 == NULL && c == 0)
        return NULL;
    l1 != NULL ? (c += l1 -> val, l1 = l1 -> next) : (c += 0);
    l2 != NULL ? (c += l2 -> val, l2 = l2 -> next) : (c += 0);
    struct ListNode *cur = (struct ListNode *)malloc(sizeof(struct ListNode));
    cur ->val = c % 10;
    c = c / 10;
    cur -> next = addTwoNumbers(l1, l2);
    return cur;
}
```

