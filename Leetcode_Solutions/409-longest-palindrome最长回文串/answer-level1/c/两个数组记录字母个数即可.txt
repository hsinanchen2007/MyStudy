### 解题思路
此处撰写解题思路

### 代码

```c
int longestPalindrome(char * s){
	int d[26]={0},x[26]={0};   //一个记录大写字母 一个记录小写字母
	for(int i=0;i<strlen(s);i++){
		if(s[i]>='a'&&s[i]<='z'){
			x[s[i]-'a']++;
		}
		else d[s[i]-'A']++;
	}

	int flag=0,sum=0;
	for(int i=0;i<26;i++){
		if(!flag&&(x[i]%2==1||d[i]%2==1)) flag=1;  //判断是否有奇数，技术再会文中可以放中间
		sum+=((d[i]/2)*2+(x[i]/2)*2);
	}
	return sum+flag;
}
```