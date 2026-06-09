```
/**
*
*总体思路：
*1.遍历字符数组，判断下一个字符是否为结束标志，下下个字符是否为结束标志，如果都不是，则判断是否为#
*2.如果满足则如下步骤：
*   a.如果为1，则进入"jklmnopqrs"，根据*( s + i + 1 )做偏移
*   b.如果为2，则进入"tuvwxyz"，根据*( s + i + 1 )做偏移
*   c.利用指针存入新数据，移动两个指针
*3.如果确定满足在1-9，则直接运行，用指针存入新数据
*
*/

char * freqAlphabets( char * s ){

    //used to save the new data
    int index = 0;

    for( int i = 0 ; *( s + i ) != '\0' ; i++ ){

        if( *( s + i + 1 ) != '\0' && *( s + i + 2 ) != '\0' && *( s + i + 2 ) == '#' ){

            if( *( s + i ) == '1' ){

                //visiting the first table
        		*( s + index++ ) = ( "jklmnopqrs" )[ *( s + i + 1 ) - 48 ];

        	} else if( *( s + i ) == '2' ){

                //visiting the second table
        		*( s + index++ ) = ( "tuvwxyz" )[ ( *( s + i + 1 ) - 48 ) ];

        	}

            //move the pointer to next two elements
        	i += 2;
 
        } else if( *( s + i ) >= '1' && *( s + i ) <= '9' ){

        	*( s + index++ ) = *( s + i ) + 48;

        }

    }

    //append the flag of the end of string 
    *( s + index ) = '\0';

    return s;

}
```
