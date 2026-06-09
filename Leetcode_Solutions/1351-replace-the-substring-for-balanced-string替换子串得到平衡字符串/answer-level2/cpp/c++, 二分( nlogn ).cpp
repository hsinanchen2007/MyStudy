```
class Solution {

public:
    int balancedString(string s) {
        int len = s.length() / 4;

        vector< int > sumq, sumw, sume, sumr;

        sumq.resize( len * 4 + 1 );
        sumw.resize( len * 4 + 1 );
        sume.resize( len * 4 + 1 );
        sumr.resize( len * 4 + 1 );

        for( int i = 0; i < len * 4; i ++ )
        {
            sumq[ i + 1 ] = sumq[ i ] + ( s[ i ] == 'Q' );
            sumw[ i + 1 ] = sumw[ i ] + ( s[ i ] == 'W' );
            sume[ i + 1 ] = sume[ i ] + ( s[ i ] == 'E' );
            sumr[ i + 1 ] = sumr[ i ] + ( s[ i ] == 'R' );
        }

        int l = 0;
        int r = len * 4;
        
        int goal = r;

        while( l <= r )
        {
            auto m = l + r >> 1;
            int flag = 0;
            for( int i = m; i <= len * 4; i ++ )
            {
                if( sumq[ i - m ] + sumq[ len * 4 ] - sumq[ i ] > len ) continue;
                if( sumw[ i - m ] + sumw[ len * 4 ] - sumw[ i ] > len ) continue;
                if( sume[ i - m ] + sume[ len * 4 ] - sume[ i ] > len ) continue;
                if( sumr[ i - m ] + sumr[ len * 4 ] - sumr[ i ] > len ) continue;
                flag = 1;
                break;
            }
            if( flag )
            {
                goal = m;
                r = m - 1;
            }
            else l = m + 1;
        } 
        return goal;
    }
};
```
