### 解题思路
此处撰写解题思路

### 代码

```c
char * addBinary(char * a, char * b){
int n=strlen(a);
int m=strlen(b);
int*arr=(int*)malloc(sizeof(int)*(m+n));
int i,j,k=0,cut=0,p=0,temp;
i=n-1;j=m-1;
while(i>-1&&j>-1){
    cut=(a[i]-'0'+b[j]-'0'+k);
    k=cut/2;
    cut=cut%2;
    arr[p++]=cut;
    i--;j--;
}
while(i>-1){
    cut=a[i--]-'0'+k;
     k=cut/2;
    cut=cut%2;
    arr[p++]=cut;
}
while(j>-1){
    cut=b[j--]-'0'+k;
    k=cut/2;
    cut=cut%2;
    arr[p++]=cut;
}
if(k>0)
arr[p++]=k;

//颠倒位置
for(i=0,j=p-1;i<j;i++,j--){
    temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
//转成字符数组
char*ret=(char*)malloc(sizeof(char)*(p+1));

for(i=0;i<p;i++){
    ret[i]=arr[i]+'0';
}
ret[p]='\0';
return ret;
}
```