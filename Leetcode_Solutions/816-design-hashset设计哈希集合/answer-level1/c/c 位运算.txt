```

typedef struct MyHashSet{

    unsigned int key;

} MyHashSet;


/** Initialize your data structure here. */

MyHashSet* myHashSetCreate() {

    MyHashSet * obj = ( MyHashSet * )malloc( sizeof( MyHashSet ) * 31250 );

    for( int i = 0 ; i < 31250 ; i++ ){

        obj[ i ].key = 0;

    }

    return obj;
    
}

void myHashSetAdd( MyHashSet * obj, int key ) {

    unsigned int k = 1;
    int tmp = key % 32;

    if( tmp > 0 && tmp < 32 ){

        k <<= tmp;

    }

    obj[ key / 32 ].key |= k;

}

void myHashSetRemove( MyHashSet * obj , int key ) {

    unsigned int k = 1;
    int tmp = key % 32;

    if( tmp > 0 && tmp < 32 ){

        k <<= tmp;

    }

    k = ~k;

    obj[ key / 32 ].key &= k;

}

/** Returns true if this set contains the specified element */
bool myHashSetContains( MyHashSet * obj , int key ) {

    unsigned int k = obj[ key / 32 ].key;
    int tmp = key % 32;

    if( tmp > 0 ){

        k >>= tmp;

    }

    if( k % 2 == 1 ){

        return true;

    }

    return false;
 
}

void myHashSetFree( MyHashSet * obj ) {

    free( obj );

}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/
```
