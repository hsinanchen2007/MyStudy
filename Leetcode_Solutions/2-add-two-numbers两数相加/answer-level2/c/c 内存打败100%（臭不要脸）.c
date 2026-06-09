**解题思路：**
1、直接在链表上相加，因为链表是按照逆序的方式存储的，所以可以直接从第一个节点相加。
2、利用栈将链表上的数据还原成十进制数，然后相加得到最终的数，在还原成链表的形式，但是这个方法有个缺点，就是总数的位数是由现，如果是9999999999999+99999999999999999999999999999999999999999，就很难直接表示成在计算机里数，所以可以利用数组来存储大的整数

方法2代码如下
//数组存储数


int getLen(struct ListNode *l)
{
    int len = 0;
    while (l != NULL)
    {
        len += 1;
        l = l->next;
    }

    return len;
}

void forSum(struct ListNode *l, int len, int math[])
{
    int k = 0;
    while(l != NULL)
    {
        math[k++] = l->val;
        l = l->next;
    }
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *returnRoot = NULL, *p;
    int maxLen, sum = 0;
    int len1, len2;

    len1 = getLen(l1);
    len2 = getLen(l2);
    maxLen = len1 > len2 ? len1 : len2;

    int math1[maxLen + 1], math2[maxLen + 1];

    memset(math1, 0, sizeof(int) * (maxLen + 1));
    memset(math2, 0, sizeof(int) * (maxLen + 1));
    
    forSum(l1, len1, math1);
    forSum(l2, len2, math2);

    int flag = 0;  //进位
    //相加
    for (int i = 0; i <= maxLen; i++)
    {
        sum = 0;
        sum = math1[i] + math2[i] + flag;
        math1[i] = sum % 10;
        flag = sum / 10;
    }
    


    returnRoot = (struct ListNode *)malloc(sizeof(struct ListNode));
    returnRoot->val = math1[0];
    p = returnRoot;

    for (int i = 1; i < maxLen; i++)
    {
        p->next= (struct ListNode *)malloc(sizeof(struct ListNode));
        p->next->val = math1[i];
        p = p->next;
    }
    if (math1[maxLen] != 0){
        p->next= (struct ListNode *)malloc(sizeof(struct ListNode));
        p->next->val = math1[maxLen];
        p = p->next;
    }
    p->next = NULL;

    
    return returnRoot;
}
