### 解题思路
1. 计数节点
2. 获取中间节点

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
    struct ListNode* res = head;
    struct ListNode* temp = head;
    int count = 0;
    
    // 节点计数
    while(temp){
        count++;
        temp = temp -> next;
    }
    
    // 中间节点获取
    count /= 2;
    for (int i=0; i<count; i++){
        res = res->next;
    }
    return res;
}
```