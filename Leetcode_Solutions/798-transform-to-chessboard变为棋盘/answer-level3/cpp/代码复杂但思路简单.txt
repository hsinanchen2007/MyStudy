### 解题思路
   分奇偶讨论，偶数比较简单，首先进行第一轮检验，将每行0，1数串转成二进制数，例如题目给的实例：[[0,1,1,0],[0,1,1,0],[1,0,0,1],[1,0,0,1]]，第一行可以转成0110，十进制是6，记为num1，第三行可以转成1001，十进制是9，记为num2，再判断是否不同行之间转成二进制数后只有两种不同值的数num1，num2，且数的个数相同(N为偶数)或差一(N为奇数),对列做同样处理。如果不满足则返回-1；如果满足，则说明可以变为棋盘，进行第二步查找解。
   当N为偶数，观察发现，将不同行的0，1数串转成二进制后，只有两个不同的数，即每行的0，1构成的二进制数要不是num1，要不是num2，若要变成棋盘，则每个偶数行所有的0，1构成的二进制数应该都是一样的，即每个偶数行都是0101或每个偶数行都是1010，奇数行也是，在这个结论的基础之上我们可以找到最小的调换次数，即取第一个数在奇数行的次数和第一个数在偶数行的次数的最小值，之所以可以这么取，是因为只要奇数行的二进制数相同且偶数行的二进制数相同就可以在纵向上满足棋盘要求，将奇数行的num2换成num1或num1换成num2即可，在不同方案中取最小值，对不同列也是这样处理。当N为奇数时，大体和偶数行一样处理，但是奇数行只能是num1和num2中出现次数较少的，偶数行只能是num1和num2出现次数较多的，列也是同样处理。

### 代码

```cpp
class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
    vector<vector<int>>boards=board;
    int N=boards.size();
	int*V = new int[N];
	int*H = new int[N];
	for (int i = 0; i < N; i++)
	{
		H[i] = 0;
		for (int j = 0; j < N; j++)
		{
			H[i] += boards[i][j]*static_cast<int>(pow(2, j));
		}
	}
	for (int j = 0; j < N; j++)
	{
		V[j] = 0;
		for (int i = 0; i < N; i++)
		{
			V[j] += boards[i][j] *static_cast<int>(pow(2, i));
		}
	}
	   int res=-2;
		int num1_id = 0;
		int num2_id = -1;
		int count1_H = 0;
		int count2_H = 0;
		for (int i = 0; i < N; i++)
		{
			if (H[i] == H[num1_id])
				count1_H++;
			else if (num2_id == -1)
			{
				num2_id = i;
				count2_H++;
			}
			else if (H[i] == H[num2_id])
				count2_H++;
			else
			{
				res = -1;
				break;
			}
		}
		if (res != -1)
		{
			if (N % 2 == 0)
			{
				if (!(count1_H == count2_H && count1_H == N / 2))
					res = -1;
			}
			else if (!(count1_H == N / 2 && count2_H == N / 2 + 1 || count2_H == N / 2 && count1_H == N / 2 + 1))
				res = -1;
		}
		num1_id = 0;
		num2_id = -1;
		int count1_V = 0;
		int count2_V = 0;
		for (int i = 0; i < N; i++)
		{
			if (V[i] == V[num1_id])
				count1_V++;
			else if (num2_id == -1)
			{
				num2_id = i;
				count2_V++;
			}
			else if (V[i] == V[num2_id])
				count2_V++;
			else
			{
				res = -1;
				break;
			}
		}
		if (res != -1)
		{
			if (N % 2 == 0)
			{
				if (!(count1_V == count2_V && count1_V == N / 2))
					res = -1;
			}
			else if (!(count1_V == N / 2 && count2_V == N / 2 + 1 || count2_V == N / 2 && count1_V == N / 2 + 1))
				res = -1;
		}
		if (res != -1)
		{
			res = 0;
			int even_1 = 0;
			int odd_1 = 0;
			int even_2 = 0;
			int odd_2 = 0;
			for (int i = 0; i < N; i++)
			{
				if (H[i] == H[0])
					if (i % 2 == 0)
						even_1++;
					else odd_1++;
				else if (i % 2 == 0)
					even_2++;
				else odd_2++;
			}
			if(N%2==0)
			res += (count1_H - even_1 > odd_1 ? even_1 : odd_1) < (count2_H - even_2 > odd_2 ? even_2 : odd_2)
				? (count1_H - even_1 > odd_1 ? even_1 : odd_1) : (count2_H - even_2 > odd_2 ? even_2 : odd_2);
            else {
                if(count1_H>count2_H)
                  res+=count1_H-even_1;
                else res+=count2_H-even_2;
            }
			even_1 = 0;
			odd_1 = 0;
			even_2 = 0;
			odd_2 = 0;
			for (int i = 0; i < N; i++)
			{
				if (V[i] == V[0])
					if (i % 2 == 0)
						even_1++;
					else odd_1++;
				else if (i % 2 == 0)
					even_2++;
				else odd_2++;
			}
            if(N%2==0)
			res += (count1_V - even_1 > odd_1 ? even_1 : odd_1) < (count2_V - even_2 > odd_2 ? even_2 : odd_2)
				? (count1_V - even_1 > odd_1 ? even_1 : odd_1) : (count2_V - even_2 > odd_2 ? even_2 : odd_2);
            else {
                if(count1_V>count2_V)
                  res+=count1_V-even_1;
                else res+=count2_V-even_2;
            }
	    }
	return res;
    }
};
```