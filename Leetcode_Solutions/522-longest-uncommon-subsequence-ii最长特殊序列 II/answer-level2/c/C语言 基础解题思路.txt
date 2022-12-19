### 解题思路
最大特殊子串一定是输入的这些字符串中的一个，因为如果字符串的子串满足跟其他字符串不重复的条件，则整个字符串也满足这个条件；所以我们只需要找到所有输入字符串中跟其他字符串【不重复】的字符串即可；
1.按照字符串长度从大到小排序
2.排序完成之后，判断跟当前字符串相同长度的后面的字符串是否存在重复的；
  如果长度比后面的字符串长，还需要判断当前字符串是否为前面的字符串的子串；
3.如果既不重复，也不是子串，则找到了最大特殊子串；

### 代码

```c
#inlcude <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_NUN  50
#define MAX_STRING_LEN 10

typedef struct {
    char input[MAX_STRING_LEN];
    short repFlag;
    int stringLen;
} InStr;

InStr g_in[MAX_STRING_NUN];

//判断字符串A是否为B的子串,是子串返回1;不是子串返回0;
int judge(InStr *a,InStr *b)
{
    int j;
    int cmpValue = 1;
    int i = 0;
    for(j=0;j<b->stringLen;j++){  
        if ((a->input[i] == b->input[j]) && ((a->stringLen - i) <= (b->stringLen-j))) {
            i++;    
        }
    }  
    if(i==a->stringLen){
        return 1;
    }
    return 0;
}

int compar(const void*a,const void*b)
{
    InStr *atemp = (InStr*)a;
    InStr *btemp = (InStr*)b;

    return btemp->stringLen - atemp->stringLen;
}
int findLUSlength(char ** strs, int strsSize){
    int i, j, k, n;
    int judgeValue, rslt;

    //初始化
    memset(&g_in[0], 0, MAX_STRING_NUN*sizeof(InStr));
    for (i=0; i<strsSize; i++) {
        g_in[i].stringLen = strlen(&strs[i][0]);
        memcpy(&g_in[i].input[0], &strs[i][0], g_in[i].stringLen);
    }
    
    //按长度从大到小排序
    qsort(&g_in[0], strsSize, sizeof(InStr), compar);

    //从最长的字符串开始找
    for (i=0; i<strsSize; i++) {    
        //printf("%d:%s ",i,&g_in[i].input);         
        if(g_in[i].repFlag == 1){
            continue;
        }
        judgeValue = 1;
        /* 由于前面的长度比后面的长，或者跟后面的子串一样长，跟后面的字符串比较，
            不重复，是最长特殊子串
            重复的，任何子串都不是特殊子串
        */
        for (k=i+1; k<strsSize; k++) {            
            //长度相同，判断是否有重复的字符串；长度大于后面的长度，则还需要跟前面的子串进行比较                 
            if(g_in[i].stringLen == g_in[k].stringLen) {          
                judgeValue &= strcmp(&g_in[i].input, &g_in[k].input);
                //重复需要去重
                if(judgeValue == 0) {                
                    g_in[i].repFlag = 1;
                    g_in[k].repFlag = 1; 
                    break;
                } 
            }              
        } 
        // 如果前面的字符串都没有找到结果(重复)；则后面的字符串需要跟前面的字符串比较          
        for (j=0; j<i; j++) {    
            //判断是否有重复的字符串
            rslt = judge(&g_in[i].input, &g_in[j].input);.stringLen);
            //是子串则标记重复
            if(rslt == 1) {                
                g_in[i].repFlag = 1;
                break;
            }             
        } 
        //如果当前字符串不是重复的，则为最大子串 
        if(g_in[i].repFlag != 1) {
            return g_in[i].stringLen;
        }              
    }

    return -1;
}
```