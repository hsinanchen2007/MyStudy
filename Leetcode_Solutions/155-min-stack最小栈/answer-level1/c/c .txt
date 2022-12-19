```
typedef struct Node {

    int val;
    struct Node * next;

} Node;

typedef struct {

    Node * base;
    Node * top;
    int size;

} MinStack;

/** initialize your data structure here. */

bool isEmpty( MinStack * obj ){

    if( obj -> size == 0 ){

        return true;

    }

    return false;

}

MinStack* minStackCreate() {

    MinStack * obj = ( MinStack * )malloc( sizeof( MinStack ) * 1 );
    obj -> base = ( Node * )malloc( sizeof( Node ) * 1 );
    obj -> base -> next = NULL;
    obj -> top = obj -> base;
    obj -> size = 0;

    return obj;

}

void minStackPush( MinStack * obj , int x ) {

    obj -> top -> val = x;
    Node * tmp = ( Node * )malloc( sizeof( Node ) * 1 );
    tmp -> next = obj -> top;
    obj -> top = tmp;
    obj -> size++;

}

void minStackPop( MinStack * obj ) {

    if( !isEmpty( obj ) ){

        Node * tmp = obj -> top;
        obj -> top = tmp -> next;
        free( tmp );
        tmp = NULL;
        obj -> size--;  

    }

}

int minStackTop( MinStack * obj ) {

    if( !isEmpty( obj ) ){

        return obj -> top -> next -> val;

    }
    
    return -1;

}

int minStackGetMin( MinStack * obj ) {

    Node * tmp = obj -> top -> next;
    int min = 2147483647;
    
    while( tmp != NULL ){

        if( min > tmp -> val ){

            min = tmp -> val;

        }

        tmp = tmp -> next;

    }

    return min;

}

void minStackFree( MinStack * obj ) {

    free( obj );

}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
```
