```
/**
*
*整体思路：
*1.快速排序
*2.遍历排序后的元素，计算每个类型元素，如果某一个元素的count>numsSize，则返回当前元素
*3.返回最后一个元素*( nums + numsSize - 1 )
*/

//quick sort
int cmp( const void * a , const void * b ){

    return *( int * )a - *( int * )b;

}

int majorityElement( int * nums , int numsSize ){

    //quick sort
    qsort( nums , numsSize , sizeof( int ) , cmp );

    //the parameter of count used to calculatr the number of current element in nums
    int count = 1;

    for( int i = 1 ; i < numsSize ; i++ ){

        //if the value of current element equals to the value of former element,
        //updating the value of count 
        if( *( nums + i - 1 ) == *( nums + i ) ){

            count++;
            continue;

        }

        //if the velue of count bigger than numsSize / 2
        if( count > ( numsSize / 2 ) ){

            return *( nums + i - 1 );

        }

        //intializing count
        count = 1;

    }

    return *( nums + numsSize - 1 );

}

```
