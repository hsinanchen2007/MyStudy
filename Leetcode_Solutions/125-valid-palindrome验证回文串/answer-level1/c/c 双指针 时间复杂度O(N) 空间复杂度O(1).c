```

/**
*
*整体思路：
*1.双指针，从两边往中间遍历，维护left和right两个指针
*2.无论进行何种操作，都必须满足left < right
*3.left和right一直维护指向数字digit和字母alpha
*4.将left和right指向的大写(upper)，全部更新为小写后，比较两者是否相等，不等，直接返回false，
*  相等时，进入下一趟循环
*5.返回true
*/

bool isPalindrome( char * s ){

    //the parameter of right is the pointer points the right of string s 
    //the parameter of left is the pointer points the left of string s 
    int right = strlen( s ) - 1 , left = 0;

    //if the length of string less than 2, returning true
    if( right < 1 ){

        return true;

    }

    //making sure left smaller than right
    while( left < right ){

        //making sure the pointer of left points to digit or alpha
        while( left < right && !( isdigit( *( s + left ) ) || isalpha( *( s + left ) ) ) ){

            left++;

        }

        //making sure the pointer of right points to digit or alpha
        while( left < right && !( isdigit( *( s + right ) ) || isalpha( *( s + right ) ) ) ){

            right--;

        }

        //making sure left less than right
        if( left < right ){

            //if the character of left is upper, changing to samll
            if( isupper( *( s + left ) ) ){

                *( s + left ) += 32;

            }

            //if the character of right is upper, changing to samll
            if( isupper( *( s + right ) ) ){

                *( s + right ) += 32;

            }

            if( *( s + left++ ) != *( s + right-- ) ){

                return false;

            }


        } else {

            break;

        }

    }

    return true;

}
```
