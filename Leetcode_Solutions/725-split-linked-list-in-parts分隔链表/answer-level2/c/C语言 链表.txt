思路和总结：
1.先找到一共有几个结点，然后求得每个链表有几个结点，一定要在每个链表的最后指向空
2.根据每个链表有几个结点，更新P的位置到下一个j链表需要指向的头的位置。这里封装函数更新P的时候用到了**p;
3.题目接口中的returnSize，不是每个链表的长度，只是返回的链表个数，等于k;
4.返回的链表需要自己申请，所以需要申请k个 空结点，用于指向root链表中的结点位置

void CalcNum(int n, int k, int*numL, int *numN)
{
    int temp;
    if(n<k){
        *numN = 1;
        *numL = n;
    } else {
        temp  = n % k;
		if (temp == 0){
			*numN = n/k;
			*numL = k;
		} else {
			*numN = n/k + 1;
			*numL = temp;
		}       
    }
}

void updateP(struct ListNode**p, int num)
{
    struct ListNode*  temp;
	struct ListNode*  p1;

    if(num == 0){
        return;
    }

	p1 = *p;
    while(num>0){
        num--;
        temp = p1;
        p1 = p1->next;
    }
    temp->next = NULL;
	*p = p1;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize)
{
    struct ListNode* p;
    struct ListNode **rslt;
    int i, n, numL, numN;

	*returnSize = k;

    p = root;
    n = 0;
    while (p!=NULL){
        n++;
        p = p->next;
    }

    //K个List中，numL个长度为numN的List,剩下的List长度为numN-1
    CalcNum(n,k,&numL,&numN);

    p = root;

    rslt = (struct ListNode**)malloc(k*sizeof(struct ListNode*));
    for(i=0; i<k; i++){
        if(i < numL){
            rslt[i] = p;
            updateP(&p,numN);
        } else {
            rslt[i] = p;
            updateP(&p,numN-1);
        }
    }

    return rslt;
}

