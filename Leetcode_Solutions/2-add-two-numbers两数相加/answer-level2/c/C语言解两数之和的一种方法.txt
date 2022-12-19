### 解题思路
- 这里定义了两个方法，第一个`createList`是用来生成一个初始化一个节点，其`value`值为0，`next`值为NULL
  第二个方法是`copy`作用是复制一个链表，有两个参数，第一个是需要被复制的链表，第二个参数是一个加到这个链表上的一个0-9的数字
  当overflow为0的时候就是简单复制一个链表，当overflow为1-9的时候返回的是这个将这个overflow加到链表上的结果

- 在这个`addTwoNumbers`方法中，我的想法是首先分别判断一下这两个链表是不是表示为0，如果有一个表示为0则直接复制另外一个返回即可，
  当这两个链表都不是表示0的时候，可以一位一位地加直到有一个链表为空，再将进位和剩下的另外一个链表加起来也就是调用`copy`方法连接    到结果链表上即可。

- `copy`方法首先判断一下overflow是不是0，如果是且这个时候target也是NULL的话说明只需要返回一个节点即可，如果target不为null，不管      overflow是多少，还是按照进位加法相加即可，最后再判断一下最后是否还有进位。

### 代码

```c
typedef struct ListNode ListNode;

ListNode* createList();
ListNode* copy(ListNode* , int );

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
    ListNode* l3 = createList();//initialize to be 0
    ListNode* last = l3;
    ListNode* node = NULL;

    int remain , overflow , temp;

    //if input is 0
    if(l1->val == 0 && l1->next == NULL)
    {
        l3 = copy(l2,0);
        return l3 ;
    }else if(l2->val == 0 && l2->next == NULL)
    {
        l3 = copy(l1,0);
        return l3;
    }
    // both two of the input is not zero
    temp = l1->val+l2->val;

    remain = temp%10;
    overflow = temp/10;

    l3->val = remain;
    l1 = l1->next;
    l2 = l2->next;
    
    while(l1&&l2)
    {
        temp = l1->val+l2->val+overflow;

        remain = temp % 10;
        overflow = temp/10;

        node = malloc(sizeof(ListNode));

        node->val = remain;
        node->next = NULL;

        last->next = node;
        last = node;

        l1 = l1->next;
        l2 = l2->next;
    }

    if(l1 == NULL)
    {
        node = copy(l2,overflow);

        last->next = node;

        return l3;
    }
    if(l2 == NULL)
    {
        node = copy(l1,overflow);

        last->next = node;

        return l3;
    }

   return l3;

}

struct ListNode* createList()
{
    ListNode* temp  = malloc(sizeof(ListNode));

    temp->val = 0;

    temp->next = NULL;

    return temp;
}

ListNode* copy(ListNode* target,int overflow)
{
    ListNode* l = NULL;
    ListNode* temp = NULL;
    ListNode* last = NULL;

    int remain , over , result;

    l = malloc(sizeof(ListNode));
    //first do the safty check
    if(target == NULL && overflow == 0)
    {
        return NULL;
    }
    if(target == NULL && overflow != 0)
    {
        temp = malloc(sizeof(ListNode));

        temp->val = overflow;

        temp->next =NULL;

        return temp;
    }
    
    result = target->val + overflow;

    remain = result%10;
    over = result/10;

    l->val = remain;

    l->next = NULL;

    target = target->next;

    last = l;
    
    while(target)
    {
        temp = malloc(sizeof(ListNode));

        result = target->val + over;
        remain = result%10;
        over = result/10;
        
        temp->val = remain;

        temp->next =NULL;

        last->next = temp ;

        last = temp ;

        target = target->next;
    }
    //check the overflow 
    if(over == 0)
    {
        return l;
    }
    else 
    {
        temp = malloc(sizeof(ListNode));

        temp->val = over;

        temp->next = NULL;

        last->next = temp;
        

        return l;
    }

    
}
```