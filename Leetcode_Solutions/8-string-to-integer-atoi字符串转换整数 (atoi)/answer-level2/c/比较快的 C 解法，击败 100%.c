```
int
myAtoi( char *str )
{
	int length = strlen( str );
	int num = 0, minus = 0;
	int i = 0;

	for ( i = 0; i < length; i++ )
	{
		if ( str[ i ] == ' ' && minus == 0 )
			continue;
		else
		if ( str[ i ] == '-' && minus == 0 )
			minus = -1;
		else
		if ( str[ i ] == '+' && minus == 0 )
			minus = 1;
		else
		{
			for ( ; str[ i ] <= '9' && str[ i ] >= '0'; i++ )
			{
				if ( INT_MAX / 10 > num ||
						( INT_MAX / 10 == num && str[ i ] < '8' ) )
					num = num * 10 + ( str[ i ] - '0' );
				else
					return ( minus == -1 ) ? INT_MIN : INT_MAX;
			}

			return ( minus == -1 ) ? ( minus * num ) : num;
		}
	}
	return num;
}
```
