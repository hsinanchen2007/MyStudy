```
struct ListNode* insertionSortList(struct ListNode* head){
	if(head == NULL){
		return head;
	}
	struct ListNode *temp = head->next; //从第二个元素开始排序 
	struct ListNode *tail = head; //指向已排序的最后一个元素  便于退出循环 
    while(temp != NULL){
    	
    	struct ListNode *preNode = head;  //前一个位置 
    	struct ListNode *curNode = head;  //当前位置 
    	struct ListNode *next = temp->next; //保留待排序的下一个位置 
    	
    	while(temp->val >= curNode->val && curNode != tail){
    		preNode = curNode;
    		curNode = curNode->next;
		}
		
		//退出循环后的判断按照退出条件分别进行判断 
		if(temp->val < curNode->val){
			//插入到tial之前，tail的位置不变 
			if(curNode == preNode){
				//插入到第一个 head位置改变 
				temp->next = head;
				head = temp;
			}else{
				//插入到head和tail之间 
				temp->next = curNode;
				preNode->next = temp;
			}
		}else{ //curNode == tail && curNode->val <= temp->val 插入到最后 tail的位置改变 
			tail->next = temp;
			tail = temp;
		}
		temp = next;
	}
	tail->next = NULL;
	return head;
}
```
