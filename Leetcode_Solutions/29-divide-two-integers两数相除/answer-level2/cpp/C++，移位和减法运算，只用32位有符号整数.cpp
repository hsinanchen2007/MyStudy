首先，先将一些边界情况进行处理，比如dividend为INT_MIN，而divisor为+-1的时候，等等；
之后，将dividend和divisor都转化为正数，注意，当dividend是INT_MIN时转化为整数没有办法处理，那就将dividend转化为INT_MAX，标记Mark为1，其他情况下Mark都为0，Mark的作用是，当计算出均被转化为正数的dividend和divisor的商和余数时，将余数加上Mark，然后用新的余数和divisor去比较，假如新的余数>=divisor的话，就将商加一；
而计算两个正数的商和余数的办法是，设被除数的位数为m，除数的位数为n,将被除数每次左移m-n位，使得被除数与除数的位数相等，比较被除数与除数的大小，判断商在这一位上的大小为0还是1，然后更新被除数。不断循环，最终得到商和余数；
代码如下：
int divide(int dividend, int divisor)
{
	if (dividend == INT_MIN&&divisor == -1)//溢出的情况;
		return INT_MAX;
	if (divisor == 1)
		return dividend;
	if (dividend == divisor)//被除数和除数相等的情况
		return 1;
	else if (divisor == INT_MIN)//除数为INT_MIN的情况;
		return 0;//将这些特殊的情况先进行处理;
	int judge = true;//代表得到的是个正数，还是负数；
	int mark = 0;
	if (dividend == INT_MIN)//假如直接将INT_MIN转化为整数的话，会溢出，
	//因此将其转化为INT_MAX，并且标记Mark为1;
	{
		mark = 1;
		dividend++;
	}
	if (dividend<0)
	{
		dividend = -dividend;
		judge = !judge;
	}
	if (divisor<0)
	{
		divisor = -divisor;
		judge = !judge;
	}//假如是INT_MIN,会被转换为INT_MAX,并且Mark为1，其他情况下Mark都为0；
	int m = 0;
	int n = 0;
	int ans = 0;
	int op1 = dividend;
	int op2 = divisor;
	while (op1>0)
	{
		op1 = (op1 >> 1);
		m++;
	}//m表示dividend的位数；
	while (op2>0)
	{
		op2 = (op2 >> 1);
		n++;
	}//n表示dividend的位数;
	if (m<n)
		return 0;
	op1 = dividend;
	op2 = divisor;
	int sub = m - n;
	int temp = (op2 << sub);
	while (sub >= 0)
	{
		temp = (op2 << sub);
		if (temp <= op1)
		{
			op1 -= temp;
			ans = ans | (1 << sub);
		}
		sub--;
	}
	if (mark == 1)
		op1++;
	if (op1 >= op2)
		ans++;
	if (!judge)
		ans = -ans;
	return ans;
}