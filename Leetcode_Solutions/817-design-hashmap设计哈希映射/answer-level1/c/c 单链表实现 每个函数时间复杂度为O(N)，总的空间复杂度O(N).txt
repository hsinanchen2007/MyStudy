```
/**
*
*整体思路：
*1.单链表实现哈希映射
*
*/

typedef struct MyHashMap {

    int key;
    int val;
    struct MyHashMap * next;
    
} MyHashMap;

/** Initialize your data structure here. */

MyHashMap* myHashMapCreate() {

    MyHashMap * obj = ( MyHashMap * )malloc( sizeof( MyHashMap ) * 1 );
    obj -> key = -1;
    obj -> val = -1;
    obj -> next = NULL;
    
    return obj;

}

/** value will always be non-negative. */
void myHashMapPut( MyHashMap * obj , int key , int value ) {

    MyHashMap * tmp = obj;
    MyHashMap * form = obj;

    while( tmp != NULL ){

        if( tmp -> key == key ){

            tmp -> val = value;
            return ;

        }

        form = tmp;
        tmp = tmp -> next;

    }

    tmp = ( MyHashMap * )malloc( sizeof( MyHashMap ) * 1 );
    tmp -> next = NULL;
    tmp -> key = key;
    tmp -> val = value;
    form -> next = tmp;
  
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet( MyHashMap * obj , int key) {

    MyHashMap * tmp = obj;

    while( tmp != NULL ){

        if( tmp -> key == key ){

            return tmp -> val;

        }

        tmp = tmp -> next;

    }

    return -1;

}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove( MyHashMap * obj, int key ) {

    MyHashMap * tmp = obj;
    MyHashMap * form = obj;

    while( tmp != NULL ){

        if( tmp -> key == key ){

            form -> next = tmp -> next;
            free( tmp );
            break;

        }

        form = tmp;
        tmp = tmp -> next;

    }
  
}

void myHashMapFree( MyHashMap * obj ) {

    while( obj != NULL ){

        MyHashMap * tmp = obj;
        obj = obj -> next;
        free( tmp );

    }

}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/
```
