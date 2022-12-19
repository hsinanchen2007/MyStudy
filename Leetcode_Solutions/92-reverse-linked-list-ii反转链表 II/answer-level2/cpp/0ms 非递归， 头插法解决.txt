```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
ListNode* reverseBetween(ListNode* head, int m, int n) {
	if (!head || m >= n)
		return head;
    //创建冗余头节点
	ListNode* before = new ListNode(0);
    //qNode节点将指向被反转部分的前一个节点
	ListNode* qNode = before;
	qNode->next = head;
    //pNode是遍历指针
	ListNode* pNode = head;
    //共需要反转k个节点
	int k = n - m;
    //pNode和qNode同时移动到需要反转的位置，循环结束后，pNode指向需要反转部分的第一个节点
	while (m > 1)
	{
		pNode = pNode->next;
		qNode = qNode->next;
		m--;
	}
    *//反转结束后，需要接上后续节点，last记录反转结束后的反转部分最后一个节点，也就是pNode*
	ListNode* last = pNode;
    //pNode后移一个位置，开始头插法
	pNode = pNode->next;
    //temp记录pNode后续节点，防止断链
	ListNode* temp = pNode;
    //基础头插法算法
	while (k > 0)
	{
		temp = pNode->next;
		pNode->next = qNode->next;
		qNode->next = pNode;
		pNode = temp;
		k--;
	}
    //循环结束后，temp指向反转部分的后一个节点，用之前记录的last接上后续节点
	last->next = temp;
    //返回冗余头节点的next
	return before->next;
}
};
```
