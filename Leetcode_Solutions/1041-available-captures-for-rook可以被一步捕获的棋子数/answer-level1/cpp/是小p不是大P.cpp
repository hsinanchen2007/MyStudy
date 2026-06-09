### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char> >& board) {
		int ans=0;
		int cherow=-1,checol=-1;
		bool isfind;
		for(int i=0;i<board.size();i++)
		{
			isfind=false;
			for(int j=0;j<board[i].size();j++)
			{
				if(board[i][j]=='R')
				{
					cherow=i;
					checol=j;
					isfind=true;
					break;
				}
				if(isfind)
					break;
			}
		}
		if(cherow==-1||checol==-1)
			return ans;
		for(int i=cherow+1;i<board.size();i++)
		{
			if(board[i][checol]=='B')
				break;
			else if(board[i][checol]=='p')
			{
				ans++;
				break;
			}
		}
		for(int i=cherow-1;i>=0;i--)
		{
			if(board[i][checol]=='B')
				break;
			else if(board[i][checol]=='p')
			{
				ans++;
				break;
			}
		}
		for(int i=checol+1;i<board[cherow].size();i++)
		{
			if(board[cherow][i]=='B')
				break;
			else if(board[cherow][i]=='p')
			{
				ans++;
				break;
			}
		}
		for(int i=checol-1;i>=0;i--)
		{
			if(board[cherow][i]=='B')
				break;
			else if(board[cherow][i]=='p')
			{
				ans++;
				break;
			}
		}
		return ans;
    }
};
```