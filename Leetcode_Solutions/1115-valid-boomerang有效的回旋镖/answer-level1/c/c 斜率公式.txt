```

/**
*
*整体思路
*1.分别计算三个点的两两之间的斜率，调用计算函数calculatLineRate,传入两个点对应的x,y坐标
*2.如果x2-x1 == 0，证明斜率是无穷大的，此时斜率等于最大值inf
*3.如果斜率k1,k2,k3任意两两之间出现相等的情况，证明无法构成回旋镖，直接返回false
*4.返回true
*
*/

//the maximun of Slope
#define inf 2147483647

/**
*Function: calculating the Slope between two points
*@param: int x1 : the x-coordinate of first point
*@param: int y1 : the y-coordinate of first point
*@param: int x2 : the x-coordinate of second point
*@param: int y2 : the y-coordinate of second point
*return: double : the line rate of the two points
*/
double calculatSlope( int x1 , int y1 , int x2 , int y2 ){

    //if the value of x2 -x1 is zero, the Slope is inf
    if( x2 - x1 == 0 ){

        return inf;

    }

    return ( y2 - y1 ) * 1.0 / ( x2 - x1 );

}

bool isBoomerang( int ** points , int pointsSize , int * pointsColSize ){

    double k1 = calculatSlope( *( *( points + 0 ) + 0 ) , *( *( points + 0 ) + 1 ) ,
                                *( *( points + 1 ) + 0 ) , *( *( points + 1 ) + 1 ) );
    double k2 = calculatSlope( *( *( points + 0 ) + 0 ) , *( *( points + 0 ) + 1 ) ,
                                *( *( points + 2 ) + 0 ) , *( *( points + 2 ) + 1 ) );
    double k3 = calculatSlope( *( *( points + 1 ) + 0 ) , *( *( points + 1 ) + 1 ) ,
                                *( *( points + 2 ) + 0 ) , *( *( points + 2 ) + 1 ) );

    //if two of them have the same Slope, returning false
    if( k1 == k2 || k1 == k3 || k2 == k3 ){

        return false;

    }                            

    return true;

}
```
