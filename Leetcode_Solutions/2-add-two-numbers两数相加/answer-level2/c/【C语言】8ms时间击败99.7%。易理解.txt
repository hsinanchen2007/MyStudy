**里面的ret这个值大概是这个解法最重要的一部分
本题的难点在于的是如何处理一些进位之类的特殊情况，而其中ret的设立很好的解决了这个问题，并且容易理解。
大概就是这样了，个人能力有限，能给大家带来好处的话再好不过，不喜勿喷。**
```
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l3->next = NULL;//初始一定要设成NULL，否则出错
    struct ListNode *head = l3;//初始将head = l3
    int i=0,ret = 3;//ret是用来形容各种状态的一个值，初始代表l1与l2均不为NULL
    while( ret != 0 ){
		struct ListNode *p;
		if( i != 0 ) {//因为这个链表是没有头结点的，所以i==0时p是不需要malloc的
            p = (struct ListNode*)malloc(sizeof(struct ListNode));
            p->next = NULL;
        }
        int sum;
        static int sum1;//用来表示下一位需要进多少值
        if( ret == 3 ) sum = (l1->val + l2->val) % 10;
        if( ret == 1 ) sum = (l1->val) % 10;//此时l2为NULL
        if( ret == 2 ) sum = (l2->val) % 10;//此时l1为NULL
        if( ret == 4 ) sum = 0;//此时l1与l2均为NULL，但是sum1不为0
        if( i == 0 ){
            l3->val = sum;//第一次直接给l3的val赋值
        }
        else{
            p->val = (sum+sum1) % 10;
            sum1 = (sum+sum1) / 10;/*这里是很重要的一步，sum1在这里顺便被初始化。防止例如sum=9，sum1=1的情况出现。*/
            head->next = p;
            head = p;
        }
        if( ret == 3 )sum1 += (l1->val + l2->val) / 10;
        if( ret == 2 )sum1 += (l2->val) / 10;
        if( ret == 1 )sum1 += (l1->val) / 10;
        if( ret == 4 )sum1 = 0;
        if( ret != 2 && ret != 4 ) l1 = l1->next;
        if( ret != 1 && ret != 4 ) l2 = l2->next;
        if( l1 || l2 ){
            if( l1 == NULL ){
                ret = 2;
            }
            if( l2 == NULL ){
                ret = 1;
            }
        }
        else{
            if( sum1 ) ret = 4;//这里是为了l1与l2皆为NULL但是sum1有值的情况设定的
            else ret = 0;
        }
        i++;
    }
    return l3;
}
```
