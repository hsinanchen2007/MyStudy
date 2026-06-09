### 迭代

![截屏2020-03-02下午10.45.57.png](https://pic.leetcode-cn.com/dbede33d92d704199f407affb15166b4c35f5abad636eb2efb5ba64792596e81-%E6%88%AA%E5%B1%8F2020-03-02%E4%B8%8B%E5%8D%8810.45.57.png)

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL || head->next == NULL) return head;
    struct ListNode * p = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;    
    return p;
}
```

### 回归
* 对于下一个或者自身为NULL的节点执行返回，此返回值为逆转后的头部
* 对于中间节点：使自己的下一个节点指向自己；使自己指向的节点为空；返回头部值；

### 代码
```struct ListNode* reverseList(struct ListNode* head){
	if(head == NULL || head->next == NULL) return head;
	struct ListNode * p = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;    
	return p;
```