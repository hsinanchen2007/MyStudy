### 解题思路
1.找到haysstack中与needle中第一个字符相匹配的位置，即为可能的匹配成功位置。
2.在第一步的基础之上进行逐个字符的匹配。若找到则成功，若找不到则继续进行第一步。

### 代码

```c
//暴力回溯法

int strStr(char * haystack, char * needle){
     int n=strlen(haystack),l=strlen(needle);
     if(l==0) return 0;
     if(n==0&&l!=0) return -1;
     int pn=0,pl=0,curlen=0;
     while(pn<n-l+1){
         while(pn<n-l+1&&haystack[pn]!=needle[0]) pn++;
         while(pn<n&&pl<l&&haystack[pn]==needle[pl]){
             pn++;
             pl++;
             curlen++;
         }
         if(curlen==l) return pn-l;
         else {
             pn=pn-curlen+1;
             pl=0;
             curlen=0;
         }
     }
     return -1;
}
```