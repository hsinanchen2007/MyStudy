```
/**
*
*整体思路：分治(注意观察，[ 2n*k, (2n+1)*k-1 ]范围内需要逆序，偶数k倍起点，奇数k倍-1终点)
*1.首先判断前k段是否满足k<len，如果满足，令j=len-1
*2.在i-j之间进行逆序操作，完成逆序后
*3.更新j的值，是否在字符串的范围内，如果不是，则令j=len-1，如果是则更新为j=count*k-1
*4.更新i的值为k的偶数倍末尾
*/

char * reverseStr(char * s, int k){

    //the parameter of len is used to save the length of string s
    int len = strlen( s );

    //if s is  NULL, return s
    if( len == 0 ){

        return s;

    }

    //the parameter of count is used to point the starting and edning of substring
    //the parameter of j is used to point the end of the segment of substring
    int count = 1 , j = k - 1;

    //making sure the parameter of j is legal in string s
    j = j < len ? j : len - 1;


    for( int i = 0 ; i < len ; ){

        //reversing the substring
        while( i < j ){

            char ch = *( s + i );
            *( s + i++ ) = *( s + j );
            *( s + j-- ) = ch;

        }

        //point to next segment
        count += 2;
        //updating j, and making sure is legal in substring
        j = count * k - 1;
        j = j < len ? j : len - 1;
        i = ( count - 1 ) * k;

    }

    return s;

}
```
