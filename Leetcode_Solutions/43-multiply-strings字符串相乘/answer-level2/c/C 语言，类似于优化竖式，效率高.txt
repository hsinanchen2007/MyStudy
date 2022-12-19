
![图片.png](https://pic.leetcode-cn.com/7fb347b25432d75b2d02145499e36da7ba2de158e509b599b5d8603ab5fd1e09-%E5%9B%BE%E7%89%87.png)
```
char *
multiply( char *num1, char *num2 )
{
	int i = 0, j = 0;
	int *rec = NULL;
	char *ans = NULL;
	int n = 0, r = 0;
	int len1 = strlen( num1 ), len2 = strlen( num2 );
	int lenAns = 0, flag = 0;

	rec = calloc( len1 + len2, sizeof( int ) );

	if ( len1 == 0 )
		return num2;
	else
	if ( len2 == 0 )
		return num1;
	else
	if ( len1 == 0 && len2 == 0 )
		return NULL;
	else
	if ( num1[ 0 ] == '0' || num2[ 0 ] == '0' )
		return "0";

	for ( i = 0; i < len1; i++ )
		for ( j = 0; j < len2; j++ )
		{
			rec[ j + i + 1 ] += ( num1[ i ] - '0' ) * ( num2[ j ] - '0' );
			if ( rec[ j + i + 1 ] >= 100 )
			{
				rec[ j + i + 1 ] -= 100;
				rec[ j + i ] += 10;
			}
		}

	for ( i = len1 + len2 - 1; i > 0; i-- )
	{
		r = rec[ i ] % 10;
		n = ( rec[ i ] - r ) / 10;
		rec[ i - 1 ] += n;
		rec[ i ] -= n * 10;
	}

	if ( rec[ 0 ] == 0 )
	{
		lenAns = len1 + len2;
		flag++;
	}
	else
		lenAns = len1 + len2 + 1;

	ans = calloc( lenAns, sizeof( char ) );
	ans[ lenAns - 1 ] = '\0';
	for ( i = lenAns - 2; i >= 0; i-- )
		ans[ i ] = ( char )rec[ i + flag ] + '0'; 

	free( rec );

	return ans;
}
```
