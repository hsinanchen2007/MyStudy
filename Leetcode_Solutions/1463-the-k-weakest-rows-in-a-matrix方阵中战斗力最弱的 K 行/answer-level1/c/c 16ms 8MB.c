```
/**
*
*整体思路：
*1.分配动态内存，
*2.遍历数组，如果遇到当前行元素为0，则停止循环，将计数个数*100，加上对应的行数( i + 1 )存入缓冲区
*3.利用快排序，排序完毕后，对缓冲区元素进行对100取余
*
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp( const void * a , const void * b ){

    return *( int * )a - *( int * )b;

}

int * kWeakestRows( int ** mat , int matSize , int * matColSize , int k , int * returnSize ){

    //alloclating memorise to save the number of mat that is 1
    int * buffer = ( int * )malloc( sizeof( int ) * matSize );
    int len = 0;

    for( int i = 0 ; i < matSize ; i++ ){

        int k = 0;

        for( int j = 0 ; j < *( matColSize + i ) ; j++ ){

            if( *( *( mat + i ) + j ) == 1 ){

                k++;
                continue;

            }

            break;

        }

        //in order to save the row of current element, wo move the number of row to left
        *( buffer + len++ ) = ( i + 1 ) + k * 100;

    }

    //quick sort
    qsort( buffer , len , sizeof( int ) , cmp );

    //get the index of row
    for( int i = 0 ; i < len ; i++ ){

        *( buffer + i ) = *( buffer + i ) % 100 - 1;

    }

    *returnSize = k;

    return buffer;

}
```
