### 解题思路
若s2是由s1翻转得到的，则s2必是s1+s1的子串，故先看s1+s1的长度是否是s2的两倍，再用模式匹配

### 代码

```c
#include <string.h>
bool pattern(char* s1,char*s2){
    int i=0,j=0;
    while(s1[i]!=0&&s2[j]!=0){
        if(s1[i]==s2[j]){
            i++;j++;
        }else{
            i=i-j+1;
            j=0;
        }
    }
    return s2[j]==0;
}
bool isFlipedString(char* s1, char* s2){
    if(*s1==0&&*s2==0){
        return true;
    }
    int len1=2*strlen(s1);
    int len2=strlen(s2);
    if(len1!=2*len2){
        return false;
    }
    char*s=(char*)malloc((len1+1)*sizeof(char));
    memset(s,0,(len1+1)*sizeof(char));
    int i=0;
    while(i<len1){
        s[i]=s1[i%(len2)];
        i++;
    }
    return pattern(s,s2);
}
```