```
/**
*
*整体思路：
*1.快速排序原数组
*2.从下标为1开始遍历数组，
*3.比较i与i-1元素是否相同，如果是，直接返回i元素，否则更新i，继续步骤3，直到i==numsSize时进入步骤4
*4.返回-1
*/

//quick sort
int cmp( const void * a , const void * b ){

    return *( int * )a - *( int * )b;

}

int findRepeatNumber( int * nums , int numsSize ){

    //quick sort
    qsort( nums , numsSize , sizeof( int ) , cmp );

    //visiting array
    for( int i = 1 ; i < numsSize ; i++ ){

        //if the value of current element equals to the value of former element, returning
        //the value of current element  
        if( *( nums + i ) == *( nums + i - 1 ) ){

            return *( nums + i );

        }

    }

    return -1;

}
```

方法二：哈希映射，时间复杂度O(N)，空间复杂度O(N)

```
/**
*
*整体思路：
*1.申请长度为numsSize的缓冲区buffer，初始化所有元素的值为0
*2.遍历数组，根据元素*( nums + i )映射到buffer对应存储位置，判断是否等于1，如果是，释放缓冲区
*  返回*( nums + i )；如果不是，更新*( buffer + *( nums + i ) ) += 1,继续下一趟遍历
*3.释放缓冲区，返回-1
*
*/

int findRepeatNumber( int * nums , int numsSize ){

    //alloclating memory to save the hashSet
    int * buffer = ( int * )malloc( sizeof( int ) * numsSize );

    //intializing the memory
    for( int i = 0 ; i < numsSize ; i++ ){

        *( buffer + i ) = 0;

    }

    //visiting array, and saving the number of current element in array
    for( int i = 0 ; i < numsSize ; i++ ){

        //if the value of *( buffer + *( nums + i ) ) == 1, returning the value current
        //element in nums
        if( *( buffer + *( nums + i ) ) == 1 ){

            free( buffer );
            return *( nums + i );

        }

        *( buffer + *( nums + i ) ) += 1;

    }

    free( buffer );

    return -1;

}
```

