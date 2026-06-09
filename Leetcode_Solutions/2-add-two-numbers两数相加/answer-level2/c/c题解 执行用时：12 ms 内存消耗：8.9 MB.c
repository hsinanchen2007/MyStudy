```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* listInsert(struct ListNode *head, int value);
void listPrint(struct ListNode *head);

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int num1, num2, result;
    int flag = 0;//进位
    struct ListNode *pl1 = l1;
    struct ListNode *pl2 = l2;
    
    //必须初始化为NULL,否则肯呢个导致段错误，因为插入链表时会判断此值是否为空
    struct ListNode *presult = NULL;

    if(NULL == l1 || NULL == l2) {
        return NULL;
    }
    while(1) {
        num1 = (NULL == pl1) ? 0 : pl1->val;
        num2 = (NULL == pl2) ? 0 : pl2->val;

        result = num1 + num2 + flag;
        /*
         * 临界条件必须考虑清楚
         * 最高位都没有值，且没有进位时退出
        */
        if(pl1 == NULL && pl2 == NULL && result == 0) {
            //listPrint(presult);
            return presult;
        }
        flag = result / 10;
        result = result % 10;
        //printf("result=%d, flag=%d\n", result, flag);
        presult = listInsert(presult, result);
       
        pl1 = (pl1 == NULL) ? NULL : pl1->next;
        pl2 = (pl2 == NULL) ? NULL : pl2->next;
    }
}

struct ListNode* listInsert(struct ListNode *head, int value){
    struct ListNode *newnode = NULL;
    newnode = (struct  ListNode*)malloc(sizeof(struct ListNode));
    newnode->val = value;
    newnode->next = NULL;
    if(NULL == head) {
        head = newnode;
		return head;
    }
    struct ListNode *p = head;
    while(p) {
		if(NULL != p->next) {
        	p = p->next;
		} else
			break;
    }
    p->next = newnode;
    return head;
}
void listPrint(struct ListNode *head){
	//printf("print list : ");
    while(head != NULL) {
        printf(" %d", head->val);
        head = head->next;
    }
    printf("\n");
}

static void listFree(struct ListNode *head){
    struct ListNode *p = NULL;
    while(head != NULL) {
        p = head;
        head = head->next;
        free(p);
        p = NULL;
    }
    return;
}
```