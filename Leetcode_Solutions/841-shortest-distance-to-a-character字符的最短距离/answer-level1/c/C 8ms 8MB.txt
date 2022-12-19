```
/**
*
*整体思路：
*1.采用双向遍历方法，先从左到右遍历，
*   遍历时，先将第一个出现C的左侧置0，用pre记录每次出现的下标，做差值，
*2.从右向左遍历时，同样不对第一次出现C的右侧操作，记录每次出现的下标，同时
*   做差值，len - i 
*3.注意：从左往右时，先不管第一次出现C的左边的距离，全部为0，
*   从右往左时，先不管第一次出现C的右边的距离，默认即可，同时判断如果遍历到
*   从左往右置0的元素时，更新距离值即可，同时距离值比第一次小时，替换距离值
*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestToChar( char * S , char C , int * returnSize ){

    //the allocalting memorise is used to save the distance bwtween character and C
    int * buffer = ( int * )malloc( sizeof( int ) * 10000 );
    //the parameter of len is the langth of the buffer, pre is used to mark the previos
    //index of C
    int len = 0 , pre = -1 ;

    //the first visiting from left to right,
    for( ; *( S + len ) != '\0' ; len++ ){

        //the meaning of -1 is that current poniter is in the left of the 
        //first C
    	if( pre != -1 ){

    		*( buffer + len ) = len - pre;

    	} else {

            *( buffer + len ) = 0;

        }

        //when meet C, setting the value of pre to the index of C
    	if( *( S + len ) == C ){

    		*( buffer + len ) = 0;
    		pre = len;

    	}


    }

    //the meaning of -1 is that current pointer is in the right
    //of first C
    pre = -1;

    for( int i = len - 1 ; i >= 0 ; i-- ){

    	if( pre != -1 ){

            //updating the element's value
    		if( ( *( buffer + i ) == 0 ) || ( pre - i < *( buffer + i ) )  ){

    			*( buffer + i ) = pre - i;

    		}

    	}

    	if( *( S + i ) == C ){

    		*( buffer + i ) = 0;
    		pre = i;

    	}

    }

    *returnSize = len;

    return buffer;

}
```
