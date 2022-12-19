有能力的小伙伴可以去了解下 傅里叶变换，复杂度好像是 O(N*logN) 还是 O(N) 忘记了。

下面介绍的是，复杂度比较高的算法。

例如：123 * 456 = 56088,

小学竖式计算：

              1  2  3
          x   4  5  6
        ----------------
              7  3  8
           6  1  5  0  ---> 在末尾补 1个0
        4  9  2  0  0  ---> 在末尾补 2个0
       -----------------
        5  6   0  8  8

初始化 ret=""。

为方便计算，字符串的乘法 从后往前 进行乘，字符串的加法 从前往后 进行加。

第一步：将 "456" 中的 "6" 与 "123" 做乘法, 得到 s="837"，第一次乘需补0个0，
       所以 s="837", 然后 s 与 ret 做加法, 得到 ret = "837".

第二步：将 "456" 中的 "5" 与 "123" 做乘法, 得到 s="516", 第二次乘需补1个0,
       所以 s = "0516", 然后 s 与 ret 做加法, 得到 ret = "8886".

第三步: 将 "456" 中的 "4" 与 "123" 做乘法, 得到 s="294", 第三次乘需补2个0,
       所以 s = "00294", 然后 s 与 ret 做加法，得到 ret = "88065".

最后将 ret逆序，然后返回ret即可。



哎，写滴太菜了 还是贴代码吧：

```c
// 反转字符串中[left,right]区间的字符.
static void reverseString( char s[], int left, int right ) {
	char temp = '\0';

	while( left < right ) {
		temp = s[left];
		s[left++] = s[right];
		s[right--] = temp;
	}
}

// 字符串的模拟加法,将结果存回s1中.
static void additionString( char s1[], char s2[] ) {
	char buf[BUFSIZ] = {'\0'};
	int ib = 0, i1 = 0, i2 = 0, n = 0, jw = 0;

	while( '\0' != s1[i1] || '\0' != s2[i2] || jw > 0 ) {
		n = jw;
		n += '\0' != s1[i1] ? s1[i1++] - '0' : 0;
		n += '\0' != s2[i2] ? s2[i2++] - '0' : 0;
		jw = n < 10 ? 0 : 1;
		n -= n < 10 ? 0 : 10;
		buf[ib++] = n + '0';
	}
	strcpy( s1, buf );
}

char *multiply( char *num1, char *num2 ) {
	int len1 = strlen( num1 ), len2 = strlen( num2 );
	int i1 = 0, i2 = 0;
	int jw = 0, n = 0;
	char buf[BUFSIZ] = {'\0'};
	int bi = 0;
	char *returnArray = NULL;

	if( num1[0] == '0' && num1[1] == '\0' ) { // 例如, num1="0", num2="123".
		return num1;
	}
	if( num2[0] == '0' && num2[1] == '\0' ) { // 例如: num1="123", num2="0".
		return num2;
	}
	if( num1[0] == '1' && num1[1] == '\0' ) { // 例如: num1="1", num2="123".
		return num2;
	}
	if( num2[0] == '1' && num2[1] == '\0' ) { // 例如: num1="123", num2="1".
		return num1;
	}

	returnArray = malloc( sizeof(char) * 54321 );
	returnArray[0] = '\0';

	for( i2 = len2 - 1; i2 >= 0; --i2 ) {
		jw = 0;
		for( bi = 0; bi < len2 - 1 - i2; ++bi  ) { // 补0.
			buf[bi] = '0';
		}
		for( i1 = len1 - 1; i1 >= 0 || jw > 0; --i1 ) {
			n = num2[i2] - '0';
			n *= i1 >= 0 ? num1[i1] - '0' : 0;
			n += jw;
			jw = n / 10;
			n = n % 10;
			buf[bi++] = n + '0';
		}
		buf[bi] = '\0';
		additionString( returnArray, buf ); // 做加法.
	}
	reverseString( returnArray, 0, strlen( returnArray ) - 1 ); // 反转.

	return returnArray;
}

```
