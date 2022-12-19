
```
int trap(int* height, int heightSize)
{
    int left = 0;
    while( left < heightSize-1 && height[ left ] <= height[ left +1 ] )
    {
        left ++ ;
    }
    if( left >= heightSize-2 )
    {
        return 0;
    }
    int right = left + 2;
    int res = 0;
    int maxRight = right;
    while( right < heightSize )
    {
        while( right < heightSize )
        {
            if( height[ right ] <= height[ right -1 ] )
            {

            }
            else if( height[ right ] >= height[ left ] )
            {
                maxRight = right ;
                break;
            }
            else 
            {
                if( height[ right ] > height[ maxRight ] )
                {
                    maxRight = right ;
                }
            }
            right ++ ;
        }
        if( height[ maxRight ] <= height[ left ] )
        {
            for( int i = left + 1 ; i < maxRight ; i ++ )
            {
                if( height[ maxRight ] > height[ i ] )
                res +=height[ maxRight ] - height[ i ] ;
            }
        }
        else
        {
            for( int i = left + 1 ; i < maxRight ; i ++ )
            {
                if( height[ left ] > height[ i ] )
                res +=height[ left ] - height[ i ] ;
            }
        }
        left = maxRight ;
        while( left < heightSize-1 && height[ left ] <= height[ left +1 ] )
        {
            left ++ ;
        }

        right = left + 2;
        maxRight = right ;
    }
    return res;
}
```
