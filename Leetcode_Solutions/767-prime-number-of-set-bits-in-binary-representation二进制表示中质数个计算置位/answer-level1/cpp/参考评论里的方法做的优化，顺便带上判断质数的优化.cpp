用bitset可以把数据放在栈上，对cache更友好。
判断质数的时候有几个优化的点：
1. 除2之外，其他质数都是奇数，所以非2的偶数都可以排除
2. 当需要判断的数值不太大时，可以把判断质数的结果缓存起来，vector< bool >内部已经做了位压缩，不会非常浪费内存。另外把从2开始已知的质数缓存起来也有用（见第3条）。
3. 检测一个数的因子，只需要从2开始检测到其平方根即可，严格大于其平方根的因子不用再做检测。而且在这个范围内，也只需要检测质数（质因子），而质数的分布是比较稀疏的，所以可以跳过很多因子判断。所以在需要判断的数不太大时，可以把质数缓存起来，有点类似动态规划的做法。

```
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        const bitset< 21 > isprime( "010100010100010101100" );
        int result= 0;
        int last_count= 0;
        for( int value= L; value<=R; ++value ){
            int count= 0;
            if( value != L && value & 1 != 0 ){
                count= last_count + 1;
            }else{
                auto tmp= value;
                while( tmp != 0 ){
                    tmp &= tmp - 1;
                    ++count;
                }
            }
            if( isprime[ count ] ){
                ++result;
            }
            last_count= count;
        }
        return result;
    }
    
private:
    static bool is_prime( int num )
    {
        static vector< bool > num2isprime= {
            false,
            false,
            true,
            true,
            false,
            true,
            false,
            true,
            false,
            false,
            false,
            true,
            false,
            true,
            false,
            false,
            false,
            true,
            false,
            true,
            false,
        };
        static vector< int > prime_factors= {
            2,
            3,
            5,
            7,
            11,
            13,
            17,
            19,
        };
        if( num <= 1 ){
            return false;
        }else if( num == 2 ){
            return true;
        }else if( num & 1 == 0 ){
            return false;
        }
        if( num < num2isprime.size() ){
            return num2isprime[num];
        }
        num2isprime.reserve( 24 );
        prime_factors.reserve( 16 );
        for( int i= num2isprime.size(); i<=num; ++i ){
            auto i_is_prime= true;
            for( auto prime_factor : prime_factors ){
                if( prime_factor*prime_factor > i ){
                    break;
                }
                if( i % prime_factor == 0 ){
                    i_is_prime= false;
                    break;
                }
            }
            num2isprime.emplace_back( i_is_prime );
            if( i_is_prime ){
                prime_factors.emplace_back( i );
            }
        }
        return num2isprime[num];
    }
    
};
```
