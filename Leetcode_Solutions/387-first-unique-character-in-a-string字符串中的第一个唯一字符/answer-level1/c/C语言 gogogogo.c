### 解题思路
找到相应位置的号码 要用s[j]-'a'表示b数组的号 比较巧妙
原理就是利用俩数组 一个存放abcd 一个计数 最后统计计数那个数组 按标号来找 其实就是字符减去a 就是数字
### 代码

```c
int firstUniqChar(char * s){
     int i,j;
     int l=strlen(s);
     char a[26];
     int  b[26]={0};
     if(l == 0)
      return -1;
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
     for(j=0;j<l;j++){
         if(b[s[j]-'a']==1){
             return j;
         }
     }
     return -1;
}
```