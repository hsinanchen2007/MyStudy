### 解题思路
开始直接递归法，比较粗暴,20ms,
```cpp
class Solution {
    bool interMatch(char* s, int slen, char* p,int plen){
	if(plen==0){
		return slen == 0;
	}
	if(plen == 1){
		if(slen==1){
            return p[0] =='.' ||  p[0] == s[0] ;
		}else{
			return false;
		}
	}
	if(p[1]=='*'){
		if(interMatch(s,slen, p+2,plen-2)){
			return true;
		}else{
            if(slen==0){
                return false;
            }
            char fc = p[0];
			if(fc =='.'||fc == s[0]){
				return interMatch(s+1,slen-1,p,plen);
			}else{
				return false;
			}
		}
	}else{
		if(slen == 0)
			return false;
		if(p[0] =='.'||p[0] == s[0]){
			return interMatch(s+1,slen-1,p+1,plen-1);
		}else{
			return false;
		}
	}
    }
public:
    bool isMatch(string s, string p) {
        return interMatch((char*)s.c_str(), s.length(), (char*)p.c_str(),p.length());
    }
};
```
经过改进，时候动态规划再次修改， 0ms, 8.9m

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.length();
        int plen = p.length();
		bool **dp = new bool*[slen+1];
		
        for(int i = 0; i < slen+1; i++){
            dp[i] = new bool[plen+1];
            for(int m=0;m<plen+1;m++)
                dp[i][m] = false;
        }
		for(int m=0;m<slen;m++)
			dp[m][0] = false;

		dp[0][0] = true;
		for(int m=1;m<plen+1;m++)
		{
			if(m> 1 && p[m-1]=='*'){
				dp[0][m]=dp[0][m-2];
			}else{
				dp[0][m]=false;
			}
		}
		
        for(int i=1;i<slen+1;i++){
            for(int j=1;j<plen+1;j++){
				if(j>1 && p[j-1]=='*'){
					dp[i][j] = dp[i][j-2] || (dp[i-1][j] && (p[j-2]=='.'|| (p[j-2]==s[i-1]) ));
				}else{
					dp[i][j] = dp[i-1][j-1] && (p[j-1]=='.'||p[j-1]==s[i-1]);
				}
				
            }
        }
        bool ret = dp[slen][plen];
		
		
        for(int i = 0; i < slen+1; i++){
            delete []dp[i];
        }
        delete []dp;
        return ret;
    }
};
```
