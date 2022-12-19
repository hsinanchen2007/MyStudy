# 147. 对链表进行插入排序
**思路：**

- 插入排序的基本思想是：每步将一个待排序的记录，按其关键码值的大小插入前面已经排序的文件中适当位置上，直到全部插入完为止。
- 但是链表只能向后移动。所以我们需要稍微修改插入排序，改为链表形式。
    1. 首先链表插入排序的本质是遍历一遍原始数据，每次从原始链表数据头部取出一个节点。然后插入到新链表的恰当位置。再后移原始链表遍历位置。
    2. 由于结果链表插入数据，需要用到结果链表插入位置的前一个节点信息。所以定义一个结果数组的头指针指向结果链表（初始化下个节点为空状态）。每次从原始链表排序链表头部取出一个未排序节点。然后遍历结果列表：
    （如果结果列表下一个节点数值大于当前未排序节点数值 或 结果列表下一个节点为空），则插入。并后移原链表，继续下一次排序。

**完整代码：**
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
    ListNode* insertionSortList(ListNode* head) {
		if( head == NULL ) return head;	//特殊值判断
		
		//创建结果链表头结点
        ListNode rst_head(0);
		rst_head.next = NULL;	//默认为空
		
		ListNode* temp;	//记录原链表下一节点位置。
		ListNode* p;	//记录结果链表遍历中间节点。
		while(head){			//遍历原始链表节点
			temp = head->next;	//记录原始链表下次遍历位置
			ListNode* p = &rst_head;	//记录结果链表起始位置
			while( p ){					//遍历排好序的结果链表
				if( p->next == NULL || p->next->val > head->val ){	//结果链表next为空 或者 结果链表next值小于当前插入节点
					head->next = p->next;	//节点插入
					p->next = head;
					break;
				}else{
					p = p->next;
				}
			}
			head = temp;
		}
		return rst_head.next;
    }
};
```

