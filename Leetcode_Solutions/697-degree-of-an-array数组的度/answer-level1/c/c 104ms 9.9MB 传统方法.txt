```
/**
* ... 8 7 6 5 4 3 2 1 0  5到更高位存放：j,频次 j+1:最大下标 0-4位：j,数值 起始下标
*解题思路：暴力法
*1.申请的动态内存，用于存放数值，频次，起始下标和终下标
*2.遍历数组，查找表，如果存在表中，更新频次，更新终止坐标，判断是否需要更新最大频次
*3. 如果不在表中，添加到表中
*4.遍历表，在最大频次中，查找最短子数组
*/

int findShortestSubArray( int * nums , int numsSize ){

    //if the length of array is less than 2
    if( numsSize <= 1 ){

        return numsSize;

    }

    //alloclating memory to save the data
    int * buffer = ( int * )malloc( sizeof( int ) * numsSize * 2 );
    //the parameter of len is length of buffer
    //the parameter of max is the maximal frequence of number in array
    //the parameter of min is the minimal length of subarray
    int len = 0 , max = 1 , min = 50000;

    //visiting array
    for( int i = 0 ; i < numsSize ; i++ ){

        char flag = '1';

        //visiting the table to determine whether current elements is in the table 
        for( int j = 0 ; j < len ; j += 2 ){

            //if current element is in the table, updating frequence and the value of max
            if( *( nums + i ) == *( buffer + j ) % 50000 ){
                           
                flag = '0';
                *( buffer + j ) += 1 * 50000;
                *( buffer + j + 1 ) /= 50000;
                *( buffer + j + 1 ) = *( buffer + j + 1 ) * 50000 + i;

                if( *( buffer + j ) / 50000 > max ){

                    max = *( buffer + j ) / 50000;

                }

                break;

            }

        }

        if( flag == '0' ){

            continue;

        }

        //if current element is not in the table, appending to the table
        *( buffer + len ) = *( nums + i ) + 1 * 50000;
        *( buffer + len + 1 ) = i * 50000 + i;
        len += 2;

    }

    //visiting the table to find the minimun of length
    for( int i = 0 ; i < len ; i += 2 ){

        if( max == *( buffer + i ) / 50000 
            && min > *( buffer + i + 1 ) % 50000 - *( buffer + i + 1 ) / 50000 ){

            min = *( buffer + i + 1 ) % 50000 - *( buffer + i + 1 ) / 50000;
        
        }

    }

    //freeing buffer
    free( buffer );

    return min + 1;

}
```
