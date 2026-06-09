```
/**
*
*总体思路：
*1.快速排序数组
*2.累加下标为偶数(包含0)的元素值
*
*/

//quick sort the elements
int cmp( const void * a , const void * b ){

    return *( int * )a - *( int * )b;

}

int arrayPairSum( int * nums, int numsSize ){

    //used to save the total value
    int sum = 0;

    //quick sort the array
    qsort( nums , numsSize , sizeof( int ) , cmp );

    //adding the element's value
    for( int i = 0 ; i < numsSize ; i += 2 ){

        sum += *( nums + i ) ;

    }

    return sum;

}
```
