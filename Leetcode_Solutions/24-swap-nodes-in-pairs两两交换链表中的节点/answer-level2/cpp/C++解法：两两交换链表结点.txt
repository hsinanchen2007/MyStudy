思路一开始很清晰。核心是交换后注意将后一个节点的后继改为下一个待交换的节点组的后一个。这样做是为了避免交换时还要考虑前驱。还有一些细节就是链表到头了、链表只有一个元素等情况的处理。
画了个丑陋的示意图，表示交换1、2两个结点的过程：

![node.png](https://pic.leetcode-cn.com/7a85b7b1a2dcc0187888f68e6cce3f197e7302494ec81a6a20ba618b96a04dd7-node.png)
写着写着有点乱了，好在最后成功了。
```cpp
ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;
        ListNode* ret=head->next;
        while(head!=NULL&&head->next!=NULL){
        	if(head->next->next!=NULL&&head->next->next->next!=NULL){
        	ListNode* temp=head->next->next;
        	head->next->next=head;
			head->next=temp->next;
			head=temp;
        	}
        	else if(head->next->next!=NULL&&head->next->next->next==NULL){
        		ListNode* temp=head->next->next;
        		head->next->next=head;
				head->next=temp;
				break;
			}
        	else
        	{
        		head->next->next=head;
        		head->next=NULL;
        		break;
			}
		}
		return ret;
    }
```
