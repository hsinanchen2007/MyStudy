```
/**
*
*整体思路：斜率公式k=(y2-y1)/(x2-x1)
*1.计算第一个点和最后一个点的斜率并记录在k
*2.将数组的每个点一次和第一个点进行斜率计算，
*3.如果两者斜率不等，必不在一条直线上
*
*
*/

bool checkStraightLine( int ** coordinates , int coordinatesSize , int * coordinatesColSize ){

    //if the length of coordinantes less than 2, return true
    if( coordinatesSize < 2 ){

        return true;

    }

    //calculating the slope between the first point and the last point 
    double k = ( *( *( coordinates + coordinatesSize - 1 ) + 1 )
            - *( *( coordinates + 0 ) + 1 ) ) * 1.0 / 
            ( *( *( coordinates + coordinatesSize - 1 ) + 0 ) 
            - *( *( coordinates + 0 ) + 0 ) );

    //visiting array,
    for( int i = 1 ; i < coordinatesSize - 1 ; i++ ){

        //calculating the slope between the first point and the current point 
        double k1 = ( *( *( coordinates + coordinatesSize - i ) + 1 )
            - *( *( coordinates + 0 ) + 1 ) ) * 1.0 / 
            ( *( *( coordinates + coordinatesSize - i ) + 0 ) 
            - *( *( coordinates + 0 ) + 0 ) );

        //if current slope is not equal to the value of k, return false
        if( k1 != k ){

            return false;

        }

    }

    return true;

}
```
