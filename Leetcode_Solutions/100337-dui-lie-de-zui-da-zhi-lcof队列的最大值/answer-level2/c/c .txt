```
/**
*
*整体思路：
*1.保存着队列头尾，最大值，以及队列的长度
*2.如果遇到push操作，就直接在队尾tail添加
*3.如果遇到pop操作，被出队的节点是最大值节点，就调用寻找最大值函数，重新找出队列的最大值
*
*/


typedef struct Node{

    int val;
    struct Node * next;

} Node;

typedef struct {

    Node * head;
    Node * tail;
    int size;
    int max_val;

} MaxQueue;

bool isEmpty( MaxQueue * obj ){

    if( obj -> size == 0 ){

        return true;

    }

    return false;

}

MaxQueue * maxQueueCreate() {

    MaxQueue * obj = ( MaxQueue * )malloc( sizeof( MaxQueue ) * 1 );
    obj -> head = NULL;
    obj -> tail = NULL;
    obj -> size = 0;
    obj -> max_val = -1;

    return obj;

}

int maxQueueMax_value( MaxQueue* obj ) {

    return obj -> max_val;

}

void maxQueuePush_back( MaxQueue * obj , int value ) {

    Node * node = ( Node * )malloc( sizeof( Node ) * 1 );
    node -> val = value;
    node -> next = NULL;

    if( value > obj -> max_val ){

        obj -> max_val = value;

    }

    if( isEmpty( obj ) ){

        obj -> head = node;
        obj -> tail = node;
        obj -> size = 1;

    } else {

        obj -> tail -> next = node;
        obj -> tail = node;
        obj -> size++;

    }

}

int maxQueuePop_front( MaxQueue * obj ) {

    if( !isEmpty( obj ) ){

        Node * tmp = obj -> head;
        obj -> head = obj -> head -> next;


        if( tmp -> val == obj -> max_val ){

            findMaxValue( obj );

        }

        int value = tmp -> val;

        free( tmp );
        obj -> size--;

        return value;

    }

    return -1;

}

void findMaxValue( MaxQueue * obj ){

    Node * tmp = obj -> head;
    obj -> max_val = -1;

    while( tmp != NULL ){

        if( obj -> max_val < tmp -> val ){

            obj -> max_val = tmp -> val;

        }

        tmp = tmp -> next;

    }

}

void maxQueueFree( MaxQueue * obj ) {

    if( !isEmpty( obj ) ){

        Node * curr = obj -> head;

        while( curr != NULL ){

            Node * form = curr;
            curr = curr -> next;
            free( form ); 

        }

        free( obj );

    }

}

/**
 * Your MaxQueue struct will be instantiated and called as such:
 * MaxQueue* obj = maxQueueCreate();
 * int param_1 = maxQueueMax_value(obj);
 
 * maxQueuePush_back(obj, value);
 
 * int param_3 = maxQueuePop_front(obj);
 
 * maxQueueFree(obj);
*/
```
