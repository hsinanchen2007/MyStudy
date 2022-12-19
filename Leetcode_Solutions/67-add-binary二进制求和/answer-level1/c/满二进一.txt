### 解题思路
此处撰写解题思路
直接上代码
### 代码

```c
void reverse(char *a)
{
    int j=strlen(a)-1, i=0, temp;
    for(; i<j; i++, j--){
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}
char * addBinary(char * a, char * b){
    reverse(a);
    reverse(b);
    char *ans=(char*)malloc(sizeof(char)*1000);
    int i=0, j=0, pos=0, jinwei=0;
    while(a[i]!='\0'||b[j]!='\0'){
        int numa= a[i]=='\0' ? 0 : a[i]-'0';
        int numb= b[j]=='\0' ? 0 : b[j]-'0';
        ans[pos++]=(numa+numb+jinwei)%2 + '0';
         jinwei=(numa+numb+jinwei)/2;
         if(a[i]!='\0') i++;
         if(b[j]!='\0') j++;
    }
    if(jinwei==1)
    ans[pos++]='1';
    ans[pos]='\0';
    reverse(ans);
    return ans;
}
```