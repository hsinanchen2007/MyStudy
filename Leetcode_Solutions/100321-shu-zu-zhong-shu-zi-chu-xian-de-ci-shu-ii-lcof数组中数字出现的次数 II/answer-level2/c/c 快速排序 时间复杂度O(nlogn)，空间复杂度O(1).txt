```
/**
*
*整体思路：
*1.快速排序数组nums
*2.从下标为1的元素开始，遍历数组，
*3.如果当前i指向的元素和i-1指向的元素相同，则计数器count加1，更新i，进入步骤3
*4.如果i与i-1指向的元素不同，判断count是否为1，如果是，返回i-1指向的元素，否则进入步骤5
*5.重置计数器count=1，更新i，进入步骤3
*6.返回numsSize - 1指向的元素
*/

//quick sort
int cmp( const void * a , const void * b ){

    return *( int * )a - *( int * )b;

}

int singleNumber( int * nums, int numsSize){

    //quick sort
    qsort( nums , numsSize , sizeof( int ) , cmp );

    //the parameter of count used to calculate then number of different elements in nums
    int count = 1;

    for( int i = 1 ; i < numsSize ; i++ ){

        //if the value of current element equals to the value of former element, continuing
        if( *( nums + i ) == *( nums + i - 1 ) ){

            count++;
            continue;

        }

        //if the value of count is 1, returning former element in nums
        if( count == 1 ){

            return *( nums + i - 1 );

        }

        //intializing count
        count = 1;

    }

    //returning the last element in nums
    return *( nums + numsSize - 1 );

}
```
