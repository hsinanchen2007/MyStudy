# 82. 删除排序链表中的重复元素 II
**思路：**

- 原链表为有序链表，在删除重复链表后需要保持原链表的顺序，所以要采用尾插法。（依次扫描原链表节点，将需要的结点一次插入新的结果链表尾部）。
- 需要定义结果链表的头结点：头结点排除第一个结点与其他结点插入和删除时的差异；
- 还需要定义结果链表的尾结点：记录结果链表尾部，下个结点插入该节点之后，从而保持与原链表同序。
- 遍历原链表是根据以下规则：
    1. 如果该节点存在下个节点并且，该节点值与下个节点值相同，那我们进入下层循环，屏蔽掉所有该值的结点。并不需要插入结果数组。
    2. 该节点与下个节点不同将该点尾插到结果链表。
# 注意：需要多次判断下个节点时候为空！

**实现代码：**
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
    ListNode* deleteDuplicates(ListNode* head) {
    	if(!head) return head;	//如果输入链表为空 返回值也为空

    	//创建结果链表头结点
        ListNode dst_head(0);	//头结点排除第一个结点与其他结点插入和删除时的差异
        dst_head.next = NULL;

        //结果链表采用尾插法，定义结果链表尾戒点指针
        ListNode *rst_tail = &dst_head;

        while( head ){
        	if( (head->next != NULL) && (head->next->val == head->val) ){
        		int temp_data = head->val;
        		do{
        			head = head->next;
        		}while( (head != NULL) && (head->val == temp_data) );
        	}else{	//只对没有重复的结点进行尾插
        		rst_tail->next = head;
        		head = head->next;
        		rst_tail = rst_tail->next;
        		rst_tail->next = NULL;
        	}
        }
        return dst_head.next;
    }
};
```
