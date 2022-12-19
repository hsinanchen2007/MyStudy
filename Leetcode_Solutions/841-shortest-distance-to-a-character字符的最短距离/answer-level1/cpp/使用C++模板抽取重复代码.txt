```
template< class ItorDst, class ItorSrc >
void update( const ItorDst& begin_dst, const ItorSrc& begin_src, const ItorSrc& end_src, char target )
{
    int distance= -1;
    auto itor_dst= begin_dst;
    for( auto itor_src= begin_src; itor_src!=end_src; ++itor_src, ++itor_dst ){
        if( *itor_src == target ){
            distance= 0;
            *itor_dst= distance;
        }else if( distance >= 0 ){
            ++distance;
            *itor_dst= min( *itor_dst, distance );
        }
    }
}

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector< int > result( S.size(), S.size() );
        update(  begin( result ),  begin( S ),  end( S ), C );
        update( rbegin( result ), rbegin( S ), rend( S ), C );
        return result;
    }
};
```
