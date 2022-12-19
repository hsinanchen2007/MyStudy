
/**
* 主要思路：
* 1.遍历字符串，比较当前元素与前一个元素是否相等，相等时，就计数加一
*   当不相等时，判断计数结果是否大于1，即字符的个数是否大于1，
* 2.当计算大于1时，计算计数的长度，以此计算更新字符串后的新的实际长度，
*   将数量字符串追加到前一个更新的元素后面，
* 3.重置计数，继续遍历
*/

/**
* replacing the same char with the length in the string
* @param: char* chars, the string ready to be checked
* @param: int charsSize, the length of the string
* return: int, the length of the updated string
*/
int compress(char* chars, int charsSize){

    int count = 1 , index = 1 , len = charsSize;
    
    //if the length of the string equals 1, return 1
    if( charsSize == 1 ){

        return 1;

    }
    
    //visitting the string
    for( int i = 1 ; i < charsSize ; i++ ){
        
        //if the former element equals current element, counting
        if( chars[ i ] == chars[ i - 1 ] ){

            count++;

        }
        
        //if not equation or at the end of the string, following
        if( ( ( chars[ i ] != chars[ i - 1 ] ) || ( i + 1 ) == charsSize ) ){
            
            //when the element is larger than one,
            if( count > 1 ){

                int value = 1;
                
                //count the length of the number
                while( ( count / value ) != 0 ){

                    value *= 10;
                    len++;

                }

                value /= 10;
                len -= ( count - 1 );

                while( value > 0 ){
                    
                    //appending the string of the number to the older string
                    chars[ index++ ] = ( count / value ) % 10 + '0';
                    value /= 10;

                }

            }

            count = 1;
            //make sure the index does not exceed the length of the string
            if( index != charsSize ){

                chars[ index++ ] = chars[ i ];

            }

        }

    }

    return len;

}