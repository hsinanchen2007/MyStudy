### 解题思路
此处撰写解题思路
1.这个代码思路上来说并不难，但是如果你没有清晰的逻辑，那么将会变得十分混乱与复杂。所以下次要写代码之前，一定一定一定把自己完整的思路，写在纸上面，在纸上面就要考虑到所有的情况。顺便再c手动测试几个例子，如果有修改的思路也要在纸上完成！！！不要边写边改，可真就成了“屎山”。
2.从细节正面来讲，我对于指针的认识又比以前深入了一些。
例如：]
point* a;
point* b;
point* c = (point*)malloc(sizeof(point));
这意味着，现在有了一个可以指向point*类型的指针a，你可以令这个指针指向同样未分配空间的b,也可以指向已经分配空间的c。但是你不可以使用a = a->next(假如他有这个成员)等任何结构体里面的成员。因为你没被分配内存，也没有指向别人分好的内存，a是个孤儿指针。
所以，当我们相对某个指针内的成员赋值或者其他操作的时候，这块指向的空间一定是被alloc的。没有就要申请。
如果指向已经被分配的空间，那么请随意。切记！
3.如果我们需要创建一个链表来记录数据，那么一般需要两个指针，一个记载头部位置，一个用作工作指针。这个链表是需要分配空间的。因为他要记录数据。如果别人已经有数据了，那么此时可以不分配空间，直接指过去。
4.自己写完代码之后，第一遍使用样例来测试自己的逻辑。第二遍检查所有符号是否写错，漏掉，大小写失误。
5.没有typedef 在定义结构体变量或者指针的时候请加上struct。

### 代码

```c
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
/*算法思想：
先便利两个链表过清楚到底有多少位，然后拉到相同的位做相加
学习心得：
没有typedef 请使用 struct node的类定义变量，不要省略

指针操作出现了严重的失 
*/

    struct ListNode* retListNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    retListNode->next = NULL;
    struct ListNode* headListNode;
    headListNode = retListNode;
    headListNode->next = NULL;

    struct ListNode* p1 = l1;
    struct ListNode* p2 = l2;
    int l1Num = 0;
    int l2Num = 0;

    while (p1 != NULL){
        l1Num ++;
        p1 = p1->next;
    }
    while (p2 != NULL){
        l2Num ++;
        p2 = p2->next;
    }    
    int preStep = l1Num - l2Num;
    p1 = l1;//reset pointer
    p2 = l2;

    /*交换*/
    if (preStep < 0){
        struct ListNode* temp;
        temp = p1;
        p1 = p2;
        p2 = temp;
        preStep = -preStep;
        l2Num = l1Num;
    }
    /*一样长*/
    if (preStep == 0){
        int tag = 0;
        while (p1 != NULL){
            struct ListNode* newNode2 = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode2->val = p1->val + p2->val + tag;
            if ( newNode2->val > 9){//进位判断
                tag = 1;
                newNode2->val = newNode2->val%10;
            }
            else{
                tag = 0;
            }
            p1 = p1->next;
            p2 = p2->next;

            retListNode->next = newNode2;
            retListNode = retListNode->next; 
         }
         if (tag == 1){//最终还有进位
            struct ListNode* newNode2 = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode2->val = 1;
            retListNode->next = newNode2;
            retListNode = retListNode->next; 
         }
        retListNode->next = NULL;
        retListNode = headListNode->next;

        return retListNode;
    }
    else{
        /*不一样长
        先处理前面*/
        int tag = 0;
        while ( l2Num-- > 0 ){
            struct ListNode* newNode2 = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode2->val = p1->val + p2->val + tag;
            if ( newNode2->val > 9){//进位判断
                tag = 1;
                newNode2->val = newNode2->val%10;
            }
            else{
                tag = 0;
            }
            p1 = p1->next;
            p2 = p2->next;

            retListNode->next = newNode2;
            retListNode = retListNode->next; 
        } 
        /*再摘取较长节点*/
        while ( p1 != 0 ){
            struct ListNode* newNode3 = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode3->val = p1->val + tag;
            if ( tag == 1){
                tag = 0;
            }
            if (newNode3->val > 9){
                tag = 1;
                newNode3->val = newNode3->val%10;
            }
            p1 = p1->next;
            retListNode->next = newNode3;
            retListNode = retListNode->next; 
        }
        if (tag == 1){
            struct ListNode* newNode4 = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode4->val = 1;
            retListNode->next = newNode4;
            retListNode = retListNode->next; 
        }
        retListNode->next = NULL;
        retListNode = headListNode->next;  
    }
return retListNode;
}


```