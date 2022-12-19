```
/**
*
*整体思路：
*1.按列遍历数组，
*2.遇到前一行比后一行大时，就计数加一
*
*/

int minDeletionSize( char ** A , int ASize ){

    //the param is used to save the number of the column that is not meet the conditions
    int count = 0 ;

    for( int j = 0 ; j < strlen( *( A + 0 ) ) ; j++ ){

        for( int i = 0 ; i < ASize - 1 ; i++ ){

            if( *( *( A + i ) + j ) > *( *( A + i + 1 ) + j ) ){

                count++;
                break;

            }

        }

    }

    return count;

}


/***********************附上对A进行修改的扩展程序****************************
*
*整体思路
*1.建立一个临时缓冲区，依据列进行操作，长度为原始子字符串大小
*2.依据列遍历数组，如果当前行ASCII码大于下一行，则记录到缓冲区中
*3.遍历结束后，依据缓冲区标志位，遍历每一行子字符串，删除对应的元素
*

int minDeletionSize( char ** A , int ASize ){

    //the param of index is used to move the pointer
    int index = 0 , len = strlen( *( A + 0 ) );
    //marking current column whether need to be deleted
    int * buffer = ( int * )malloc( sizeof( int ) * len );

    for( int j = 0 ; j < len ; j++ ){

        *( buffer + j ) = 0;

        for( int i = 0 ; i < ASize - 1 ; i++ ){

            if( *( *( A + i ) + j ) > *( *( A + i + 1 ) + j ) ){

                //changing the flag
                *( buffer + j ) = 1;
                break;

            }

        }

    }

    //updating the array
    for( int i = 0 ; i < ASize ; i++ ){

        index = 0;

        for( int j = 0 ; j < len ; j++ ){

            if( *( buffer + j ) == 1 ){

                continue;

            }

            *( *( A + i ) + index++ ) = *( *( A + i ) + j )

        }

        *( *( A + i ) + index++ ) = '\0';

    }

    return 0;

}

*/

```
