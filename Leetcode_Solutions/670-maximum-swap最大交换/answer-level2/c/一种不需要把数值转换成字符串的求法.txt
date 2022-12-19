
![1.png](https://pic.leetcode-cn.com/2db91b5265f47db7ae5ad98cfab8c2011bd0507901a2285a26d4879b194d61c8-1.png)
首先要交换的两位分为左边和右边，显然右边比左边低位，于是在对number模10保存结果到Digit时，用PreviousDigit保存上次求余得到的低一位数，左边的待交换位以Digit为基础，右边的待交换位以PreviousDigit为基础，循环过程中每次先求出右边的交换位，然后再以最新的右边交换位为依据求出左边的交换位。如果数字的所有位的值有一部分是按倒序排列，即Digit>PreviousDigit，那么显然右边的交换位顶多只能取到这部分的最低位；如果有一部分位是重复的数字，右边交换位同理最多只能取到其中的最低位，并且这若干个重复数字位于最高的位时，右边交换位不能取其中的任意一位。
于是得到取出右边交换位和左边交换位的初步逻辑：
if(Digit<=PreviousDigit && PreviousDigit>RightDigit) 
RightDigit = PreviousDigit; 
if (Digit < RightDigit) 
LeftDigit = Digit;
这个逻辑还需要排除一种情况，那就是Digit=PreviousDigit时，从Digit到最高位的数值都是等于Digit，RightDigit不应等于Digit，不过LeftDigit的赋值逻辑决定了这种情况下左边位的位数会小于右边位的位数，我们只要每次对RightDigit赋值前用PreviousRightDigit保存当前值，在最后计算时根据相应判断来决定取用RightDigit还是回溯使用PreviousRightDigit即可。
代码通过了10万个随机数的检验，将函数中的int改成__int64，可支持更大范围整数的求解。
代码写的很乱，若有改进建议，还请多多指教。
```
int maximumSwap(int num)
{
	int Result = num;
	if (Result > 11)
	{
		unsigned int PreviousDigit, Digit, Base, LeftBase, PreviousRightBase, RightBase, LeftDigit, PreviousRightDigit, RightDigit;
		Base = LeftBase = PreviousRightBase = RightBase = 1;
		PreviousDigit = LeftDigit = PreviousRightDigit = RightDigit = num % 10;
		num /= 10;
		while (num)
		{
			Digit = num % 10;
			num /= 10;
			if (Digit <= PreviousDigit && PreviousDigit > RightDigit)
			{
				PreviousRightDigit = RightDigit;
				PreviousRightBase = RightBase;
				RightDigit = PreviousDigit;
				RightBase = Base;
			}
			Base *= 10;
			if (Digit < RightDigit)
			{
				LeftDigit = Digit;
				LeftBase = Base;
			}
			PreviousDigit = Digit;
		}
		if (LeftBase >= RightBase)
			Result += (RightDigit - LeftDigit) * (LeftBase - RightBase);
		else
			Result += (PreviousRightDigit - LeftDigit) * (LeftBase - PreviousRightBase);
	}
	return Result;
}
```
