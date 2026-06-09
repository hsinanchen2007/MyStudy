```
int
divide( int dividend, int divisor )
{
	int c = 0, r = 1;
	int minus = 1, acc = 0;

	if ( ( dividend > 0 && divisor < 0 ) ||
			( dividend < 0 && divisor > 0 ) )
		minus = -1;

	if ( dividend != INT_MIN )
		dividend = 0 - abs( dividend );
	else
	if ( divisor == -1 )
		return INT_MAX;
	else
	if ( divisor == 1 )
		return INT_MIN;

	if ( divisor != INT_MIN )
		divisor = 0 - abs( divisor );
	acc = divisor;

	while ( dividend <= divisor )
	{
		if ( dividend <= acc )
		{
			c += r;
			dividend -= acc;
			
			if ( acc > -10000 )
			{
				acc += divisor;
				r++;
			}
		}
		else
		{
			c++;
			dividend -= divisor;

			r--;
			acc -= divisor;
		}
	}

	return minus * c;
}
```
算法就是增加除数来逼近被除数，前面说的人很多。