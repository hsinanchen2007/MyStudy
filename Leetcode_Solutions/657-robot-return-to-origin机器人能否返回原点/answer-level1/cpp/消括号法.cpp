先判断字符串的大小，如果是奇数，则肯定回不到原地，若是偶数再利用消括号法差Hash表，打败90%


class Solution {
public:
    bool judgeCircle(string moves)
    {
       int hash[4] = { 0 };
		int i = 0;
		bool judge = 0;
		int flag = moves.size() % 2;
		if (flag != 0)
		{
			return judge = 0;
		}
		for (i = 0; i < moves.size(); i++)
		{
			switch (moves[i])
			{
			case 'R':
			{
				hash[0]++;
				break;
			}
			case 'L':
			{
				hash[1]++;
				break;
			}
			case 'U':
			{
				hash[2]++;
				break;
			}
			case 'D':
			{
				hash[3]++;
				break;
			}
			default:
				break;
			}
		}

		if (hash[0] == hash[1] && hash[2] == hash[3])
		{
			return judge = 1;
		}
		else
		{
			return judge = 0;
		}
    }
};