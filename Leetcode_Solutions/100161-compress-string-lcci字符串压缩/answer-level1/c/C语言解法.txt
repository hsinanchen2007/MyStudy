### 解题思路
此处撰写解题思路

### 代码

```c
char* itoa(int a,int d){
    int acpy=a;int z=0;
    while(acpy>0){
        z++;
        acpy=acpy/10;
    }
    char *str=(char*)malloc(sizeof(char)*(z+1));
    str[z]='\0';
    while(a>0){
        str[--z]=a%10+'0';a=a/10;
    }
	return str;
}
char *intochar(int *a,char *c,int lendex,int len){
    char * output=(char*)malloc(sizeof(char)*len);
    char *str;
    int count=0;
    for(int i=0;i<lendex;i++){
        output[count++]=c[i];
        str=itoa(a[i],10);
		int j=0;
        while(*(str+j)){
            output[count++]=*(str+j);j++;
        }
    }
	output[count++]='\0';
    return output;
}
char* compressString(char* S){
    int len=strlen(S);
    if(len==0||len==1){
        return S;
    }
	char *c=(char*)malloc(sizeof(char)*len);
    int *a=(int*)malloc(sizeof(int)*len);
    int cdex=0;int adex=0;int count=1;
    char now=S[0];c[cdex++]=S[0];
    for(int i=1;i<len;i++){
        if(S[i]==now){
            count++;
        }else{
            a[adex++]=count;
            c[cdex++]=S[i];
			count=1;
            now=S[i];
        }
    }
	a[adex++]=count;
    if(adex+cdex>=len){
        return S;
    }
    return intochar(a,c,adex,len);
}
```