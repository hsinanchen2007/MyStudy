### 解题思路
用的滑动窗口的思想，内存越界改的我好苦
执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :7.1 MB, 在所有 C 提交中击败了65.06%的用户
### 代码

```c
int lengthOfLongestSubstring(char * s){
    if(*s=='\0') return 0;
    int len=1,maxlen=1;
    int i=0,j=0,t=i;
    while(s[j]!='\0'){
    	len=1;
    	t=i;
    	while(t<j&&s[t]!=s[j]){
    		len++;
    		t++;
		}
		if(maxlen<len)
			maxlen=len;
		if(t==j){
			j++;
		}
		else{
			i=t+1;
			j=j+1;
		}
    } 
    return maxlen;
}
```