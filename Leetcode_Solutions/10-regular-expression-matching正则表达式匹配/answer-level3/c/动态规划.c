bool isMatch(char * s, char * p){
    int m,n;
    int i ,j;
	if(s==NULL||p==NULL) return false;

	m = strlen(s); n = strlen(p);
	
	bool **f = (bool **)malloc(sizeof(bool *)*(m+1));
    for(i = 0;i<=m;i++){
        f[i] = (bool *)malloc(sizeof(bool) *(n+1));
    }

	for(i = 0;i<=m;i++){
		for(j = 0;j<=n;j++){
		   f[i][j] = false;
		}	
	}

	//bool f[100][100] = {false};
    f[0][0] = true;//dp[i][j] 表示 s 的前 i 个是否能被 p 的前 j 个匹配

    for(int i = 2; i <= n; i++){
        f[0][i] = f[0][i - 2] && p[i - 1] == '*';
    }
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s[i - 1] == p[j - 1] || p[j - 1] == '.'){
                f[i][j] = f[i - 1][j - 1];
            }
            if(p[j - 1] == '*'){
                f[i][j] = f[i][j - 2] || 
                f[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.');
            }
        }
    }
    
    return f[m][n];
}