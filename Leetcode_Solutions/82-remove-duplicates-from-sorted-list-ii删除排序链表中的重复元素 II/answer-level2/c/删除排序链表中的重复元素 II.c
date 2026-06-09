### 解题思路
类似数组的排序那种二重循环，只不过这里用指针表示，这里没有释放内存，会有泄漏
### 代码

```c
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(!head) return head;
	struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
	dummy->next = head;
	struct ListNode* pre = dummy;
	struct ListNode* p0 = dummy->next;
	struct ListNode* p1 = p0->next;
	int flag = 0; //当前是否存在相同元素
	while (p1) {
		if (p1->val == p0->val) {
			p1 = p1->next;
			flag = 1;
			continue;
		}
		if (flag) {
            flag=0;
			pre->next = p1;
			p0 = p1;
			p1 = p0->next;
		}else {
			pre = pre->next;
			p0 = pre->next;
			p1 = p0->next;
		}
	}
    if(flag) pre->next = p1;
	return dummy->next;
}
```