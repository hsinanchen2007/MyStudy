
类似于最长回文串的题解。改动很小。先来看最长回文串：

P(i, j) = true 如果子串Si….Sj是回文子串 false 其它情况
所以，转移状态：P(i, j) = P(i+1, j-1) && Si == Sj    max_ = max(j+1 – i, max_)
初始条件：P(i, i) = true  		 一字母： 字符个数为奇数时   max_ = 1
		  P(i, i+1) = Si == Si+1  二字母： 字符个数为偶数时  max_ = 2
			
string longestPalindrome(string s) {
    int len = s.size();
    vector<vector<bool>> p(len, vector<bool>(len, 0));
    string res;
    int max_ = -1;  // 不能赋值为1
    
    for(int j=0; j<len; j++){**
        p[j][j] = true;             // 初始化单字母
        for(int i=0; i<j+1; i++){     // [i, j] i<=j  漏了s.size()=1的情况
            // 初始化两个字母 
            if(s[i] == s[j] && j - i == 1)
                p[i][j] = 1;
            // 状态转移（三个字母或以上）
            if(s[i] == s[j] && j - i >= 2 && p[i+1][j-1])
                p[i][j] = 1;
            // 每个状态查看结果是否需要变更
            if(p[i][j] && max_ < j - i + 1){
                max_ = j - i + 1;
                res = s.substr(i, max_);  // [i, j]
            }
        }
    }
    return res;
}

定义状态f(i,j)表示区间[i,j]之间最小的cut数，则状态转移方程为：
f(i,j) = min{ f(i,k) + f(k+1, j) } 		i <= k <= j, 	0 <= i <= j < n
判断f(i,k) + f(k+1, j)是否为回文可以用最长回文串的结果
状态转移方程可转换为一维的：
初始状态：f[0]=0 f[1]=1 f[n-1] = n-1
f(j) = 区间[0, j]最小的cut数  
f(j) = min { f(i+1) + 1 },  i <= j < n	表示[0,i]的最小cut数    
**与最长回文串相比，程序增加了一维动态规划的初始化，与每个状态变化该变化时的代码。**

  
int minCut(string s) {
    int len = s.size();
    vector<vector<bool>> p(len, vector<bool>(len, 0));
    vector<int> f(len, 0);
    for(int i=0; i<len; i++)
        f[i] = i;   // f[0] = 0 f[1] = 1 f[len-1] = len-1

    for(int j=0; j<len; j++){
        p[j][j] = true;             // 初始化单字母
        for(int i=0; i<j+1; i++){     // [i, j] i<=j  漏了s.size()=1的情况
            // 初始化两个字母 
            if(s[i] == s[j] && j - i == 1)
                p[i][j] = 1;
            // 状态转移（三个字母或以上）
            if(s[i] == s[j] && j - i >= 2 && p[i+1][j-1])
                p[i][j] = 1;
            // 每个状态查看结果是否需要变更
            if (p[i][j] && i != 0) {
                f[j] = min(f[j], f[i - 1] + 1);
            }
            else if (p[i][j] && i == 0) //f[0,j]是回文串，f[j] = 0 不需要切割
                f[j] = 0;
        }
    }
    return f[len-1];
}
