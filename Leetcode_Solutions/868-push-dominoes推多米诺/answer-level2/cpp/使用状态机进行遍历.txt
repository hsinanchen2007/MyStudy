考虑L和R的各种状态，分析下来只有以下几种，这里前指的是左侧，后指的是右侧：

* L前边没有字母
* L前边第一个字母是L
* L前边第一个字母是R
* R前边第一个字母是R
* R后边没有字母

其中之所以考虑L前边和R后边有没有字母，而不考虑L后边和R前边有没有字母或者是何字母，是因为倒的方向，L不向右倒，因此L后边的与本L无关，同理，R前边的也是一样，我们不管他，保持原样即可。

1.对于L前边第一个字母是L的和L前边没有字母的，我们可以合并，因为都要从本L处往前写入L，直到遇见上一个字母或者数组越界。

2.对于L前边第一个字母为R的，要使用双指针，分别从本L和上一个R处开始遍历，分布写入L和R，为了满足某位同时被左右作用时保持不变的特性，左指针必须严格小于右指针。上一个R位置的记录可以由一个变量在其他状态中记录。

3.一旦出现R，我们就要记录该R的位置，以供匹配或其他状态使用，对于本R前边第一个字母是R的，应当从上一个R处开始遍历，写入R，直到到达本位置为止。

4.对于R后边没有字母的，当对原数组遍历完成后，才能发现该状态，因此应当在循环外补上。

```
string pushDominoes(string dominoes) 
{
	bool flag = false;                //标识R是否在等待匹配
	int start = 0;                      //上一个R的位置
	for (int i = 0; i < dominoes.size(); i++)
	{
		if (dominoes[i] == 'L')
		{
			if (flag == false)		//不是配对的L
			{
				for (int r = i - 1; r>=0&&dominoes[r] == '.'; r--)
				{
					dominoes[r] = 'L';
				}
			}
			else                     //是配对的L
			{
				for (int l = start + 1,r=i-1; l < i&&l<r; l++,r--)
				{
					
					dominoes[l] = 'R';
					dominoes[r] = 'L';
					
				}
				flag = false;

			}
		}
		else if (dominoes[i] == 'R')
		{
			if (flag)			//R之前还是R
			{
				for (int l = start + 1; l < i; l++)
				{
						dominoes[l] = 'R';
				}
			}
			flag = true;
			start = i;
		}
	}
	if (flag)
	{
		for (int l = start + 1; l < dominoes.size(); l++)
		{
			dominoes[l] = 'R';
		}
	}
	return dominoes;
}
```
