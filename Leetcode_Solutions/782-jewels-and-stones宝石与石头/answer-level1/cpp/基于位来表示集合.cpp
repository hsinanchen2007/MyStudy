题目明确了所有字符都是字母，从'A'到'z'总共只有58个字符（大小写字母之间有6个非字母符号），所以可以用一个64位整数来表示它们构成的集合，每个二进制位对应一个字符。
注意判断mask & all_types的地方如果不写 != 0 的话性能会降低。

```
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        MaskType all_types= 0;
        for( auto t : J ){
            all_types |= type2mask( t );
        }
        auto count= 0;
        for( auto t : S ){
            const auto mask= type2mask( t );
            if( ( mask & all_types ) != 0 ){
                ++count;
            }
        }
        return count;
    }
    
private:
    using MaskType= unsigned long long;
    
    static MaskType type2mask( char type )
    {
        static_assert( 'z' - 'A' < sizeof( MaskType ) * 8 );
        assert( 'A' <= type );
        assert( type <= 'z' );
        const auto offset= type - 'A';
        constexpr MaskType one= 1;
        return one << offset;
    }
    
};
```
