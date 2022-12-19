### 解题思路
此处撰写解题思路
BF算法
### 代码

```c
int strStr(char * haystack, char * needle){
     int i=0,j=0,ret=-1;
     while(haystack[i]!='\0'&&needle[j]!='\0'){
         if(haystack[i]==needle[j]){
             i++;
             j++;
         }else{
             i=i-j+1;            //回溯
             j=0;
         }
     }
        
     if(needle[j]=='\0')
         ret=i-j;
     return ret;
}
```