题前思考：
1. 为了节省内存，只在已有的l1、l2节点上操作，结果最多增添一个ListNode节点保存进位
2. 为了逻辑的方便，保留l1节点，如果l1较短，l1的尾结点指向l2剩余的节点，通过l1返回结果
3. 最坏情况下，总的遍历次数是两个链表的长度之后(length1+length2)，如果进位不是到达最后一个节点，提前退出，遍历次数会小于(length1+length2)，节省时间，时间复杂度o(n)。
4. 主要逻辑：
    - 从头开始同时遍历l1和l2，处理两个链表长度相等部分的节点之和，并记录l1的尾结点lTailNode，记录最后的进位iAdd
    - 如果l1节点较多，且上一步的进位iAdd为0，直接return l1，否则继续用l1余下的节点和iAdd计算，直到结束
    - 如果l2节点较多，将l1的尾节点指向l2的剩余节点的第一个节点。如果第一步的进位iAdd为0，直接return l1。否则继续用l2余下的节点和iAdd计算，直到结束
    - 如果最后iAdd>0，新增一个节点，值为1。
    - return l1。
```
    if(l1==NULL && l2==NULL) return NULL; 
    if(l1==NULL) return l2; 
    if(l2==NULL) return l1; 

    ListNode* ltemp1 = l1; 
    ListNode* lTailNode = l1;//把所有结果都通过l1传递，保存l1的最后一个节点
    ListNode* ltemp2 = l2; 
    int iAdd = 0;
    int iValue = 0;
    //处理长度相等部分的节点
    while(ltemp1 && ltemp2)
    {
        iValue = ltemp1->val + ltemp2->val + iAdd;
        if(iValue >= 10) 
        {   
            iAdd = iValue / 10; 
            ltemp1->val = iValue % 10; 
        }   
        else
        {   
            ltemp1->val = iValue;
            iAdd = 0;
        }   

        lTailNode = ltemp1;
        ltemp1 = ltemp1->next;
        ltemp2 = ltemp2->next;
    }   
    //如果l1节点较多 
    if(ltemp1)
    {
        //如果无进位 直接return
        if(iAdd == 0)
        {
            return l1;
        }
        //处理进位
        while(ltemp1)
        {
            ltemp1->val = ltemp1->val + iAdd;
            if(ltemp1->val >= 10)
            {
                iAdd = ltemp1->val / 10;
                ltemp1->val = ltemp1->val % 10;
            }
            else
            {
                iAdd = 0;
                break;
            }
            lTailNode = ltemp1;                                                                     
            ltemp1 = ltemp1->next;
        }
    }
    else if(ltemp2) //如果l2较长，将l1尾部指向剩余的l2节点
    {
        lTailNode->next = ltemp2; //l1的尾节点指向l2的剩余部分
        if(iAdd == 0)
        {
            return l1;
        }
        while(ltemp2)
        {
            ltemp2->val = ltemp2->val + iAdd;
            if(ltemp2->val >= 10)
            {
                iAdd = ltemp2->val / 10;
                ltemp2->val = ltemp2->val % 10;
            }
            else
            {
                iAdd = 0;
                break;
            }
            lTailNode = ltemp2;
            ltemp2 = ltemp2->next;
        }
    }
    //如果两个链表都同时到达尾部且进位不为0 或者长链表处理完 进位不为0
    if(iAdd > 0)
    {
        ListNode *pnew = new ListNode(iAdd);
        lTailNode->next = pnew;
    }
    return l1;
```
