分析题意，就是将1-26的数字对应成字母，然而所有数字都写在一个数组里，因此可能出现两个数字组成一个数的情况，也会出现单独一个进行解码的情况，那么最直接的思路就是判断每一位要不要和下一位组成一个数，这样就可以使用递归的方式实现，若单独一位，则下次递归时，选择的位置前进一个即可，若要和下一个一起组成，则下次递归时，选择的位置前进两个，该种情况下，一旦出现单独的0，该种解码方式则宣告失败。然而递归的方式不可避免的出现大量的重复计算，我们可以找一个初始化为-1的数组进行计算结果的记录，进行下一次递归前，判断要计算的这个值是否已经计算了，若已经计算过了，就可以直接使用，若没有，则继续进行递归操作，运行时间4ms，击败98.10%的用户。
```
int dfs(string&s, int index,vector<int>&mem)
{
	if (index == s.size())
	{
		return 1;
	}
	int sum = 0;
	if (s[index] == '0')					//若出现单独的0，则此时就可以返回了，不符合规则
	{
		return 0;
	}
	else if (s[index] != '0')				//数为单个
	{
		if (mem[index + 1] == -1)			//先判断是否计算过了
		{
			int temp= dfs(s, index + 1, mem);
			mem[index + 1] = temp;
			sum += temp;	
		}
		else
		{
			sum += mem[index + 1];
		}
		
	}
	if (index<=s.size()-2&&((s[index] == '2'&&s[index+1]<='6')||(s[index] == '1'&&s[index + 1] <= '9')))
	{
		if (mem[index + 2] == -1)			//先判断是否计算过了
		{
			int temp = dfs(s, index + 2, mem);
			mem[index + 2] = temp;
			sum += temp;
		}
		else
		{
			sum += mem[index + 2];
		}
	}
	return sum;
}

int numDecodings(string s) 
{
	int result = s.size();
	if (result == 0)
	{
		return result;
	}
	else if (result == 1 && s[0] != '0')
	{
		return result;
	}
	else if (s[0] == '0')
	{
		return 0;
	}
	vector<int> mem(s.size()+1, -1);	//记录计算的值
	result = dfs(s, 0,mem);
	return result;

}
```