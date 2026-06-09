### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
private:
	vector<vector<int> >cb;
	int check(int row,int col)
	{
		int cnt=0,res;
		for(int i=-1;i<=1;i++)
		{
			for(int j=-1;j<=1;j++)
			{
				if(i==0&&j==0)
					continue;
				if(row+i<cb.size()&&row+i>=0&&col+j<cb[row+i].size()&&col+j>=0)
				{
					if(cb[row+i][col+j]==1)
						cnt++;
				}
			}
		}
		if(cb[row][col]==1)
		{
			if(cnt==2||cnt==3) 
				res=1;
			else
				res=0;
		}
		else
		{
			if(cnt==3)
				res=1;
			else
				res=0;
		}
		return res;
	}		
public:
    void gameOfLife(vector<vector<int> >& board) {
		cb=board;
		for(int i=0;i<board.size();i++)
		{
			for(int j=0;j<board[i].size();j++)
			{
				board[i][j]=check(i,j);
			}
		}
        cout<<'[';
		for(int i=0;i<board.size();i++)
		{
            cout<<'[';
			for(int j=0;j<board[i].size();j++)
			{
				cout<<board[i][j];
                if(j<board[i].size()-1)
                    cout<<',';
			}
            if(i<board.size()-1)
			cout<<"],";
            else
                cout<<"]";
		} 
        cout<<']';
    }
};
```