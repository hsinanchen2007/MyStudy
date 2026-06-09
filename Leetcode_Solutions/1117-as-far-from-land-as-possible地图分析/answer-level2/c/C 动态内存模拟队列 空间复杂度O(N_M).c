```
/**
*数据说明：
*每个整形queue存储说明：32 31 30 ... 4,3位：用于存放x坐标，2 1 0位：用于存放y坐标
* dequeue时：x = *( queue + 0 ) / 1000 , y =  x = *( queue + 0 ) % 1000
* enqueue时:*( queue + 0 ) + x * 1000 + y
* 
*整体思路：
*1.申请长度为*( gridColSize + 0 ) * gridSize长度的动态缓冲区queue，模拟队列，enqueue指向
*  queue右端模拟进队列，dequeue指向queue左端，模拟出队列
*2.将所有的陆地存入queue
*3.如果队列queue为NULL，或者不全为陆地，释放queue，返回-1
*4.判断队列是否为空，即dequeue!=enqueue?，若果不为NULL，进入步骤5，否则进入步骤7
*5.遍历所有队列元素，同时将队列元素所代表的坐标邻近元素全部置1，标记为已访问
*6.步数增一，如果进入步骤4，
*7.释放queue，返回-1
*/

int maxDistance( int ** grid , int gridSize , int * gridColSize ){

    //alloclating memory to save the points which ready to be visited
    int * queue = ( int * )malloc( sizeof( int ) * ( *( gridColSize + 0 ) * gridSize ) );
    //the parameter of enqueue points to the right of queue
    //the parameter of dequeue points to the left of queue
    int enqueue = 0 , dequeue = 0 , dis = 1;

    //saving the position of points which are land to queue
    for( int i = 0 ; i < gridSize ; i++ ){

        for( int j = 0 ; j < *( gridColSize + i ) ; j++ ){

            if( *( *( grid + i ) + j ) == 1 ){

                *( queue + enqueue++ ) = i * 1000 + j ;

            }

        }

    }

    //if all the points are ocean or land, returning -1
    if( enqueue == 0 || enqueue == *( gridColSize + 0 ) * gridSize ){

        free( queue );
        return -1;

    }

    //visiting the elements in the queue
    while( dequeue != enqueue ){

        for( int i = enqueue - dequeue ; i > 0 ; i-- , dequeue++ ){

            int x = *( queue + dequeue ) / 1000 , y = *( queue + dequeue ) % 1000;

            //checking the former point which in the same column
            if( x > 0 && *( *( grid + x - 1 ) + y ) == 0 ){

                *( queue + enqueue++ ) = ( x - 1 ) * 1000 + y ;
                *( *( grid + x - 1 ) + y ) = 1;

            }

            //checking the next point which in the same column
            if( x < gridSize - 1 && *( *( grid + x + 1 ) + y ) == 0 ){

                *( queue + enqueue++ ) = ( x + 1 ) * 1000 + y ;
                *( *( grid + x + 1 ) + y ) = 1;

            }

            //checking the former point which in the same row
            if( y > 0 && *( *( grid + x ) + y - 1 ) == 0 ){

                *( queue + enqueue++ ) = x * 1000 + y - 1 ;
                *( *( grid + x ) + y - 1 ) = 1;

            }

            //checking the next point which in the same row
            if( y < *( gridColSize + 0 ) - 1 && *( *( grid + x ) + y + 1 ) == 0 ){

                *( queue + enqueue++ ) = x * 1000 + y + 1 ;
                *( *( grid + x ) + y + 1 ) = 1;

            }

        }

        //updating the value of distance
        dis++;

    }

    free( queue );
    return dis - 2;

}
```
