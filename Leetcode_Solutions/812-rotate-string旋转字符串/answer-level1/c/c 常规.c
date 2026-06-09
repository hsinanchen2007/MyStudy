```
/**
*
*整体思路：
*1.外层循环为字符串A的偏移量，i取值范围为[0, len_A)
*2.第二层循环遍历字符串B，比较当前元素j和偏移了(i + j ) % len_A个单位字符串A的元素是否相等
*  如果相等，继续下一趟比较，如果不等，标志位清0，结束本次遍历，
*3.结束遍历有两种情况，一种是break掉的，一种是成功遍历到最后一个元素，
*  因此如果是成功遍历的，直接返回true，否则进入下一次偏移
*4.返回false
*/

bool rotateString( char * A , char * B ){

    //the parameter of len_A and len_B is the length of string A and string B respectively
    int len_A = strlen( A );
    int len_B = strlen( B );

    //if len_A is not equal len_B
    if( len_A != len_B ){

        return false;

    //if the length of both string A and B are zero
    } else if( len_A == 0 && len_B == 0 ){

        return true;

    }

    //trying every offset
    for( int i = 0 ; i < len_A ; i++ ){

        int j = 0;

        for( ; j < len_B ; j++ ){
            
            //if the character of current element in string B is not equal
            //to the character of offset in string A, stopping visiting 
            if( *( B + j  ) != *( A + ( ( j + i ) % len_A ) ) ){

                break;

            }

        }

        //if visiting successfully, returning true
        if( j == len_B ){

            return true;

        }

    }

    return false;

}
```
