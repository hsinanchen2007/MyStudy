### 解题思路
分别统计计数两串出现的字母，然后一一比较个数 不一致就输出

### 代码

```c
char findTheDifference(char * s, char * t){
    int i,j;
     int l=strlen(s);
     int ll=strlen(t);
     char a[26];
     int  b[26]={0};
     int  c[26]={0};
     if(l==0){
         char d=t[0];
         return d;
     }
     for(i=0;i<26;i++){
         a[i]='a'+i;
     }
    
     for(i=0;i<l;i++){
         for(j=0;j<26;j++){
           if(a[j]==s[i]){
                b[j]+=1;
           }
         }
     }
          for(i=0;i<ll;i++){
         for(j=0;j<26;j++){
           if(a[j]==t[i]){
                c[j]+=1;
           }
         }
     }
     for(j=0;j<ll;j++){
         if(b[j]!=c[j]){
             return a[j];
         }
     }
     return 0;
}
```