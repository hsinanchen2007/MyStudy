### 解题思路
![image.png](https://pic.leetcode-cn.com/676b44408482d740b037f5c6ebe284763f4532c6d808797e42fa35ef27031dcf-image.png)


### 代码

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.size()==0&&p.size()==0)
        return 1;
        if(p.size()==0)
        return 0;
	int h = p.size();
	int w = s.size();
	bool**dp = new bool*[h];
	int*len = new int[h];
	char*stk = new char[h];
	int cntlen = 0;
	for (int i = 0; i < h; i++)
	{
		int med = cntlen;
		if (p[i] != '*')
			stk[cntlen++] = p[i];
		else {
			cntlen--;
			med = max(cntlen, 0);
		}
		len[i] = med;
	}
    bool fl=true;
    if(s.size()==0)
    {for(int i=0;i<h;i++)
    if(len[i]!=0)
    return false;
    if(p.size()==1)
    return 0;
    if(cntlen!=0)
    return 0;
    return 1;
    }
	for (int i = 0; i < h; i++)
	{
		dp[i] = new bool[w];
		for (int j = 0; j < w; j++)dp[i][j] = 0;
	}
	bool vali = true;
	int las = -1;
	for (int i = 0; i < h; i++)
	{
		if (!vali)break;
		if (i == 0){
			if (p[i] == '.'){
				dp[i][0] = 1; las = 0;
			}
			else if (p[i] == '*')
				vali = false;
			else	dp[0][0] = s[0] == p[0],las=0;
		}
		else {
			if (p[i] == '.'){
				for (int j = len[i]; j < w; j++)
				{
					if(j!=0)
					dp[i][j] = dp[i][j] || dp[i - 1][j - 1];
					else dp[i][j] = 1;
				}
				las = i;
			}
			else if (p[i] == '*') {
				if(p[i-1]!='.')
				for (int j = len[i]-1; j < w; j++){
                    if(j<0)continue;
                    if(j!=0)
					{
                        dp[i][j] = dp[i-1][j]||dp[i-1][j-1]&&(s[j]==p[las]);
                    }
                    else dp[i][j] = dp[i-1][j]&&(s[j]==p[las]);
                    if(i>=2)
                        dp[i][j]=dp[i][j]||dp[i-2][j];
					dp[i][j] = dp[i][j] || dp[i - 1][j];
				}
				else for (int j = len[i]-1; j < w; j++) {
                    if(j<0)continue;
					dp[i][j] = dp[i - 1][j] || dp[i][j];
					if (j > 0)dp[i][j] = dp[i][j] || dp[i][j - 1];
                    if(i>=2)
                        dp[i][j]=dp[i][j]||dp[i-2][j];
				}
			}
			else {
				for (int j = len[i]; j < w; j++)
					if(j!=0)
					dp[i][j] = dp[i - 1][j - 1] && p[i] == s[j];
					else dp[i][j] = p[i] == s[j];
				las = i;
			}
		}
	}
	return dp[h - 1][w - 1]&&vali;
    }
};
```