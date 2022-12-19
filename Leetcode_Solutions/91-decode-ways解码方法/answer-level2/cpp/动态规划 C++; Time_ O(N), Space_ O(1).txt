这题的动规很直观: `dp[i]` = `dp[i-1]` or `dp[i-2]` or `dp[i-1] + dp[i-2]`。主要问题时**在什么条件下**状态会**从哪里更新到哪里**。
**主要思路**：通过对当前主条件`s[i]`, 次条件`s[i-1]`分类讨论来进行状态转移。代码里`pre`, `ppre`, `curr`分别指代`dp[i-1]`,`dp[i-2]`, `dp[i]`, 这样可以将空间复杂度从O(N)降至O(1).
**注意事项**：初始化，当`i==1`(从第二个字符开始)时,即`s[i-2]`为空串(不存在)时, `pre`和`ppre`该怎么初始化？
**代码**：
```
int numDecodings(string s) {
    int len = s.size();
    if(len==0)
        return 0;
    if(len == 1)
        return s[0]!='0';
    
    int pre = s[0]!='0', ppre = 1, curr = 0;
    for(int i =1; i<len; i++){
        if(s[i]=='0'){
            if(s[i-1]=='2'||s[i-1]=='1')
                curr = ppre;
            else
                return 0;
        }
        else if(s[i]<='6'){
            if(s[i-1]=='2'||s[i-1]=='1')
                curr = pre + ppre;
            else
                curr = pre;
        }
        else{ //s[i]>'6'
            if(s[i-1]=='1')
                curr = pre + ppre;
            else
                curr = pre;
        }
        ppre = pre;
        pre = curr;
    }
    return curr;
}
```
