```
/**
*
*整体思路：
*1.先判断长度为1的话，直接判断是否为目标值，是的话，返回0
*2.声明左右端点，同时判断是否满足条件
*3.判断中点值和目标值大小
*   大于，更新右端点right 为中点
*   小于，更新左端点为left为中点
*   等于，返回当前下标
*4.返回-1
*/

int search( int * nums , int numsSize , int target ){

    //if the length of num is 1 and the value of it is equaling to target, return 0
    if( numsSize == 1 && *( nums + 0 ) == target ){

        return 0;

    }

    //intializing the pointer of left and right 
    int left = 0 , right = numsSize;

    //judging the value of left
    if( *( nums + left ) == target ){

        return left;

    }

    //judging the value of right
    if( *( nums + right - 1 ) == target ){

        return right - 1;

    }

    //if left is not in the left of right by one elements
    while( right - left > 1 ){

        //if the value of current element is bigger than target, updating right
        if( *( nums + ( ( left + right ) / 2 ) ) > target ){

            right = ( left + right ) / 2 ;

        //if the value of current element is samller than target, updating left
        } else if( *( nums + ( ( left + right ) / 2  ) ) < target ){

            left = ( left + right ) / 2 ;

        //if the value of current element is equaling to target, returning the index of it
        } else if( *( nums + ( ( left + right ) / 2 )  ) == target ){

            return ( left + right ) / 2 ;

        }

    }

    return -1;

}
```
