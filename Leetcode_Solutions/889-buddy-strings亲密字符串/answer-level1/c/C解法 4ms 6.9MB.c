
/**
*主要思路：
*  1.遍历其中两个字符串，如果当两个字符串出现第一次不相等元素时，记录下此时的下标，
*  2.当第二次出现不同元素时，取出第一次记录的下标，分别对应比较，两者必须同时满足
*  交换后的值时，成功交换，否则视为无法交换。
*  3.第三次出现不相同元素时，直接退出，无法通过互换元素得到字符串B
*  4.如果未发现有不同的元素时，对字符串A进行检测，是否存在两个相同的元素，否则无法
*  通过交换得到字符串B
*/


/**
*check the string whether has two char that are the same
*检查数组中是否有两个一样的字符
* @param: char * str, the string ready to be checked
* return : int , 0 No, 1 Yes
*/
int doubleChar( char * str ){

    int len = strlen( str );

    for( int i = 0 ; i < len - 1 ; i++ ){

        for( int j = i + 1 ; j < len ; j++ ){

            if( *( str + i ) == *( str + j ) ){

                return 1;

            }

        }

    }

    return 0;

}

/**
*check if the string A can equals to string B by exchanging two char 
* @param: char * A, the string A ready to be checked
* @param: char * B, the string B ready to be compared
* return : int , 0 No, 1 Yes
*/
bool buddyStrings(char * A, char * B){

    int lengthA = strlen( A ) , lengthB = strlen( B ) ;
    int index = 0 , flag = 0 ;

    //make sure the strings have the same length
    if( ( lengthA != lengthB ) || 
        ( ( strcmp( A , "" ) == 1 ) || ( strcmp( B , "" ) == 1 ) ) ){

        return false;

    }

    for ( int i = 0 ; i < lengthA ; i++ ){

        //make sure the elements of the strings are character
        if( ( *( A + i ) >= 'a' && ( *( A + i ) <= 'z') ) 
            && ( *( B + i ) >= 'a' && ( *( B + i ) <= 'z') ) ){

            if( *( A + i ) != *( B + i ) ){

                flag++;

                switch( flag ){

                    case 1:{

                        //remember the index of the first different char
                        index = i;
                        break;

                    }

                    case 2:{

                        //compare the different char whether can equal by exchanging
                        if( ( *( A + i) != *( B + index ) ) 
                            || ( *( A + index ) != *( B + i ) ) ){
                            return false;

                        }
                        break;

                    }

                    default:
                        return false;

                }



            }

        } else {

            return false;

        }

    }

    //make sure the string A not equal string B
    if( flag == 0 ){

        if( doubleChar( A ) == 0 ){

            return false;

        }

    } 

    return true;
}