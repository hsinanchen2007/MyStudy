/**
*！！！！！对strcmp()函数很熟悉的可以跳过！！！！！
*补充说明：这个快速排序可能有人没用过，先来看看熟悉的strcmp函数，如果两个字符串完全相等，返回的
*结果是0，如果否则返回两个字符串首次出现不同字符时的差值，例如s1="123456", s2="123567",此时函数
*返回的结果是strcmp( s1, s2 ) = -1 != 0，s1的'4'和s2的'5'，相减等于-1。
*!!!本题中，只要返回大于0，小于0和等于0就可以知道比较结果了
*/

```


/**
*
*整体思路：   自定义快速排序的比较函数
*1.直接调用相应的快速排序函数
*2.首先直接移动字符串s1和字符串s2到' '处，再开始比较
*3.如果s1和s2内容全为数字，直接return 0，不改变他们的顺序
*4.如果s1和s2内容全为字母，直接返回他们的比较值，注意如果他们内容完全一致，再移动到前面去比较标识*  符，
*5.如果s1为字符，则直接返回-1
*6.直接返回1
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp( const void * a , const void * b){

    //the parameter of i is used to point current elements in s1
    //the parameter of j is used to point current elements in s2
    int i = 0 , j = 0;
    //saving the string which ready to be compared to s1 and s2
    char * s1 = *( ( char ** ) a );
    char * s2 = *( ( char ** ) b );

    //moving s1 and s2 to their contents respectively
    while( *( s1 + i++ ) != ' ' );
    while( *( s2 + j++ ) != ' ' );

    //if the content of s1 and s2 are digty, keepig their sequence
    if( *( s1 + i ) >= '0' && *( s1 + i ) <= '9' && *( s2 + j ) >= '0' && *( s2 + j ) <= '9' ){

        return 0;

    }

    //if the content of s1 and s2 are alpha, return their result of comparing process
    if( *( s1 + i ) >= 'a' && *( s1 + i ) <= 'z' && *( s2 + j ) >= 'a' && *( s2 + j ) <= 'z' ){

        //keeping moving the pointer of s1 and s2 until they are different or
        //meeting the ending flag of string '\0'
        for( ; *( s1 + i ) != '\0' && *( s2 + j ) != '\0'
                        && *( s1 + i ) == *( s2 + j )  ; i++ , j++ );

        //if the content of s1 and s2 are the same, comparing their flag 
        if( i == j && *( s1 + i ) == *( s2 + j ) ){

            i = j = 0;
                
            for( ; *( s1 + i ) != '\0' && *( s2 + j ) != '\0'
                        && *( s1 + i )  == *( s2 + j ) ; i++ , j++ );

        }
        
        return *( s1 + i ) - *( s2 + j );

    }
    
    //if the content of s1 is alpha, the content of s2 is numbers, return -1
    if( *( s1 + i ) >= 'a' && *( s1 + i ) <= 'z' ){

        return -1;

    }

    //if the content of s1 is numbers, the content of s2 is alpha, return 1
    return 1;

}

char ** reorderLogFiles( char ** logs , int logsSize , int * returnSize){

    *returnSize = logsSize;

    qsort( logs , logsSize , sizeof( *( logs + 0 ) ) , cmp );

    return logs;

}
```
