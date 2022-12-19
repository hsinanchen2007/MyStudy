之前的代码在测试用例[1,-1,1,-1]时不会通过，在每个while循环前，将该段的和令为该段首元素即可，如下

```
second_sum = *( A + i++ );

while( second_sum != ( sum / 3 ) && i < ASize - 1 ){

    second_sum += *( A + i++ );

}
```

完整源码如下

```
/**
*
*整体思路：
*1.判断数组长度小于3直接返回false，
*2.先遍历数组，计算总和，
*3.判断总和是否为3的倍数，如果不是，直接返回false
*4.维护一个指针，遍历数组
*   a.先计算出第一段为sum/3的数组
*   b.计算数组和为sum/3的第二段
*   c.计算余下数组是否为sum/3，如果不是，直接返回false
*
*/

bool canThreePartsEqualSum( int * A , int ASize ){

    //if the length of array is shorter than 3, return false
    if( ASize < 3 ){

        return false;

    }

    //the parameter of first_sum is used to calculating the sum of first segement in array
    //the parameter of second_sum is used to calculating the sum of second segement in array
    //the parameter of third_sum is used to calculating the sum of third segement in array
    int first_sum = *( A + 0 ) , second_sum = 0 , third_sum = 0;
    //the parameter of _sum is used to calculating the sum of array
    //the parameter of i is current pointer
    int sum = 0 , i = 0;

    for( i = 0 ; i < ASize ; i++ ){

        sum += *( A + i );

    }

    //if the result of sum can not div 3, return false
    if( sum % 3 != 0 ){

        return false;

    }

    //intializing current pointer
    i = 1;

    //calculating the sum of first segment in array
    while( first_sum != ( sum / 3 ) && i < ASize - 2 ){

        first_sum += *( A + i++ );

    }

    second_sum = *( A + i++ );

    //calculating the sum of second segment in array
    while( second_sum != ( sum / 3 ) && i < ASize - 1 ){

        second_sum += *( A + i++ );

    }

    third_sum = *( A + i++ );

    //calculating the sum of the rest element in array
    while( i < ASize ){

        third_sum += *( A + i++ );

    }

    //if third_sum is one of three of sum, return true
    if(  third_sum == ( sum / 3 )  ){

        return true;

    }


    return false;

}
```
