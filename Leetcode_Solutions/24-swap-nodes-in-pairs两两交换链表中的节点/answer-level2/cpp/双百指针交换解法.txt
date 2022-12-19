### 解题思路
1. 添加一个头结点方便交换
2. 将prev定义为上一次进行交换的偶数位置，通过prev可以方便的找到要交换的节点，初始值就是头结点
3. p在链表上移动
4. 每当p指向偶结点时进行交换操作
	tmp = p->next;   // tmp 保存后面要处理的位置
	p->next = prev->next;  // p->next修正为prev->next，也就是p前一个节点的指针
	prev->next->next = tmp;  // p的前一个节点的next指向tmp，后面要处理的位置
	prev->next = p;				// prev->next设置为p
	prev = prev->next->next;	// 更新prev 方便下一次交换使用
	p = prev->next;				// 更新p
### 代码

```cpp
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr) {
			return head;
		}

		ListNode *p = new ListNode(0);  //添加头结点
		p->next = head;
		ListNode *prev = p;
		ListNode *new_head = p;
		ListNode *tmp;

		int i = 0;
		while (p != nullptr) {
			if (i % 2 == 0 && i != 0) {
				tmp = p->next;
				p->next = prev->next;
				prev->next->next = tmp;
				prev->next = p;
				prev = prev->next->next;
				p = prev->next;
			} else {
				p = p->next;
			}
			i++;
		}
		head = new_head->next;
		delete new_head;
		return head;
	}
};
```