如下所示，代码比较长，单数之和最大进位是1， 所以我们用 k = 1 或者 0 去记录进位的值，并与下一位数进行相加，生成新的数赋值给L1,并赋值 k的新进位值，直到某一个链表遍历完成，其余部分拼接到L1，继续遍历，需要注意的是遍历完成后，还需要看是否要进位，对链接进行溢出处理。

```

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

```

```cpp
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
  int k = 0;
  struct ListNode* l1Head = l1;
  struct ListNode* l2Head = l2;
  
  struct ListNode* temp = l1;
  
  while (l1Head) {
    
    int a1 = l1Head ? l1Head->val : 0;
    int a2 = l2Head ? l2Head->val : 0;
    int a = a1 + a2 + k;
    
    if (a >= 10) {
     k = 1;
     a = a%10;
    } else {
      k = 0;
    }
    
    l1Head->val = a;
    
    temp = l1Head;
    l1Head = temp->next;
   
    if (l2Head) {
      l2Head = l2Head->next;
    }
    
    if (l1Head == NULL  && l2Head != NULL){  
      (*temp).next = l2Head;
      l1Head = temp->next;
      l2Head = NULL;
    }
     
  }
  //! 溢出，则需要新建一个节点
  if (k > 0) {    
    struct ListNode* lastHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    lastHead->next = NULL;
    lastHead->val = k;
    temp->next = lastHead;
  }
  
  
  return l1;
  
}

```