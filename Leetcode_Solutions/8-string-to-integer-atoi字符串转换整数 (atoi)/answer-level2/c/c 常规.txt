```

/**
*
*整体思路：
*1.首先初始化result为long型数据，result=0
*2.维护一个指针i,初始化i=0，同时符号标志位flag初始化为1
*3.去除数字或符号前的空格' ' 和正号'+'，
*4.如果为'-'，flag=-1
*5.遍历符号或者无符号后的连续数字，如果不为数字，退出遍历，无论遍历完与否，进入步骤
*6.更新result，判断result*flag>INT_MAX是否成立，如果成立，返回INT_MAX，
*   如果result*flag<INT_MIN成立，返回INT_MIN，
*7.继续下一趟遍历
*8.返回result*flag
*/

//the maximun value of int
#define INT_MAX 2147483647
//the minimun value of int
#define INT_MIN -2147483648

int myAtoi( char * str ){

    //the parameter of result used to save the final result
    long result = 0 ;
    //the parameter of flag is the flag of sign
    //the parameter of i is the pointer of string str
    int flag = 1 , i = 0;

    //skipping the spaces in the front of digit in string str
    while( *( str + i ) == ' '  ){

        i++;

    }

    //if the sign is '-', updating flag
    if( *( str + i ) == '-' ){

        flag = -1;
        i++;

    } else if( *( str + i ) == '+' ){

        i++;

    } 

    //visiting string str making sure digit is continuing
    for( ; *( str + i ) != '\0' && isdigit( *( str + i ) ) ; i++ ){

        //updating the value of result
        result = result * 10 + *( str + i ) - 48;

        //if result*flag bigger than INT_MAX, returning INT_MAX
        if( result * flag > INT_MAX ){

            return INT_MAX;

        //if result*flag bigger than INT_MIN, returning INT_MIN
        } else if( result * flag < INT_MIN ){

            return INT_MIN;

        }

    }

    return result * flag; 

}
```
