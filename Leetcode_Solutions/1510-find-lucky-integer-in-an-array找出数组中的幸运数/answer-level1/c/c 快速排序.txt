```

/**
*
*整体思路：
*1.从大到小快排所有元素，初始化计数器num = 1
*2.遍历排序后的数组，比较前后元素是否相同，如果相同，计数器加1
*3.如果不同，比较num是否等于对应的值，如果是，返回元素值，如果不是，初始化计数器num = 1，进入下一趟
*4.判断num与数组最后一个元素的关系，如果满足，直接返回最后一个元素
*5.返回-1
*/

//quick sort
int cmp( const void * a , const void * b ){

    return *( int * )b - *( int * )a;

}

int findLucky( int * arr, int arrSize ){

    //quick sort
    qsort( arr , arrSize , sizeof( int ) , cmp );
    //the parameter of num used to save the frequency of element in arr
    int num = 1;

    //visiting array
    for( int i = 1 ; i < arrSize ; i++ ){

        //if the value of current element equals to former element updating num 
        if( *( arr + i ) == *( arr + i - 1 ) ){

            num++;
            continue;

        }

        //if the frequency of former element equals to the value of former element, 
        //returning former element
        if( *( arr + i - 1 ) == num ){

            return *( arr + i - 1 );

        }

        //intilizing the value of num
        num = 1;

    }

    //judging the last element in array
    if( *( arr + arrSize - 1 ) == num ){

        return *( arr + arrSize - 1 );

    }

    return -1;

}
```
