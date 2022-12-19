```
/**
*
*整体思路：
*1.如果n<0，直接返回false
*2.用无符号整形i，初始化为1，
*3.判断i<=n，则进入循环，进入步骤6
*4.如果i==n，返回true
*5.左移一位，进入步骤3
*6.返回false
*/

bool isPowerOfTwo( int n ){

    //if the vlaue of n smaller than zero, returning false
    if( n < 0 ){

        return false;

    }

    //the parameter of i is binary
    unsigned int i = 1;

    while( i <= n ){

        //if cthe value of urrent i equals to n, returning true 
        if( i == n ){

            return true;

        }

        //moving one bit to left
        i <<= 1;

    }

    //returning false
    return false;

}
```
