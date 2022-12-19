```
/**
*
*整体思路：
*1.利用一个变量32位的tmp=1，
*2.循环32次，判断tmp&n是否大于0，如果是，证明n当前位为1，计数器加一
*3.左移一位
*.返回计数器count
*/

int hammingWeight( uint32_t n ) {
    
    //the parameter of count used to svae the number of 1 in n
    int count = 0;
    //the parameter of tmp used to check current bit in n
    uint32_t tmp = 1;

    for( int i = 0 ; i < 32 ; i++ ){

        //if the value of tmp&n bigger than 0, which mweans that current bit is 1 in n, 
        //updating the value of count
        if( ( tmp & n ) > 0 ){

            count++;

        }

        tmp <<= 1;

    } 

    return count;

}
```
