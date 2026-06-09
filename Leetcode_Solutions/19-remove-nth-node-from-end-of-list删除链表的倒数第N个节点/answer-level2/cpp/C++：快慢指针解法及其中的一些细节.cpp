因为粗暴解法思路比较简单，这里就讲一下快慢指针。其实我也是看到官方题解才知道有这种解法，思路很简单，就是使用两个指针，快指针领先慢指针n个节点，快指针到头时，慢指针指向倒数第n个节点（的前一个节点）。说几个细节：
+ 设定是快指针领先慢指针n个节点，那么有个问题，如果n是链表的长度，会造成指向末尾不存在的节点，该怎么办？其实检测一下快指针是否到头就可以了。
+ 注意，最后慢指针指向的是倒数第n+1个节点，不过这恰好方便我们删除目标节点
```cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* ret = head;
        for(int i=0;i<n;i++){
        	if(temp->next==NULL)return ret->next; //边界检查
        	temp=temp->next;
        }
        while(temp->next!=NULL){
        	temp=temp->next;
        	head=head->next; 
		}
		head->next=head->next->next; //删除操作
		return ret;
    }
```