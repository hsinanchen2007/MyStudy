### 解题思路
1.计算列表的长度；
2.分奇数还是偶数，进行返回位的计算；
3.重新遍历，返回

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    int count = 0;
    struct ListNode* tmp = head;
    while (tmp) {
        tmp = tmp->next;
        count++;
    }
    tmp = head;
  
    if (count % 2 == 0)
        count = (count + 1) / 2;
    else
        count = count / 2;

    while (count) {
        tmp = tmp->next;
        count--;
    }
    return tmp;
}
```