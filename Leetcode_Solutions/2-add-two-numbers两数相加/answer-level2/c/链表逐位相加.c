1. 利用calloc来创建一块连续的内存来存储ListNode类型的变量cur，用于存储当前两个链表相加的结果。（p.s. calloc与malloc的区别在于，malloc创建好的内存里面存储的是随机的值，但是calloc创建好的内存里面存储的是0）
2. 设置标志位add来判断当前位置的加法是否有进位。
3. 当链表l1指向的不是空值或者链表l2指向的不是空值或者add标志位不为0的时候，进行循环逐位相加。
4. 在循环过程中，cur->next也是需要通过calloc进行创建分配内存的。然后更新l1,l2,add。
5. 最后返回在开始时候cur的复制品ret，也就是链表的头即可。


```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* cur =(struct ListNode*) calloc(1, sizeof(struct ListNode));
	struct ListNode* ret;
	
	ret = cur;
	int add=0;
	int tmp1,tmp2,vtmp;
	while((l1!=NULL)||(l2!=NULL)||(add!=0)){
		
		if(l1!=NULL){
			tmp1 = l1->val;
			l1 = l1->next;
		}else{
			tmp1=0;
		}
		
		if(l2!=NULL){
			tmp2 = l2->val;
			l2 = l2->next;
		}else{
			tmp2=0;
		}
		
		vtmp = tmp1+tmp2+add;
		
		
		cur->next =(struct ListNode*) calloc(1, sizeof(struct ListNode));
		cur->next->val = vtmp%10;
		add=vtmp/10;
		cur = cur->next;

	
	}
	return ret->next;
}
```
