### 代码

```c
bool isSubsequence(char * s, char * t){
     int len1=strlen(s);
     if(len1==0) return 1;
     int len2=strlen(t);
     char* temp=t;
     for(int i=0;i<len1;i++)
     {
         char* pos=strchr(temp,s[i]);
         if(pos==NULL) return 0;
         temp=++pos;
     }
     return 1;
}
```