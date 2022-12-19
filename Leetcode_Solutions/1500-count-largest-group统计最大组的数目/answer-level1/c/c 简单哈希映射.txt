```
/**
*
*整体思路：
*1.申请一个长度为n的动态缓冲区buf，用做简单的哈希映射，用一个变量max记录出现的最大和，count记录最大和
* 的个数
*2.遍历1-n的数据，
*3.计算每个数各位的和sum，通过sum直接映射到*( buf + sum - 1 )的元素，如果未存储过数据，
* 就对该位置进行初始化，否则更新*( buf + sum - 1 ) += 1，
*4.判断*( buf + sum - 1 )是否大于max，如果是，更新max，初始化count=1,
*  如果max==*( buf + sum - 1 )，更新count++，
*5.释放缓冲区，返回count
*/

int countLargestGroup( int n ){

    //alloclating memory to save the number of value of sum
    int * buf = ( int * )malloc( sizeof( int ) * n );
    //the parameter of max used to save the maximun of element in buf
    //the parameter of count used to save the number of max in element
    int max = 0 , count = 1;

    //visiting from 1 to n
    for( int i = 1 ; i <= n ; i++ ){

        //the parameter of sum used to save the total value of each bits of sum
        int tmp = i , sum = 0;

        while( tmp > 0 ){

            sum += tmp % 10;
            tmp /= 10;

        }

        //updating the value of *( buf + sum - 1 )
        if( *( buf + sum - 1 ) < 0 ){

            *( buf + sum - 1 ) = 1;

        } else {

            *( buf + sum - 1 ) += 1;


        }

        //comparing the value of *( buf + sum - 1 ) to max
        if( *( buf + sum - 1 ) > max ){
            
            //if *( buf + sum - 1 ) bigger than max, updating max and count
            max = *( buf + sum - 1 );
            count = 1;

        } else if( *( buf + sum - 1 ) == max ){

            count++;

        }

    }

    //freeing buf
    free( buf );

    return count;

}
```
