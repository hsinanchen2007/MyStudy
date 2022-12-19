1.除去空格
2.递归:
    (1)判断每个数字前面的符号
    (2)乘除在函数中计算，加减用递归计算
```
int ss(int i,char s[],int n) {
	if(i==n)
		return 0;
	int a=0;
	char cc='+';
	if(s[i]=='+')
		i++;
	if(s[i]=='-'){
		cc='-';
		i++;
	}
	while(i<n&&s[i]<='9'&&s[i]>='0') {
		a*=10;
		a+=s[i]-'0';
		i++;
	}
	while(s[i]=='*'||s[i]=='/') {
		char c=s[i];
		i++;
		double b=0;
		while(i<n&&s[i]<='9'&&s[i]>='0') {
			b*=10;
			b+=s[i]-'0';
			i++;
		}
		if(c=='*')
			a*=b;
		else
			a/=b;
	}
	if(cc=='+') 
		return ss(i,s,n)+a;
	return ss(i,s,n)-a;
}
int calculate(char * s){
    int n=strlen(s);
    int m=0;
    for(int i=0;i<n;i++){
        if(s[i]!=' ')
        s[m++]=s[i];
    }
    s[m]='\0';
    return ss(0,s,m);
}
```
