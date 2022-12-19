```
/**
*
*双指针法:
*维护两个指针，一个是遍历的指针，一个是待存储的指针
*
*/

int removeElement( int * nums , int numsSize , int val ){

    //the updating array's pointer
    int index = 0;

    for( int i = 0 ; i < numsSize ; i++ ){

        if( *( nums + i ) == val ){

            continue;

        }

        *( nums + index++ ) = *( nums + i );

    }

    return index;

}
```
