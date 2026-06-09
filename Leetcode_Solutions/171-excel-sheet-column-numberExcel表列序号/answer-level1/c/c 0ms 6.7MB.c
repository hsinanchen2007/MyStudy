```
/**
*
*整体思路：
*1.从左往右遍历字符数组，权值为26，
*
*/

int titleToNumber( char * s ){

    //the parameter of count is used to save the result
    int count = 0;

    for( int i = 0 ; *( s + i ) != '\0' ; i++ ){

        //the priority is 26
        count = count * 26 + ( *( s + i ) - 64 );

    }

    return count;

}
```
