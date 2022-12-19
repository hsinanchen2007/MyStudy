![图片.png](https://pic.leetcode-cn.com/452852cd2497c30f2ed662b1d36cb6c5ca5a96a15efbd6893a9ef739750fa62c-%E5%9B%BE%E7%89%87.png)


```
struct Word
{
	char *str;
	int Times;
	int CurTimes;
};

typedef struct Word *Container;

int
CompareStr( int len, char *s1, char *s2 )
{
	int i = 0;
	
	if ( s1 == NULL || s2 == NULL )
		return 0;

	for ( i = 0; s1[ i ] != '\0' &&
			s2[ i ] != '\0' && i < len; i++ )
		if ( s1[ i ] != s2[ i ] )
			return 0;

	if ( i == len )
		return 1;
	return 0;
}

void
Insert( int len, char *str, int Size, Container *C )
{
	int i = 0, j = 0;
	for ( i = 0; i < Size; i++ )
		if ( C[ i ]->str == NULL )
		{
			C[ i ]->str = calloc( len + 5, sizeof( char ) );
			for ( j = 0; j < len; j++ )
				C[ i ]->str[ j ] = str[ j ];

			( C[ i ]->Times )++;
			break;
		}
}

int
FindStr( int len, char *str, int Size, Container *C )
{
	int i = 0;
	for ( i = 0; i < Size; i++ )
		if ( CompareStr( len, C[ i ]->str, str ) )
			return i;
	return -1;
}

int
CheckTimes( int Size, Container *C )
{
	int i = 0;
	for ( i = 0; i < Size; i++ )
		if ( C[ i ]->Times != C[ i ]->CurTimes )
			return 0;
	return 1;
}

void
ReSetTimes( int Size, Container *C )
{
	int i = 0;
	for ( i = 0; i < Size; i++ )
		C[ i ]->CurTimes = 0;
}

int *
findSubstring( char *s, char **words, int wordsSize, int *returnSize )
{
	int *returnPos = NULL; 
	Container *container = NULL;
	int i = 0, j = 0; 
	int len = 0, pos = 0;

	returnPos = calloc( 100, sizeof( int ) );
	container = calloc( wordsSize, sizeof( Container ) );
	*returnSize = 0;

	if ( wordsSize > 0 )
		len = strlen( words[ 0 ] );
	else
		return returnPos;

	//Initalize
	for ( i = 0; i < wordsSize; i++ )
		container[ i ] = calloc( 1, sizeof( struct Word ) );
		

	for ( i = 0; i < wordsSize; i++ )
	{
		if ( ( pos = FindStr( len, words[ i ],  wordsSize, container ) ) != -1 )
			( container[ pos ]->Times )++;
		else
			Insert( len, words[ i ], wordsSize, container ); 
	}

	//Algorithm begins.
	for ( i = 0; s[ i ] != '\0'; i++ )
	{
		for ( j = 0; j < wordsSize; j++ )
		{
			//Compare words
			
			if ( ( pos = FindStr( len, s + i + j * len, 
							wordsSize, container ) ) != -1 )
				( container[ pos ]->CurTimes )++;
			else
				break;
		}

		if ( j == wordsSize && 
				CheckTimes( wordsSize, container ) == 1 )
		{
			returnPos[ *returnSize ] = i;
			( *returnSize )++;
		}
		ReSetTimes( wordsSize, container );
	}

	return returnPos;
}
```
写得也是非常痛苦，一天的学习时间都栽在这上面了。
如果有同学想要知道算法是怎么样的，请在下面留言，我来日补上算法描述。
