```
/**
*
*整体思路：
*1.根据当前月份，类似动态规划，计算前面所有月份的总日期
*2.计算如果当前月份大于2的 话，判断是否为闰年，
*
*/

/**
*Function: changing string to integer from starting index to edning index
*@param: char * s : the string ready to changed
*@param: int start : the starting index in string ready to be changed
*@param: int end : the ending index in string ready to be changed
*return: int : the result of process
*/
int stringToInteger( char * s , int start , int end ){

    //the parameter of value is used to save the result
    int value = 0;

    while( start <= end ){

        value = value * 10 + *( s + start++ ) - 48;

    }

    return value;

}

int dayOfYear( char * date ){
    
    //alloclating memory to save the number of days before current month
    int day[] = { 0 , 31 , 59 , 90 , 120 , 151 , 181 , 212 , 243 , 273 , 304 , 334 };
    //the parameter of month is used to save current month
    int month = stringToInteger( date , 5 , 6 );
    //the parameter of days is used to save the number of total days
    int days = *( day + ( month - 1 ) );
    //the parameter of year is used to save current year
    int year = stringToInteger( date , 0 , 3 );
    
    days += stringToInteger( date , 8 , 9 );

    if( month > 2 && ( ( year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0 ) ){

        days += 1;

    }

    return days;

}
```
