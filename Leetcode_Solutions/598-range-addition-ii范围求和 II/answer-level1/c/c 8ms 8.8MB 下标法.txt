```
/**
*
*整体思路：
*1.如果opsSize=0，返回m*n
*2.遍历数组，如果当前更新的坐标点的横坐标小于最小横坐标row，更新row
*3.遍历数组，如果当前更新的坐标点的纵坐标小于最小横坐标col，更新col
*4.返回row * col
*
*/

int maxCount( int m , int n , int ** ops , int opsSize , int * opsColSize ){

    //if the length of ops less than 1, return m * n
    if( opsSize < 1 ){

        return m * n;

    }

    //the parameter of row used to save the minimun of row in ops
    //the parameter of col used to save the minimun of column in ops
    int row = *( *( ops + 0 ) + 0 ) , col = *( *( ops + 0 ) + 1 );

    //visiting the elements in ops
    for( int i = 1 ; i < opsSize ; i++ ){

        //if current element is smaller than row, updating row
        if( row > *( *( ops + i ) + 0 ) ){

            row = *( *( ops + i ) + 0 );

        }

        //if current element is smaller than col, updating col
        if( col > *( *( ops + i ) + 1 ) ){

            col = *( *( ops + i ) + 1 );

        }

    }

    return row * col;

}
```
