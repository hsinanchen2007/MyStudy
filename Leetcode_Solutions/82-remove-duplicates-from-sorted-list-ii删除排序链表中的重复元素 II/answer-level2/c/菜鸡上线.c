### 解题思路

![QQ图片20200324140447.png](https://pic.leetcode-cn.com/ceb4d491367608043334b7996aa0930f1092cc3f938dc27204438c46e696b2d8-QQ%E5%9B%BE%E7%89%8720200324140447.png)
1.暴力破解 2.递归
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//第一种正常思路暴力破解
struct ListNode* deleteDuplicates(struct ListNode* head)
{
	struct ListNode* px=head;//指向要删除的元素
	struct ListNode* pr=NULL;//指向要删除的元素的前一个元素
	struct ListNode* first=head;//遍历指针
	struct ListNode* ps=NULL;//指向pr前面
    if(px==NULL)
    {
        return NULL;
    }
	pr=px;
	px=px->next;
	int flag=0;
	while(px)
	{
		if(pr->val==px->val)
		{
			pr->next=px->next;
			px->next=NULL;
			free(px);
			px=pr->next;
			flag=1;
		}
		else if(pr->val!=px->val&&flag==0)
		{
			ps=pr;
			pr=px;
			px=px->next;
		}
		else if(pr->val!=px->val&&flag==1)
		{
			free(pr);
			pr=px;
			if(ps)
			{
				ps->next=pr;
			}
			else
			{
				head=pr;
			}
			px=px->next;
			flag=0;	
		}

	}
	if(flag==1)
	{
		if(head->next==NULL)
		{
			return NULL;
		}
		else
		{
			ps->next=NULL;
		}
	}
    return head;
}

//第二种递归思想
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    int flag=0;
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    while(head->next)
    {
        if(head->val==head->next->val)
        {
            flag=1;
            head=head->next;
        }
        else
        {
        	
            head->next=deleteDuplicates(head->next);
            break;
        }
    }
	if(flag==1)
	{
		head=head->next;
	}
    return head;
}
```