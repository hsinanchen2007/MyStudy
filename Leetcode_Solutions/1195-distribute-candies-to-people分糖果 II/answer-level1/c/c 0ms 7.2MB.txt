```
/**
*
*整体思路：
*1.设置当前糖果分发数的缓存变量，
*2.依次分发糖果，如果分发糖果数大于总数，则只发最后的糖果数
*3.如果指针超出长度，重新回到起点
*
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * distributeCandies( int candies , int num_people , int * returnSize){

    //alloclating the memorise
    int * buffer = ( int * )malloc( sizeof( int ) * num_people );
    //current need to alloclating candies, the parameter of index is the pointer
    int count = 1 , index = 0;

    for( int i = 0 ; i < num_people ; i++ ){

        *( buffer + i ) = 0;

    }

    while( candies > 0 ){

        count = count > candies ? candies : count;
        *( buffer + index++ ) += count;
        candies -= count;
        count++;
        //if index surpass the length of buffer, it will return to 0
        index = index % num_people;
            

    }

    *returnSize = num_people;

    return buffer;

}
```
