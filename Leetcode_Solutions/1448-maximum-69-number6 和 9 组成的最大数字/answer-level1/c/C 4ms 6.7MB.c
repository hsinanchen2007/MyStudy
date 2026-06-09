```
/**
*
*总体思路：
*1.遍历每一位
*2.如果当前位为6，记录当前权值，
*3.循环步骤2，直到不满足
*4.判断是否存在6,否则返回,如果存在，翻转6
*/

int maximum69Number ( int num ){

    //save the prority of the number
    int count = 1;
    //memorise the position of number on the left
    int tmp = 0;

    while( ( num / count ) != 0 ){
        
        //if current number is 6, memorise it prority
        if( ( ( num / count ) % 10 ) == 6 ){

            tmp = count;

        }

        //move to next value
        count *= 10;

    }

    //if there is a number that is 6, turn over the number
    if( tmp != 0 ){

        num -= ( 6 * tmp );
        num += ( 9 * tmp );

    }
    

    return num;

}
```
