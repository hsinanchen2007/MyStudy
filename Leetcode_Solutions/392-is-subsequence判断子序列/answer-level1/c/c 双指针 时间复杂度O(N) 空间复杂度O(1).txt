```
/**
*
*整体思路：双指针
*1.维护指针i指向字符串s，维护指针j指向字符串t
*2.判断两者是否达到字符结束标志，如果达到进入步骤6
*3.判断s和t当前字符是否相同，不同的话，移动指针j到下一个字符，
*4.如果当前字符相同，同时更新指针i和j，
*5.重复2-5步骤
*6.判断s字符串是否遍历完，如果不是，返回false
*7.返回true
*/

bool isSubsequence(char * s, char * t){

    //the parameter of i is the pointer of string s
    //the parameter of j is the pointer of string t
    int i = 0 , j = 0;

    //making sure i and j do not point the end of s and t
    while( *( s + i ) != '\0' && *( t + j ) != '\0' ){

        //if the character of current element in s is not equals to one in string t, 
        //only updating the pointer of j
        if( *( s + i ) != *( t + j ) ){

            j++;

        //updating the pointer of i and j
        } else {

            i++;
            j++;

        }

    }

    //if the pointer of i in string s does not point to '\0', returning false
    if( *( s + i ) != '\0' ){

        return false;

    }

    return true;

}
```
