```
/**
*
*整体思路：
*1.快速排序数组，
*2.倒序遍历，如果当前最后两个元素相等，向前移动两个单位，
*3.如果x!=y,此时先做减法，同时如果j=0，直接返回y-x,否则用插入排序，对y-x插入原数组中，移动一个单位
*
*/

int cmp( const void * a , const void * b ){

    return *( int * )a - *( int * )b;

}

int lastStoneWeight( int * stones , int stonesSize ){
    //quick sort
    qsort( stones , stonesSize , sizeof( int ) , cmp );
    //the parameter of x and y meeting the question's condition 
    int x = 0 , y = 0;

    //visiting the array from the ending to starting
    for( int i = stonesSize - 1 ; i > 0 ;  ){

        x = *( stones + i - 1 );
        y = *( stones + i );

        //if x == y
        if( x == y ){

            *( stones + i - 1 ) = 0;
            *( stones + i ) = 0;
            //moving two unit
            i -= 2;
            continue;
            
        }

        //updating y
        y -= x;

        int j = i - 1 ;

        //if the length of the array is 2, return new y
        if( j == 0 ){

            return y;

        }

        //insert sort
        while( j > 0 && *( stones + j - 1 ) > y ){

            *( stones + j ) = *( stones + j - 1 );
            j--;

        }

        *( stones + j ) = y;
        i--;

    }

    return *( stones + 0 );

}
```
