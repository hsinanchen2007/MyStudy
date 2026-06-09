

```c
void reverse(char*s,int start,int end){
	char temp;
	while(start<end){
		temp=s[start];
		s[start++]=s[end];
		s[end--]=temp;
	}
}
char * reverseWords(char * s){
	int start=0,end;
	int len=strlen(s);
	for(int i=0;i<len;i++){
		if(s[i]==' '||i==len-1){
			i==len-1? (end=i):(end=i-1);
			reverse(s,start,end);
			start=i+1;
		}
	}
	return s;
}
```