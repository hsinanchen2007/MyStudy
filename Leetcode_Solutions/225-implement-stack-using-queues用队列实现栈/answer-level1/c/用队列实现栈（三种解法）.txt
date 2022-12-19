
我只想到一种解法，后看题解时，发现有两种完全没想到的思路，学习到了！

解法1：双队列a、b，入栈时将数据存入到a内；出栈时将a内元素除最新元素外都转移到b内，再将b内元素全部转移到a内，得到应出栈的数据。
比如依次添加1,2,3,4,5。数据在a中的顺序关系是5<=4<=3<=2<=1。此时出栈数据应为5，而出队列数据为1，所以需要另外个队列b配合。依次a队列出列，b队列入列，直到a队列内只剩一个元素5，b队列内数据为4<=3<=2<=1。5就为出栈元素，最后再将b队列内的元素出列入列到队列a内。

入栈时间复杂度O(1)

出栈时间复杂度O(n)

    typedef struct listNode {
        struct ListNode *next;
        int val;
    } ListNode;

    typedef struct {
        ListNode *tail;
        ListNode *head;
    } Queues;

    typedef struct {
        Queues *q1;
        Queues *q2;
    } MyStack;



    /** Initialize your data structure here. */

    MyStack* myStackCreate() {
        MyStack *myStack = (MyStack *)malloc(sizeof(MyStack));
        myStack->q1 = (Queues *)malloc(sizeof(Queues));
        myStack->q2 = (Queues *)malloc(sizeof(Queues));
        myStack->q1->tail = NULL;
        myStack->q1->head = NULL;
        myStack->q2->tail = NULL;
        myStack->q2->head = NULL;
        return myStack;
    }

    /** Push element x onto stack. */
    void myStackPush(MyStack* obj, int x) {
        ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
        tmp->val = x;
        tmp->next = NULL;

        if (obj->q1->head == NULL) {
            obj->q1->head = obj->q1->tail = tmp;
        } else {
            obj->q1->head->next = tmp;
            obj->q1->head = tmp;
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int myStackPop(MyStack* obj) {
        ListNode *tmp = obj->q1->tail;
        obj->q2->head = obj->q2->tail = NULL;
        while (obj->q1->tail->next != NULL) {
            tmp = obj->q1->tail;
            obj->q1->tail = obj->q1->tail->next;

            tmp->next = NULL;
            if (obj->q2->head == NULL) {
                obj->q2->head = obj->q2->tail = tmp;
            } else {
                obj->q2->head->next = tmp;
                obj->q2->head = tmp;
            }
        }
        int data = obj->q1->tail->val;
        free(obj->q1->tail);

        obj->q1->tail = obj->q2->tail;
        obj->q1->head = obj->q2->head;
        return data;
    }

    /** Get the top element. */
    int myStackTop(MyStack* obj) {
        ListNode *tmp = obj->q1->tail;
        obj->q2->head = obj->q2->tail = NULL;
        int data;
        while (obj->q1->tail != NULL) {
            tmp = obj->q1->tail;
            if (obj->q1->tail->next == NULL) {
                data = obj->q1->tail->val;
            }
            obj->q1->tail = obj->q1->tail->next;

            tmp->next = NULL;
            if (obj->q2->head == NULL) {
                obj->q2->head = obj->q2->tail = tmp;
            } else {
                obj->q2->head->next = tmp;
                obj->q2->head = tmp;
            }
        }

        obj->q1->tail = obj->q2->tail;
        obj->q1->head = obj->q2->head;
        return data;
    }

    /** Returns whether the stack is empty. */
    bool myStackEmpty(MyStack* obj) {
        if (obj->q1->tail == NULL) {
            return true;
        } else {
            return false;
        }
    }

    void myStackFree(MyStack* obj) {
        ListNode *tmp;
        while (obj->q1->tail != NULL) {
            tmp = obj->q1->tail;
            obj->q1->tail =  obj->q1->tail->next;
            free(tmp);
        }
    }


解法2：旨在如何依赖两个队列，在入栈时生成按出栈顺序依次出队的队列。
两个空队列a，b。入栈元素1，添加到队列b，队列a为空，将b内元素全部转移到a内；入栈元素2，添加到队列b，队列a非空，将队列a内元素转移到b内，b顺序为1,2。2后入队，将先出队，再将b内元素全部转移到a内；入栈元素3，添加到队列b，将队列a内1,2元素按序转移到b内，b顺序为1,2,3。3后入队，将先出队，将b内元素转移到a内，最后a内元素顺序为1,2,3。

入栈时间复杂度O(n)

出栈时间复杂度O(1)

    typedef struct listNode {
        struct ListNode *next;
        int val;
    } ListNode;

    typedef struct {
        ListNode *tail;
        ListNode *head;
    } Queues;

    typedef struct {
        Queues *q1;
        Queues *q2;
    } MyStack;



    /** Initialize your data structure here. */

    MyStack* myStackCreate() {
        MyStack *myStack = (MyStack *)malloc(sizeof(MyStack));
        myStack->q1 = (Queues *)malloc(sizeof(Queues));
        myStack->q2 = (Queues *)malloc(sizeof(Queues));
        myStack->q1->tail = NULL;
        myStack->q1->head = NULL;
        myStack->q2->tail = NULL;
        myStack->q2->head = NULL;
        return myStack;
    }

    /** Push element x onto stack. */
    void myStackPush(MyStack* obj, int x) {
        ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
        tmp->val = x;
        tmp->next = NULL;
        obj->q2->head = obj->q2->tail = tmp;

        while (obj->q1->tail != NULL) {
            obj->q2->head->next = obj->q1->tail;
            obj->q2->head = obj->q2->head->next;

            obj->q1->tail = obj->q1->tail->next;
        }

        obj->q1->head = NULL;
        obj->q1->tail = NULL;
        while (obj->q2->tail != NULL) {
            if (obj->q1->head == NULL) {
                obj->q1->head = obj->q1->tail = obj->q2->tail;
            } else {
                obj->q1->head->next = obj->q2->tail;
                obj->q1->head = obj->q1->head->next;
            }
            obj->q2->tail = obj->q2->tail->next;
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int myStackPop(MyStack* obj) {
        ListNode *tmp = obj->q1->tail;
        obj->q1->tail = obj->q1->tail->next;
        int data = tmp->val;
        free(tmp);
        return data;
    }

    /** Get the top element. */
    int myStackTop(MyStack* obj) {
        return obj->q1->tail->val;
    }

    /** Returns whether the stack is empty. */
    bool myStackEmpty(MyStack* obj) {
        if (obj->q1->tail == NULL) {
            return true;
        } else {
            return false;
        }
    }

    void myStackFree(MyStack* obj) {
        while (obj->q1->tail != NULL) {
            ListNode *tmp = obj->q1->tail;
            obj->q1->tail = obj->q1->tail->next;
            free(tmp);
        }
    }

解法3：关键在于如何使用一个队列，使在入栈时就生成出栈顺序存储元素的队列。
假设已存在队列1,2，入队3，理论上3是出栈第一元素，所以预期目标是得到顺序是1,2,3的队列。入队是顺序为3,1,2，发现依次将2和1出队立即入队可得到效果。
第一步得到：2,3,1
第二步得到：1,2,3
出栈操作时，实际执行出队操作，获得元素3。

入栈时间复杂度O(n)

出栈时间复杂度O(1)

    typedef struct listNode {
        struct ListNode *next;
        int val;
    } ListNode;

    typedef struct {
        ListNode *tail;
        ListNode *head;
    } Queues;

    typedef struct {
        Queues *q1;
    } MyStack;



    /** Initialize your data structure here. */

    MyStack* myStackCreate() {
        MyStack *myStack = (MyStack *)malloc(sizeof(MyStack));
        myStack->q1 = (Queues *)malloc(sizeof(Queues));
        myStack->q1->tail = NULL;
        myStack->q1->head = NULL;
        return myStack;
    }

    /** Push element x onto stack. */
    void myStackPush(MyStack* obj, int x) {
        ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
        tmp->val = x;
        tmp->next = NULL;
        if (obj->q1->tail == NULL) {
            obj->q1->head = obj->q1->tail = tmp;
        } else {
            obj->q1->head->next = tmp;
            obj->q1->head = obj->q1->head->next;
        }
        while (obj->q1->tail != tmp) {
            obj->q1->head->next = obj->q1->tail;
            obj->q1->head = obj->q1->tail;
            obj->q1->tail = obj->q1->tail->next;
        }
        obj->q1->head->next = NULL;
    }

    /** Removes the element on top of the stack and returns that element. */
    int myStackPop(MyStack* obj) {
        ListNode *tmp = obj->q1->tail;
        obj->q1->tail = obj->q1->tail->next;
        int data = tmp->val;
        free(tmp);
        return data;
    }

    /** Get the top element. */
    int myStackTop(MyStack* obj) {
        return obj->q1->tail->val;
    }

    /** Returns whether the stack is empty. */
    bool myStackEmpty(MyStack* obj) {
        if (obj->q1->tail == NULL) {
            return true;
        } else {
            return false;
        }
    }

    void myStackFree(MyStack* obj) {
        while (obj->q1->tail != NULL) {
            ListNode *tmp = obj->q1->tail;
            obj->q1->tail = obj->q1->tail->next;
            free(tmp);
        }
    }