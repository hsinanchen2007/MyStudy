### 解题思路
计算方法数再加上这个数据范围，很显然的状压dp
f(i,j)表示连线的最后一个在第i个位置（0~8编号），参与连线的点的状态为j（0000000000~111111111）的方案数
预处理（dfs）出当有i（0~9）个点参与连线时的所有状态，即可进行转移
在转移的过程中要注意判断是否可以转移（两个点直接连线是否合法）


### 代码

```cpp
class Solution {
private:
	int f[10][550],g[10][550];
	void dfs(int now,int cnt,int dep)
	{
		if (dep==9)
		{
			g[cnt][++g[cnt][0]]=now;
			return;
		}
		for (int i=0;i<=1;++i)
			dfs(now|(i<<dep),cnt+i,dep+1);
	}
	bool check(int state,int x,int y)
	{
		switch (x)
		{
			case 0:{
				if (y==1||y==3||y==4||y==5||y==7) return 1;
				if (y==2)
				{
					if (state&(1<<1)) return 1;
					else return 0;
				}
				if (y==6)
				{
					if (state&(1<<3)) return 1;
					else return 0;
				}
				if (y==8)
				{
					if (state&(1<<4)) return 1;
					else return 0;
				}
				break;
			}
			case 1:{
				if (y==0||y==2||y==3||y==4||y==5||y==6||y==8) return 1;
				if (y==7)
				{
					if (state&(1<<4)) return 1;
					else return 0;
				}
				break;
			}
			case 2:{
				if (y==1||y==3||y==4||y==5||y==7) return 1;
				if (y==0)
				{
					if (state&(1<<1)) return 1;
					else return 0;
				}
				if (y==6)
				{
					if (state&(1<<4)) return 1;
					else return 0;
				}
				if (y==8)
				{
					if (state&(1<<5)) return 1;
					else return 0;
				}
				break;
			}
			case 3:{
				if (y==0||y==1||y==2||y==4||y==6||y==7||y==8) return 1;
				if (y==5)
				{
					if (state&(1<<4)) return 1;
					else return 0;
				}
				break;
			}
			case 4:{
				return 1;
				break;
			}
			case 5:{
				if (y==0||y==1||y==2||y==4||y==6||y==7||y==8) return 1;
				if (y==3)
				{
					if (state&(1<<4)) return 1;
					else return 0;
				}
				break;
			}
			case 6:{
				if (y==1||y==3||y==4||y==5||y==7) return 1;
				if (y==2)
				{
					if (state&(1<<4)) return 1;
					else return 0;
				}
				if (y==0)
				{
					if (state&(1<<3)) return 1;
					else return 0;
				}
				if (y==8)
				{
					if (state&(1<<7)) return 1;
					else return 0;
				}
				break;
			}
			case 7:{
				if (y==0||y==2||y==3||y==4||y==5||y==6||y==8) return 1;
				if (y==1)
				{
					if (state&(1<<4)) return 1;
					else return 0;
				}
				break;
			}
			case 8:{
				if (y==1||y==3||y==4||y==5||y==7) return 1;
				if (y==0)
				{
					if (state&(1<<4)) return 1;
					else return 0;
				}
				if (y==2)
				{
					if (state&(1<<5)) return 1;
					else return 0;
				}
				if (y==6)
				{
					if (state&(1<<7)) return 1;
					else return 0;
				}
				break;
			}
		}
		return 0;
	}
public:
	int numberOfPatterns(int m, int n) {
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		dfs(0,0,0);
		for (int i=0;i<=8;++i) f[i][1<<i]=1;
		for (int i=1;i<=8;++i)
			for (int j=1;j<=g[i][0];++j)
			{
				int state=g[i][j];
				for (int k=0;k<=8;++k)
					if (state&(1<<k))
					{
						for (int p=0;p<=8;++p)
							if (!(state&(1<<p)))
							{
								if (check(state,k,p))
								{
									f[p][state|(1<<p)]+=f[k][state];
								}
							}
					}
			}
		int ans=0;
		for (int i=m;i<=n;++i)
			for (int j=1;j<=g[i][0];++j)
				for (int k=0;k<=8;++k)
					ans+=f[k][g[i][j]];
		return ans;
	}
};
```