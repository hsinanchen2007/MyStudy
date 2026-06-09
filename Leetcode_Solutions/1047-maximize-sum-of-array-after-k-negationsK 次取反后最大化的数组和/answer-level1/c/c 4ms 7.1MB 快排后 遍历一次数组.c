```
代码块/**
*
*整体思路：
*1.快速排序整个数组
*2.先最大限度的将数组前面的负数变成正数，
*3.判断K是否耗尽次数，如果不是，判断k为奇数，直接令sum减去2倍的当前数组最小值
*4.求余下数组的和
*/

//quick sort
int cmp( const void * a , const void * b ){

    return *( int * )a - *( int * )b;

}

int largestSumAfterKNegations( int * A , int ASize , int K ){

    //quick sort
    qsort( A , ASize , sizeof( int ) , cmp );

    //the parameter of i used to point current element in array
    //the parameter of sum used to save the total value of elements in array
    int i = 0 , sum = 0;

    //doing best to turn over the sign of number which is smaller than zero
    while( K > 0 && *( A + i ) < 0 ){

        *( A + i ) *= -1;
        sum += *( A + i++ );
        K--;

    }

    //judging the value of k, updating the value of sum according k
    if( K > 0 && K % 2 != 0 ){

        if( i > 0 && *( A + i ) >= *( A + i - 1 ) ){

            sum -= *( A + i - 1 ) * 2;

        } else {

            sum -= *( A + i ) * 2;

        }

    }

    //visiting the rest of elements in array
    for( ; i < ASize ; i++ ){

        sum += *( A + i );

    }
    
    return sum;

}
```
