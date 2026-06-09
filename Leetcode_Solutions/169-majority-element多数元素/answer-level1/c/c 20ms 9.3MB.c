```
/**
*
*整体思路：
*1.分配动态内存，二维数组，一个存数值，一个存个数
*2.遍历数组，如果当前元素存在，则对计数加一，如果不存在，就申请动态内存
*3.如果某个元素值先达到数组长度一半，返回当前值
*
*/

int majorityElement( int * nums , int numsSize ){

    //alloclating memorise to save element and it's count
    int ** buffer = ( int ** )malloc( sizeof( int * ) *( numsSize / 2 + 1 ) );
    //the length of the buffer
    int len = 0;

    for( int i = 0 ; i < numsSize ; i++ ){

        //used to identify if there have this element in buffer
        int flag = 0;

        for( int j = 0 ; j < len ; j++ ){

            if( *( *( buffer + j ) + 0 ) == *( nums + i ) ){

                //the element in the buffer, adding the count
                flag = 1;
                *( *( buffer + j ) + 1 ) += 1;

                //if the number of current element bigger than half of the length, return it
                if( *( *( buffer + j ) + 1 ) > ( numsSize / 2 ) ){

                    return *( *( buffer + j ) + 0 );

                }

                break;

            }

        }

        if( flag == 1 ){

            continue;

        }

        //if current element is not in the buffer, alloclating memorise
        *( buffer + len ) = ( int * )malloc( sizeof( int ) * 2 );
        *( *( buffer + len ) + 0 ) = *( nums + i );
        *( *( buffer + len ) + 1 ) = 1;
        len++;

    }

    return *( nums + 0 );

}
```
