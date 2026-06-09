```
/**
*
*整体思路：从00:00遍历到11:59，判断1的个数是否等于nums
*1.从00:00调用 递归函数
*2.如果minute为60，清零后，hour加一，如果nums=0返回0:00
*3.计算当前hour和minute的二进制1的个数count
*4.如果count等于nums，则获取当前时间的字符串，存入缓冲区
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
*Function: changing the value of hour and minute to the format of HH:MM
*@param: char * buffer : the memory is used to save the result
*@param: int hour : the value of hour ready to be changed
*@param: int minute : the value of minute ready to be changed
:return: void
*/
void timeString( char * buffer , int hour , int minute ){

    //the parameter of index is used to point current element in buffer
    int index = 0;

    //if hour is bigger than 10
    if( hour >= 10 ){

        *( buffer + index++ ) = hour / 10 + 48;
        *( buffer + index++) = hour % 10 + 48;

    //if hour is less than 10, delete the zero in the priority of ten
    } else {

        *( buffer + index++ ) = hour % 10 + 48;

    }

    //appending the string of minutes
    *( buffer + index++ ) = ':';
    *( buffer + index++ ) = minute / 10 + 48;
    *( buffer + index++ ) = minute % 10 + 48;
    *( buffer + index++ ) = '\0';

}

/**
*Function: checking current hour and minutes meet the condition
*@param: int hour : current hour
*@param: int minute : current minute
*@param: int nums : the number of 1 in the binary of hour and minte
*@param: char * buffer : the memory is used to save the result
*@param: int * len : the parameter of len is used to save the length of buffer
:return: void
*/
void getTime( int hour , int minute , int nums , char ** buffer , int * len ){

    //if current minute is equaling to 60, updating hour, clearing minute
    if( minute == 60 ){

        minute = 00;
        hour++;

    }

    //if hour is bigger than 11 or nums is bigger than 10, return 
    if( hour > 11 || nums > 10 ){

        return ;

    }

    //the parameter of count is used to save the number of 1 in the binary of hour and minute
    int count = 0 , count1 = 0;
    //temp is a temporary parameter
    int tmp = hour;

    //calculating the number of 1 in the binaty of hour
    while( tmp > 0 ){

        if( tmp % 2 == 1 ){

            count++;

        }

        tmp /= 2;

    }

    tmp = minute;

    //calculating the number of 1 in the minute of hour
    while( tmp > 0 ){

        if( tmp % 2 == 1 ){

            count++;

        }

        tmp /= 2;

    }

    //if the total number of 1 in binary hour and minute equal to the value of nums
    if( count == nums ){

        *( buffer + *len ) = ( char * )malloc( sizeof( char ) * 6 );
        timeString( *( buffer + *len ) , hour , minute );
        *len += 1;

    }
    
    //continuing next time
    getTime( hour , minute + 1 , nums , buffer , len );


}

char ** readBinaryWatch(int num, int* returnSize){

    char ** buffer = ( char ** )malloc( sizeof( char * ) * 190 );

    *returnSize = 0;
    getTime( 0 , 0 , num , buffer , returnSize );

    return buffer;

}
```
