### 解题思路
![Snipaste_2020-03-18_15-09-04.png](https://pic.leetcode-cn.com/dd6d0bc941dbd158273d1b05cf7380ebf5446ffca203fb48d9f6175425d7fadb-Snipaste_2020-03-18_15-09-04.png)


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findOcurrences(char * text, char * first, char * second, int* returnSize){
    char ** buffer=(char **)malloc(sizeof(char *)*100);
    *( buffer+0)=(char *)malloc(sizeof(char)*50);
    int len=0,index=0;
    int i;
    for(i=0;*(text+i)!='\0';i++){
        if(*(text+i)!=' '){
            *(*(buffer+len)+index++)=*(text+i);
            continue;
        }
        *(*(buffer+len)+index)='\0';
        index=0;
        len++;
        *(buffer+len)=(char *)malloc(sizeof(char)*50);
    }
    *(*(buffer+len)+index)='\0';
    len++;
    index=0;
    if(len<3) return NULL;
    for(i=0;i<len-2;i++){
        if(strcmp(*(buffer+i),first)==0&&strcmp(*(buffer+i+1),second)==0){
            strcpy(*(buffer+index),*(buffer+i+2));
            index++;
        }

    }
    *returnSize=index;
    return buffer;
}
```