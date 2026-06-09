### 解题思路
基础做法：
1、先遍历计算总长度len;
2、在从头循环到倒数第k个，返回结果

双指针
1、先让快指针走k步
2、然后2个指针同时走，当快指针到末尾时，慢指针刚好处于倒数第k个节点位置


### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// 统计链表元素个数（长度）
int getLength(struct ListNode* head)
{
	int count = 0;
	while(head != NULL)
	{
		count++;
		head = head->next;
	}
	return count;
}

// 返回倒数第k个节点值
int kthToLast2(struct ListNode* head, int k)
{
	int len = getLength(head);
	//printf("len: %d\n", len);
	while(len > k)
	{
		head = head->next;
		len--;
	}
	return head->val;	
}

// 双指针
int kthToLast(struct ListNode* head, int k)
{
    struct ListNode* fast = head;
    while(k--)
    {
        fast = fast->next;
    }
    while(fast)
    {
        fast = fast->next;
        head = head->next;
    }
    return head->val;
}

```