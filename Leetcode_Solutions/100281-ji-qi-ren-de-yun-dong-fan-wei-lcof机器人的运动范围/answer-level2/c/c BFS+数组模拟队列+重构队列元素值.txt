```

/**
*
*整体思路：
*1.申请一个模拟队列queue，大小为m * n，重构queue的数据，x * 100 + y 来存放对应的数据
*2.申请一个动态内存visit，长度为m * n,用于标记当前元素是否已访问，初始化计数器count=0，
*3.将0加入队列中，enqueue同时更新，dequeue指向队列头部，enqueue指向队列尾部 
*4.判断dequeue==enqueue是否成立，如果不成立，进入步骤，如果成立，进入步骤5
*5.进行出队操作，读取队列头部，同时更新dequeue
*6.判断当前元素的下一行元素[x+1][y]是否满足位和<=k，且不为1,
*   如果是，加入队列中，且*( *( visit + x + 1 ) + y ) = 1
*7.判断当前元素的右边元素[x][y+1]是否满足位和<=k，且不为1,
*   如果是，加入队列中，且*( *( visit + x ) + y + 1 ) = 1
*8.进入步骤4
*9.释放queue和visit，返回count
*/

/**
*Function: calculating the total value of each bits of x and y
*@param: int x : the first value ready to be calculated
*@param: int y : the second value ready to be calculated
*Return: int : the total value of each bits of x and y
*/
int bitsSum( int x , int y ){

    //the parameter of sum used to save the final result
    int sum = 0;

    while( x > 0 ){

        sum += x % 10;
        x /= 10;

    }

    while( y > 0 ){

        sum += y % 10;
        y /= 10;

    }

    return sum;

}

int movingCount( int m , int n , int k ){

    //the parameter of count used to save the number of positions which meet the condition
    int count = 0;
    //alloclating memory used to be a queue
    int * queue = ( int * )malloc( sizeof( int ) * m * n );
    //alloclating memory to mark current position
    int ** visit = ( int * )malloc( sizeof( int * ) * m );

    for( int i = 0 ; i < m ; i++ ){

        *( visit + i ) = ( int * )malloc( sizeof( int ) * n );

    }

    //the parameter of dequeue is the pointer of header
    //the parameter of enqueue is the pointer of tail
    int enqueue = 0 , dequeue = 0;

    *( queue + enqueue++ ) = 0;

    while( dequeue != enqueue ){

        //reading the value of current node
        int x = *( queue + dequeue ) / 100 , y = *( queue + dequeue ) % 100;

        count++;
        dequeue++;

        //if x + 1 and y meets the conditions, appending to the end of the queue
        if( x + 1 < m && bitsSum( x + 1 , y ) <= k && *( *( visit + x + 1 ) + y ) != 1 ){

            *( *( visit + x + 1 ) + y ) = 1;
            *( queue + enqueue++ ) = ( x + 1 ) * 100 + y;

        }

        //if x and y + 1 meets the conditions, appending to the end of the queue
        if( y + 1 < n && bitsSum( x , y + 1 ) <= k && *( *( visit + x ) + y + 1 ) != 1){

            *( *( visit + x ) + y + 1 ) = 1;
            *( queue + enqueue++ ) = x * 100 + y + 1 ;

        }

    }

    //freeing memory
    free( visit );
    free( queue );
    return count;

}
```
