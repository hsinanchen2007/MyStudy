/*
在题解一位大神（标题为：逐位相加，模拟进位）的思路下修改，看齐评论我亦认为其存在内存泄漏的小问题，所以想要在其基础上进行修改，望各位海涵。
（本人愚拙，一开始的思路很不堪，将两个数化为整数加起来放到一个新的链表，结果提交时发现即使是long long 型也有数据界限，故此，只能说膜拜大神，学习大神思路，特此记录）
*/
```
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int digit1 = 0,digit2 = 0,digit_sum = 0,carry = 0,digit3 = 0;
    struct ListNode *l1a = l1,*l2a = l2;
    struct ListNode *result=(struct ListNode*)malloc(sizeof(struct ListNode));
    result->next = NULL;
    struct ListNode *result_a = result,*result_pre = result;
    while(l1a != NULL || l2a != NULL)
    {
        digit1=(l1a==NULL)?0:l1a->val;
        digit2=(l2a==NULL)?0:l2a->val;
        digit_sum = digit1 + digit2 + carry;
        carry = digit_sum/10;       //进位
        digit3 = digit_sum%10;      //本位的值
        result_a->val = digit3;
        result_a->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        result_pre = result_a;            //保持其为尾节点前一个基点，方便释放内存
        result_a = result_a->next;
        result_a->next = NULL;
        if(l1a != NULL) l1a = l1a->next;
        if(l2a != NULL) l2a = l2a->next;
    }
    if(carry > 0 )  result_a->val = 1;    //超过最大位数，需要进一
    else
    {
        free(result_a);                  //未超过最大位数，释放尾节点内存
        result_pre->next = NULL;         
    }
    return result;
}
```
