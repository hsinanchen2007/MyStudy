![20200331102530183.jpg](https://pic.leetcode-cn.com/afad31ed773d1c560e971736d8e2f3594205bbb58aff4f64ed884da9a3312a82-20200331102530183.jpg)


```
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
		else if (l2 == nullptr) return l1;//异常判断
		ListNode *n1 = l1, *n2 = l2;
		ListNode *head,*h;
		if (n1->val <= n2->val) { head = n1;h = n1; n1 = n1->next; }
		else { head = n2;h = n2; n2 = n2->next; }//确立头结点
		while (n1 != nullptr || n2 != nullptr) {
			if (n1 == nullptr) { head->next = n2;break; }//当一方为空时直接结束
			else if(n2 == nullptr) { head->next = n1;break; }
			if (n1->val <= n2->val) {
				head->next = n1;
				head = head->next;
				n1 = n1->next;
			}
			else {
				head->next = n2;
				head = head->next;
				n2 = n2->next;
			}
		}
		return h;
	}
};
```

