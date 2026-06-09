```
/**
*
*整体思路：
*1. 维护两个指针，指针left初始化指向字符串第一个字符，指针right初始化指向字符串最后一个元素
*2.判断left < right，如果不成立，进入步骤7
*3.左指针left如果指向辅音，则继续向右移动，
*4.右指针right如果指向辅音，则继续向左移动，
*5.如果两个指针left和right同时指向元音，则交换对应元素，同时left向右移动一位,right向左移动一位
*6.重复2-5步骤
*7.返回字符串s
*/


/**
*Function: checking whether the character of ch is vowl
*@param: char ch : the character ready to be checked
*return: bool : true : ch is vowl , false : ch is not vowl
*/
bool isVowls( char ch ){

    if( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ){

        return true;

    }

    if( ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ){

        return true;

    }

    return false;

}

char * reverseVowels(char * s){

    //the parameter of left used to ponit the left of string
    //the parameter of right used to point the right of string
    int left = 0 , right = 0;

    //moving the pointer of right to the right of string 
    while( *( s + right++ ) != '\0' );
    right -= 2;

    //making sure left smaller than right
    while( left < right ){

        bool b1 = isVowls( *( s + left ) ) , b2 = isVowls( *( s + right ) );

        //if the element of left is not vowl, 
        //keeping moving to next element, otherwise stopping
        if( !b1 ){

            left++;

        }

        //if the element of right is not vowl, 
        //keeping moving to next element, otherwise stopping
        if( !b2 ){

            right--;

        }

        //if the element of left is vowl and the element of right is also vowl
        if( b1 == true && b2 == true ){

            //exchanging the character of left and right, then, updating both of them
            char ch = *( s + left );
            *( s + left++ ) = *( s + right );
            *( s + right-- ) = ch;

        }

    }

    return s;

}
```
