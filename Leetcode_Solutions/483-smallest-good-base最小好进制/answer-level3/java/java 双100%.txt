   
![TIM图片20200109230015.png](https://pic.leetcode-cn.com/d1c9cd7cc7d7056e2c170e664f24cdbcd1e31b485b4df70cb3cd938d92f467e3-TIM%E5%9B%BE%E7%89%8720200109230015.png)

	//N = k^0 + k^1 + k^2 + ... + k^m

	public String smallestGoodBase(String n) {
        long N = Long.parseLong( n );
    	long m_max = ( long )( Math.log( ( double )N ) / Math.log( ( double )2.0 ) );// m_max
    	for( long m = m_max ; m > 1 ; m-- ) {
			//最重要的一步 , m确定之后 k其实也是确定的，这是因为 k^m < N且有(k+1)^m > N
			//因此只需要枚举 [2,log( N )]，并求解对应的K
    		long k = (long) Math.pow( ( double )N , 1.0/m );
    		long s = 0;
    		for( long i = 0 ; i <= m ; i++ )s = s * k + 1;
    		if( s == N )return String.valueOf( k );
    	}
        return String.valueOf(N-1);
    }


