### 解题思路
快慢指针，92%击败。两种不同的微操，第二种更秀一点，个人感觉。
![图片.png](https://pic.leetcode-cn.com/34a629b09a7ca7d34e19062fac28d79a817a20b49170130599717668f59fed13-%E5%9B%BE%E7%89%87.png)

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head==NULL){
        return 0;
    }
    struct ListNode *p,*q;
	p=head;q=head;
	while(p->next!=NULL&&q->next!=NULL){
		if(p->next==q->next->next){
			return 1;
		}
		p=p->next;q=q->next->next;
        if(p==NULL||q==NULL){
            return 0;
        }
	}
	return 0;
}
```
```c
bool hasCycle(struct ListNode *head) {
    if(head==NULL)return false;
    struct ListNode *p,*q; 
    p=head;q=head;
    while(p!=NULL&&q!=NULL){
        if(q->next==NULL)return false;
        if(q->next->next==NULL)return false;
        p=p->next;q=q->next->next;
        if(p==q){
            return true;
        }
    }
    return false;
}
````