惭愧，刚开始没理解题目，理解了后想到了得用两个栈，但是是在添加的时候每次对两个栈进行操作，想想特别麻烦。最后看了题解恍然大悟。

自定义了一个数组实现的栈，实际上来并不严谨，可能会存在数组大小的问题，不过此题栈的实现非重点，所以就忽略了。

两种解法过程其实相差不大，解法2优化了Pop操作。
解法1所有的数据都存在在s1内，s2仅仅是Pop的时候，作为临时空间进行中转操作，每次Pop一个元素，需要进行O(n)的时间复杂度，先从s1->s2，再将s2->s1。

解法2优化了这步操作，第一次Pop时，将s1内的元素全部放入到s2内，如s1:1,2,3 => s2:3,2,1。后续Push元素到s1，Pop时从s2取栈顶数据，除了s2为空需要从s1拿数据的时候，时间复杂度仅为O(1)。


解法1：

    typedef struct stack {
        int data[100];
        int index;
    } Stack;

    typedef struct {
        Stack *s1;
        Stack *s2;
        int front;
    } MyQueue;

    /** Initialize your data structure here. */

    MyQueue* myQueueCreate() {
        MyQueue *myQueue = (MyQueue *)malloc(sizeof(MyQueue));
        myQueue->s1 = (Stack *)malloc(sizeof(Stack));
        myQueue->s2 = (Stack *)malloc(sizeof(Stack));
        myQueue->s1->index = -1;
        myQueue->s2->index = -1;
        return myQueue;
    }

    /** Push element x to the back of queue. */
    void myQueuePush(MyQueue* obj, int x) {
        if (obj->s1->index == -1) {
            obj->front = x;
        }
        obj->s1->data[++obj->s1->index] = x;
    }

    /** Removes the element from in front of queue and returns that element. */
    int myQueuePop(MyQueue* obj) {
        int i;

        obj->s2->index = -1;
        for (i=obj->s1->index; i>=0; i--) {
            obj->s2->data[++obj->s2->index] = obj->s1->data[obj->s1->index--];
        }
        int data = obj->s2->data[obj->s2->index--];

        if (obj->s2->index >= 0) {
            obj->front = obj->s2->data[obj->s2->index];
        }

        obj->s1->index = -1;
        for (i=obj->s2->index; i>=0; i--) {
            obj->s1->data[++obj->s1->index] = obj->s2->data[obj->s2->index--];
        }

        return data;
    }

    /** Get the front element. */
    int myQueuePeek(MyQueue* obj) {
        return obj->front;
    }

    /** Returns whether the queue is empty. */
    bool myQueueEmpty(MyQueue* obj) {
        if (obj->s1->index >= 0) {
            return false;
        } else {
            return true;
        }
    }

    void myQueueFree(MyQueue* obj) {
        obj->s1->index = -1;
    }



解法2：

    typedef struct stack {
        int data[100];
        int index;
    } Stack;

    typedef struct {
        Stack *s1;
        Stack *s2;
        int front;
    } MyQueue;

    /** Initialize your data structure here. */

    MyQueue* myQueueCreate() {
        MyQueue *myQueue = (MyQueue *)malloc(sizeof(MyQueue));
        myQueue->s1 = (Stack *)malloc(sizeof(Stack));
        myQueue->s2 = (Stack *)malloc(sizeof(Stack));
        myQueue->s1->index = -1;
        myQueue->s2->index = -1;
        return myQueue;
    }

    /** Push element x to the back of queue. */
    void myQueuePush(MyQueue* obj, int x) {
        if (obj->s1->index == -1) {
            obj->front = x;
        }
        obj->s1->data[++obj->s1->index] = x;
    }

    /** Removes the element from in front of queue and returns that element. */
    int myQueuePop(MyQueue* obj) {
        if (obj->s2->index < 0) {
            int i;
            for (i=obj->s1->index; i>=0; i--) {
                obj->s2->data[++obj->s2->index] = obj->s1->data[obj->s1->index--];
            }
        }
        return obj->s2->data[obj->s2->index--];

    }

    /** Get the front element. */
    int myQueuePeek(MyQueue* obj) {
        if (obj->s2->index >= 0) {
            return obj->s2->data[obj->s2->index];
        } else {
            return obj->front;
        }
    }

    /** Returns whether the queue is empty. */
    bool myQueueEmpty(MyQueue* obj) {
        if (obj->s1->index >= 0 || obj->s2->index >= 0) {
            return false;
        } else {
            return true;
        }
    }

    void myQueueFree(MyQueue* obj) {
        obj->s1->index = -1;
        obj->s2->index = -1;
    }