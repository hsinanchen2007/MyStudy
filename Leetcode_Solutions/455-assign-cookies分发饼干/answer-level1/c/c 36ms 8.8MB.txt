```
/**
*
*整体思路：时间复杂度O(N*M)，空间复杂度O(1)
*1.如果饼干或者小朋友一个为0，则返回0
*2.快速排序饼干权值和小朋友胃口
*3.如果饼干最大权值不能满足最低要求的小朋友胃口则返回0
*4.如果饼干最低权值可以满足小朋友最大要求，则返回饼干数量即为所求最大数值
*5.遍历数组，饼干作为外层循环，用最小权值饼干去满足可以满足的最小的小朋友胃口
*   如果可满足，继续寻找下一个可满足的搭配
*
*/

//quick sort
int cmp( const void * a , const void * b ){

    return *( int * )a - *( int * )b;

}

int findContentChildren( int * g , int gSize, int * s , int sSize ){

    //if the number of children and cookies is zero, return 0 
    if( gSize == 0 || sSize == 0 ){

        return 0;

    }

    //the parameter of count is used to save the maximun number that meet the conditions
    int count = 0;

    //quick sort
    qsort( g , gSize , sizeof( int ) , cmp );
    qsort( s , sSize , sizeof( int ) , cmp );

    //if the biggest cookie can not meet the smallest appetite of children, return 0
    if( *( s + sSize - 1 ) < *( g + 0 ) ){

        return 0;

    //if the smallest cookie can meet the maximun appetite of children, return the length
    //of cookies
    } else if( *( s + 0 ) > *( g + gSize - 1 ) ){

        return sSize;

    }

    //visiting the cookies
    for(  int i = 0 , j = 0 ; i < sSize && j < gSize ; ){

        //finding the smaller cookie to meet the smaller appetite of chidren
        while( i < sSize && *( s + i ) < *( g + j ) ){

            i++;

        }

        //if we find one situation, continuing the finding process
        if( i < sSize && *( s + i ) >= *( g + j ) ){

            count++;
            i++;
            j++;

        }

    }

    return count;

}
```
