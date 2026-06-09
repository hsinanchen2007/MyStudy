```
char * gcdOfStrings(char * str1, char * str2){
    int len1=0,len2=0,i=0,shortlen,longlen,sublen=0;//记录两字符串的长度，确定公因串的长度
    char c=str1[i],*ans;
    while(c!='\0') {len1++;c=str1[++i];}
    i=0;c=str2[i];
    while(c!='\0') {len2++;c=str2[++i];}
    if(len1>len2) {shortlen=len2;longlen=len1;}
    else {shortlen=len1;longlen=len2;}
    int elem[shortlen],size=0;
    for(int j=1;j<=shortlen;j++) //算出较短串的长度的因数
        if(shortlen%j==0) elem[size++]=j;
    size--;
    for(int j=0;j<=size;j++)//非公因数变为0
        if(longlen%elem[j]!=0) elem[j]=0;
        int k=0,j,h;
    while(k<=size) {
        if(elem[k]!=0) {//为公因数
            for(j=0;j<elem[k];j++) {
                if((int)str1[j]!=(int)str2[j]) break;//判断是否可能是公因串
            }
            if(j==elem[k]) {
                for(i=1;i<len1/j;i++) {//i次子串对比
                    for(h=0;h<j;h++) {//0到公因数-1序号的字符对比
                        if((int)str1[h+i*j]!=(int)str1[h]) break;
                    }
                    if(h<j) break;
                }
                if(i==len1/j) sublen=j;
            }
        }
        k++;
    }
    if(sublen>0) {
        ans=(char*)malloc(sizeof(char)*(sublen+1));
        for(i=0;i<sublen;i++) ans[i]=str1[i];
        ans[i]='\0';
    }
    else {
        ans=(char*)malloc(sizeof(char));
        ans[0]='\0';
    }
    return ans;
}
```
