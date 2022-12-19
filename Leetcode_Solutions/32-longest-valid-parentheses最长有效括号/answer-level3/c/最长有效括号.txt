### 解题思路
参照题解，正反循环

### 代码

```c
int longestValidParentheses(char * s) {
	int maxLen = 0;
    int left=0,right=0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='(') left++;
        else right++;
        if(left==right){
            maxLen = right*2>maxLen?right*2:maxLen;
        }else if(right>=left){
            left=right=0;
        }
    }
    left=right=0;
    for(int i=strlen(s)-1;i>=0;i--){
        if(s[i]=='(') left++;
        else right++;
        if(left==right){
            maxLen = left*2>maxLen?left*2:maxLen;
        }else if(left>=right){
            left=right=0;
        }
    }
    return maxLen;
}
```