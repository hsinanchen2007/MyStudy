```
/**
*
*整体思路：
*1.遍历数组，求数组和
*2.利用求和公式减去数组和即可
*3.求和公式：（首项+尾项）x 个数 / 2
*
*/

int missingNumber( int * nums , int numsSize ){

    int sum = 0;

    for( int i = 0 ; i < numsSize ; i++ ){

        sum += *( nums  + i );

    }

    return ( ( ( numsSize + 1 ) * numsSize ) / 2 ) - sum;

}
```
