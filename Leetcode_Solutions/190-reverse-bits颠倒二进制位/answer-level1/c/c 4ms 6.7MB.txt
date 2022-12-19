```
/**
*
*整体思路：
*1.直接循环32次
*
*/

uint32_t reverseBits( uint32_t n ) {
    
    uint32_t tmp = 0 , count = 0;

    while( count < 32 ){

        tmp = tmp * 2 + n % 2;
        n /= 2;
        count++;

    }

    return tmp;

}
```
