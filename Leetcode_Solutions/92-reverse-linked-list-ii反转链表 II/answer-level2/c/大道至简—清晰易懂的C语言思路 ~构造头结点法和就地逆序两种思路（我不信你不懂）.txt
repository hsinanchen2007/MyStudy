```
struct ListNode* reverseBetween(struct ListNode* head, int m, int n){

if(!head||!(head->next)||(m==n)) return head;
struct ListNode* dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
dummy->next=head;
struct ListNode* q,*p,*pre;
q=p=dummy;
struct ListNode *L=(struct ListNode*)malloc(sizeof(struct ListNode));
struct ListNode* rear=L;
L->next=NULL;
/**
找出第m个位置的表头p以及第m-1个位置的指针pre
**/
int count=0;
while(m-count>0)
{
pre=p;
count++;
p=p->next;
}
/*
新建L链表对【M,N】中的元素进行头插
*/
while(n-count>=0)
{
q=p;
p=p->next;
count++;
q->next=L->next;
L->next=q;
if(rear->next)
{
rear=rear->next;
rear->next=NULL;
}
}
/**
第M-1个位置的指针指向新建链表的头结点，第N个位置的指针rear指向第m+1个位置，为p结点
***/
pre->next=L->next;
rear->next=p;
head=dummy->next;
free(dummy);//释放空间
return head;
}
```
```
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
	if (!head ||!(head->next)|| (m==n)) 
		return head;

	struct ListNode* p = head;
	struct ListNode* pM = NULL;//位于第m个位置的指针
	struct ListNode* pN = NULL;//位于第n个位置的指针
	struct ListNode* pTmp = head;//做遍历用的指针
	struct ListNode* pTmpPre = NULL;
	struct ListNode* pTmpPost = NULL;
	struct ListNode* pMPre = NULL;//第m-1个位置指针

	int i = 1;

    while (i <= n) {
		if (m == i) {
			pM = pTmp;
			pTmpPre = pTmp;
			pTmp = pTmp->next;
		}
        else if (i >m && i < n) {
			pTmpPost = pTmp->next;
			pTmp->next = pTmpPre;
			pTmpPre = pTmp;
			pTmp = pTmpPost;
		}
		else if (n == i) {
			pTmpPost = pTmp->next;
			pN = pTmp;
			pN->next = pTmpPre;
			pM->next = pTmpPost;
			if (NULL != pMPre) {//m不为1时
				pMPre->next = pTmp;
			}
			if (1 == m) {//m为1时
				head = pN;
			}
		}
		
		else {
			if (m == (i+1)) {
				pMPre = pTmp;
			}
			pTmpPre = pTmp;
			pTmp = pTmp->next;
		}

		i++;
	}

	return head;
}
```
