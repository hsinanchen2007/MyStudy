### 解题思路
此处撰写解题思路

### 代码

```c
char * countAndSay(int n){
char*ret=(char*)malloc(sizeof(char)*5000);
char*signal=(char*)malloc(sizeof(char)*5000);
ret[0]='1';ret[1]='\0';
signal[0]='1';signal[1]='\0';
int i,j,k,count,m;
char flag;
for(i=1;i<n;i++){
count=1;flag=ret[0];j=1;m=strlen(ret);k=0;
while(j<m){
    if(ret[j]!=flag){
        signal[k++]=count+'0';
        signal[k++]=flag;
        flag=ret[j];
        count=1;
    }
    else{
        count++;
    }
 j++;
}
signal[k++]=count+'0';
signal[k++]=flag;
signal[k]='\0';
j=0;k=0;
while(ret[k++]=signal[j++]);   //字符串复制,将字符串signal中的数据复制进ret中;
}
return signal;
}
```