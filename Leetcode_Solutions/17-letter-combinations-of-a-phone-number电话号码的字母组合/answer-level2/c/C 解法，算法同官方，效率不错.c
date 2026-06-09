```
static int nums[] = { 2, 3, 4, 5, 6, 7, 8, 9 };
static char *chars[] = { "abc", "def", "ghi", "jkl", 
	"mno", "pqrs", "tuv", "wxyz" };

int 
returnIndex( int n )
{
	int i = 0;
	for ( i = 0; i < 8; i++ )
		if ( n == nums[ i ] )
			return i;
	return 0;
}

void
recursion( int i, int *count, int lenOfDigits, char *digits, char *buf, char **letters )
{
	int j = 0;

	if ( i == lenOfDigits )
	{
		buf[ i + 1 ] = '\0';
		
		letters[ *count ] = calloc( lenOfDigits + 1, 1 );
		for ( j = 0; j < lenOfDigits; j++ )
			letters[ *count ][ j ] = buf[ j ];
		letters[ *count ][ j ] = '\0';
		( *count )++;
	}
	else
	{
		int len = strlen( chars[ 
				returnIndex( digits[ i ] - '0' ) ] ); 
		for ( j = 0; j < len; j++ )
		{
			buf[ i ] = chars[ returnIndex( digits[ i ] - '0' ) ][ j ];
			recursion( i + 1, count, lenOfDigits, digits, buf, letters );
		}
	}
}


char **
letterCombinations( char *digits, int *returnSize )
{
	int i = 0;
	int count = 0;
	char *buf = NULL;
	char **letters = NULL;
	int len = strlen( digits );

	if ( len == 0 )
	{
		*returnSize = 0;
		return NULL;
	}

	buf = calloc( len + 2, 1 );
	*returnSize = 1;

	for ( i = 0; i < len; i++ )
		*returnSize *= strlen( 
				chars[ returnIndex( digits[ i ] - '0' ) ] );
	letters = calloc( *returnSize + 1, 8 );

	recursion( 0, &count, len, digits, buf, letters );

	return letters;
}
```
