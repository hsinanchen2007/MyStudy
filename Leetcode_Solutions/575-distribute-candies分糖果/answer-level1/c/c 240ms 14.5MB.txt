```
/**
*
*整体思路：
*1.先快速排序数组，
*2.维护妹妹得到的最后一个类型糖果的临时变量，遍历糖果数组比较临时糖果，
* 如果没有该糖果，就给妹妹，
*3.重复2，直到妹妹糖果达到上限或者没其他类型糖果
*
*/

int cmp( const void * a , const void * b ){

    return *( int * )a - *( int * )b;

}

int distributeCandies(int* candies, int candiesSize){

    //quick sort the candies
    qsort( candies , candiesSize , sizeof( int ) , cmp );
    //the first candy is belonging to sister
    int count = 1;
    //the parameter of tmp is used mark the last type of candy that 
    //is belonging to sister  
    int tmp = *( candies + 0 );

    for( int i = 1 ; i < candiesSize && count < ( candiesSize / 2 ) ; i++ ){

        //if sister does not have this type of candy,
        if( tmp == *( candies + i ) ){

            continue;

        }
    
        tmp = *( candies + i );
        count++;

    }

    return count;

}
```
