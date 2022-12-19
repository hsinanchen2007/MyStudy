动态规划：
1. 划分区域，将结果集划分为 * 和 ？ 分别处理
2. 自底向上求解即可，注意初始化

```
    public boolean isMatch(String s, String p) {
        int sLen = s.length(), pLen = p.length();
        boolean[][] match = new boolean[sLen+1][pLen+1];
        match[sLen][pLen] = true;
        for(int i=pLen-1; i>=0; i--){
            if(p.charAt(i)!='*')
                break;
            else
                match[sLen][i] = true;
        }
        
        for(int i=sLen-1; i>=0; i--){
            for(int j=pLen-1; j>=0; j--){
                if(p.charAt(j) == '*')
                    match[i][j] = match[i+1][j] || match[i][j+1];
                else
                    match[i][j] = match[i+1][j+1] && (s.charAt(i) == p.charAt(j) || p.charAt(j) == '?');
            }
        }
        return match[0][0];

	}
```
