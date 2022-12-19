```
/**
*
*整体思路：
*1.快速排序，
*2.先判断第一个元素是否仅出现一次，遍历数组，将当前元素与其前后元素比较，看是否唯一，
*  唯一时返回当前元素
*3.返回最后一个元素
*
*/

int cmp( const void * a , const void * b ){

    return *( int * )a - *( int * )b;

}

int singleNumber( int * nums , int numsSize ){

    //quick sort
    qsort( nums , numsSize , sizeof( int ) , cmp );

    //judging the length of the array
    if( numsSize == 1 ){

        return *( nums + 0 );

    }

    //judging the first element
    if( *( nums + 0 ) != *( nums + 0 + 1 ) ){

        return *( nums + 0 );

    }

    for( int i = 1 ; i < numsSize - 1 ; i++ ){

        //judging current by former and next element, if unique, return current 
        //element
        if( *( nums + i ) != *( nums + i + 1 ) && *( nums + i - 1 ) != *( nums + i ) ){

            return *( nums + i );

        }

    }

    return *( nums + numsSize - 1 );

}
```
