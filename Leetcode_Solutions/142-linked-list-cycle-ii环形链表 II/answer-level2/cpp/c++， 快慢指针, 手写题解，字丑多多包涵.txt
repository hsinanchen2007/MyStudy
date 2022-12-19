![QQ图片20200326225647.png](https://pic.leetcode-cn.com/30d85f5760211420f17fe03e3554743b453fe5488118de49a1868027f5ada79f-QQ%E5%9B%BE%E7%89%8720200326225647.png)
![IMG_20200326_223323_wps图片.jpg](https://pic.leetcode-cn.com/f730c0670f488775589beaf28196d5717068b111898ce6bb061641be5ff64fa5-IMG_20200326_223323_wps%E5%9B%BE%E7%89%87.jpg)

```
class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return NULL;
		}
		// 采用快慢指针找到两指针的交点
		ListNode* fast = head->next->next;
		ListNode* slow = head->next;
		while (fast != slow && fast != NULL && fast->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
		}
		// 如果链表无环则返回
		if (fast == NULL) {
			return NULL;
		}
		// 标记相遇点, 两指针以相同的步数前进,直到两指针的值相等，此时便是环的起点
		ListNode* point = fast;
		slow = head;
		while (slow != point && slow != NULL && point != NULL) {
			slow = slow->next;
			point = point->next;
		}
		return point;
	}
};
```
