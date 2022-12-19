1、转为负数处理，避免溢出，因为从INT_MIN（-2147483648）转为正数时会溢出INT_MAX=2147483647

2、从被除数中减掉除数，直到不够再减一次除数。即使被除数进入区间（divisor，0）,divisor为负。

3、使用二分法，加快被除数进入到区间（divisor，0）的速度：
    具体的，使除数翻倍，直到被除数小于除数（这里都转成了负数，所以是小于）
    当被除数大于翻了数倍后的除数时，再使除数逐渐减倍。

4、c++负数左右移位的问题，可能是力扣编译器的问题，在vs2019中负数左右移位并没有什么问题
    左移：强转unsigned int 再左移
    右移：强转unsigned int 右移，然后通过位或将符号位置1即可。

```
int divide( int dividend, int divisor)
{
	if ( dividend == 0 || divisor == 0 )return 0;
	bool sign = ( dividend ^ divisor ) >= 0; //判断符号是否相同，相同为true
	if (dividend > 0) dividend = -dividend; //转为负数处理，避免INT_MIN转正数时溢出
	if (divisor > 0) divisor = -divisor;    //转为负数
		
	int ret = 0; //输出 
	int cnt = -1;    //记录二分法divisor数量，使用负数，避免溢出
	int tmp = dividend;  //被除数
	int divisorTmp = divisor; //除数

	//判断除数是否可以翻倍，以及翻倍后是否大于被除数
	while ( divisorTmp > ( (unsigned int)INT_MIN >> 1| 0x80000000 ) && tmp <= ((unsigned int)divisorTmp << 1) )
	{   
		divisorTmp = (unsigned int)divisorTmp << 1;//除数翻倍
		tmp -= divisorTmp; //从被除数中减掉 
		cnt = (unsigned int)cnt<< 1;  //记录减掉的除数的数量
		ret += cnt; //合并到总数里
	}
	//此时除数可能是被除数的2n倍，接下来对其进行减倍。
	while (tmp <= divisor)
	{
		if (tmp <= divisorTmp) 
		{
			tmp -= divisorTmp; //满足该条件时，继续从被除数中减掉除数
			ret += cnt;        //并将数量合并到总数
		}
		else if ( ( (unsigned int)divisorTmp >> 1 | 0x80000000 ) <= divisor)
		{
			divisorTmp =  (unsigned int)divisorTmp >> 1 | 0x80000000;  //除数减倍
			cnt = (unsigned int)cnt >> 1 | 0x80000000;   //数量减倍
		}
	}
	if (sign) //被除数除数符号相同时，将结果转为正数
	{
		if (INT_MIN == ret) ret = INT_MAX; //由负数转为正数时可能溢出，将溢出情况排除掉
		else ret = -ret; 
	}

	return ret;
}
```