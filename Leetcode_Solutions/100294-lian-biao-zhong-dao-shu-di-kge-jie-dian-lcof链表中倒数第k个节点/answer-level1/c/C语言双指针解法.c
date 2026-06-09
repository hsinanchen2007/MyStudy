### 解题思路
上一个解法是算长度的解法，这个是双指针解法的C语言实现，具体思路可以看前面题解的动画，非常巧妙的解法。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    struct ListNode *former = head;
	struct ListNode *latter = head;
	for (int i = 0; i < k; i++)
	{
		former = former->next;
	}
	while (former!=NULL)
	{
		former = former->next;
		latter = latter->next;
	}
	return latter;
}
```