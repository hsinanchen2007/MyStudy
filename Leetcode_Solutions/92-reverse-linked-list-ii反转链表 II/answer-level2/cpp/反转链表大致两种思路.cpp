反转链表大致两种思路：一是改变指针域，不改变数据域；另一个是改变数据域，不改变指针域。后者需要开辟额外空间-一个栈即可。

只改变指针域，执行情况和代码如下：
性能：4ms  8.6MB

```
 ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n)
            return head;
        int i=1;
        ListNode* new_head=NULL;
        ListNode* p=head;
        ListNode* old_head=head;
        ListNode* p_pre_m=NULL;
        ListNode* p_m=head;
        
        while(i<m){
            p=p->next;
            new_head=head;
            head=p;
            i++;
        }
        p_pre_m=new_head;
        p_m=p;
        
        while(i<=n){
            p=p->next;
            head->next=new_head;
            new_head=head;
            head=p;
            i++;
        }
        if(m!=1){
            p_pre_m->next=new_head;
            new_head=old_head;
        }
        p_m->next=p;
        return new_head;     
    }
```

只改变数据域，执行情况和代码如下：
性能：4ms  8.7MB
```
ListNode* reverseBetween1(ListNode* head, int m, int n) {

	ListNode* p = head;
	vector<int>stack_list_val;
	int i = 1;//累计个数
	while (p&&i <= n && n >= m) {
		if (i >= m)
			stack_list_val.push_back(p->val);
		p = p->next;
		i++;
	}
	p = head;
	i = 1;
	while (p&&i <= n && n >= m) {
		if (i >= m) {
			p->val = stack_list_val.back();
			stack_list_val.pop_back();
		}
		p = p->next;
		i++;
	}
	return head;
}
```

