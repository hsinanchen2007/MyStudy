自创的三队列算法

无论空间和时间肯定不是最优的，毕竟是编程小白，但可以提供一种思路。

首先，建立三个队列，作为2、3、5的待乘队列，各自插入元素 1 ；
每一轮操作时，计算三个队列的首位元素与各自乘数的积，取三者的最小值作为第 i 个丑数，并把这个最小值插入到三个队列的队尾；同时，对被取到最小值的队列进行弹出操作；
如此循环 n-1 次，可以计算出第n个丑数；

写完后看了大神的三指针法后恍然大悟，可以有效的减少内存空间。

附上代码：
int nthUglyNumber(int n)
{
    // 计算三个数中的最小值
    int Min(int a, int b, int c)
    {
        int result = a;
        if (b < result)
            result = b;
        if (c < result)
            result = c;
        return result;
    };

    // 定义队列结点
    struct Node
    {
        int Value;
        struct Node *Next;
    };

    // 定义队列结构体，包含首位元素与乘数的乘积（动态更新）、队列头指针、队尾指针
    struct Queue
    {
        int Front;
        struct Node *Header;
        struct Node *Tail;
    };

    // 队列初始化，将 1 插入队列中
    void InitQueue(struct Queue *myQueue, int multiplier)
    {
        struct Node *myHeader = malloc(sizeof(struct Node));
        struct Node *myTail = malloc(sizeof(struct Node));
        myHeader->Value = 0;
        myHeader->Next  = myTail;
        myTail->Value   = 1;
        myTail->Next    = NULL;
        myQueue->Front  = multiplier;
        myQueue->Header = myHeader;
        myQueue->Tail   = myTail;
    };

    // 队列的插入操作
    void Push(struct Queue *myQueue, int value)
    {
        struct Node *temp = malloc(sizeof(struct Node));
        temp->Value = value;
        temp->Next  = NULL;
        myQueue->Tail->Next = temp;
        myQueue->Tail = temp;
    };

    // 队列的弹出操作
    void Pop(struct Queue *myQueue, int multiplier)
    {
        if (myQueue->Front != 0)
        {
            struct Node *temp = myQueue->Header->Next;
            myQueue->Header->Next = temp->Next;
            if (temp->Next == NULL)
                myQueue->Front = 0;
            else
                myQueue->Front  = temp->Next->Value * multiplier;
            free(temp);
        }
    };
    
    // 定义三个待乘队列
    struct Queue *myQueue2 = malloc(sizeof(struct Queue));
    struct Queue *myQueue3 = malloc(sizeof(struct Queue));
    struct Queue *myQueue5 = malloc(sizeof(struct Queue));

    // 三个队列初始化
    InitQueue(myQueue2, 2);
    InitQueue(myQueue3, 3);
    InitQueue(myQueue5, 5);

    int count  = 1;  // 计数器
    int result = 1;  // 待返回的结果

    while (count < n)
    {
        result = Min(myQueue2->Front, myQueue3->Front, myQueue5->Front);
        count++;
        Push(myQueue2, result);
        Push(myQueue3, result);
        Push(myQueue5, result);
        if (myQueue2->Front == result)
            Pop(myQueue2, 2);
        if (myQueue3->Front == result)
            Pop(myQueue3, 3);
        if (myQueue5->Front == result)
            Pop(myQueue5, 5);
    }
    return result;
};