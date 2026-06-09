### 解题思路
![图片.png](https://pic.leetcode-cn.com/0cad8da3ffa66a9b806121548e20cff98d2ba2fb7c805f523a541ab57908ae3d-%E5%9B%BE%E7%89%87.png)


迭代版2路归并排序，写了半天。。。。
### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
2路归并排序 
先局域排序，然后依次扩大范围
2个排好之后4个排
比如  3204
23 04
0234

*/
class Solution {
public:
	ListNode* hlist=NULL;
	ListNode* sortList(ListNode* head) {
		
		ListNode* p1 = head, * p2 = head, *p = head, *pbefore=head, *pafter=NULL;
		hlist = head;
		int len = 0;
		//计算数量确认归并排序次数
		while (p != NULL)
		{
			len++;
			p = p->next;
		}
		//如果小于两个元素直接返回
		if (len < 2)
			return head;
		//i表示步进个数    几个几个排序
		for (int i = 1; i<len; i=i << 1)
		{
			int temp = i;
			//前驱节点
			pbefore = NULL;
			//p1是第一路，p2是第二路
			p2=p1 = hlist;
			for (int j = 0; j < temp; ++j)
				p2 = p2->next;

			//后置节点，也是下一次开始的起点
			pafter = p2;
			for (int j = 0; j < temp; ++j)
				if(pafter!=NULL)
					pafter = pafter->next;
			
			while (p1!=NULL && p2!=NULL)
			{
				//在保证了前驱和后置都知道的情况下，两路归并排序这一段链表
				p=merge2List(pbefore, p1, p2, temp);
				p->next = pafter;
				pbefore = p;

				p2=p1 = p->next;
				for(int j=0; j<temp; ++j)
					if(p2!=NULL)
						p2 = p2->next;

				pafter = p2;
				for (int j = 0; j < temp; ++j)
					if (pafter != NULL)
						pafter = pafter->next;
			}

		}
		return hlist;
	}
	//合并两个链表，将并连接到前序链表上，返回最后一个节点指针
	ListNode* merge2List(ListNode* before, ListNode* h1, ListNode* h2, int k)
	{
		ListNode* newHead=NULL, *p=NULL;

		int k1 =k, k2 = 0;
		p = h2;
		for (int i = 0; i < k; ++i)
			if (p != NULL)
			{
				k2++;
				p = p->next;
			}
			else
				break;

		//两个链表都不空
		while (k1 && k2 && h1 != NULL && h2 != NULL)
		{
			//取较小的节点
			if (h1->val > h2->val)
			{
				if (newHead == NULL)
				{
					newHead = h2;
					p = h2;
				}
				else
				{
					p->next = h2;
					p = p->next;
				}
				h2 = h2->next;
				k2--;
			}
			else
			{
				if (newHead == NULL)
				{
					newHead = h1;
					p = h1;
				}
				else
				{
					p->next = h1;
					p = p->next;
				}
				h1 = h1->next;
				k1--;
			}
	
		}
		//步进到最后一个元素
		if (k1)
		{
			p->next = h1;
			while (k1--)
				p = p->next;
		}
		if (k2)
		{
			p->next = h2;
			while (k2--)
				p = p->next;
		}

		//如果没有前驱节点说明是头结点，赋给头结点
		if (before == NULL)
			hlist = newHead;
		else
			before->next = newHead;

		//返回合并后的最后一个元素
		return p;
	}

};
```