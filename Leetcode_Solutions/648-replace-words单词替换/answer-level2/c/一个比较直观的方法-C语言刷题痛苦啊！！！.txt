strtok分开，直接拼串，比较直观。  时间复杂度一般  空间复杂度凑合
显示详情
执行用时 :
164 ms
, 在所有 C 提交中击败了
17.09%
的用户
内存消耗 :
10.2 MB
, 在所有 C 提交中击败了
100.00%
的用户
```
#define MIN(a,b) (((a)<(b))?(a):(b))
#define WORDLANMAX 100

char * replaceWords(char ** dict, int dictSize, char * sentence){
    int sentenceLen = strlen(sentence);
    char *p = strtok(sentence," ");
    char *ans = (char*)malloc(sentenceLen*sizeof(char)*2);
    memset(ans,0,sentenceLen*sizeof(char)*2);
    int index = 0;
    
    while(p !=NULL){
        int min = INT_MAX;
        char buf[WORDLANMAX] ={0};
        for(int i = 0; i < dictSize; i++){
            if(strstr(p,dict[i]) == p){
                if(min > strlen(dict[i])){
                    memset(buf,0,WORDLANMAX);
                    snprintf(buf,WORDLANMAX,"%s",dict[i]);
                    min = MIN(min, strlen(dict[i]));
                }
            }
        }

        if(min != INT_MAX){
            index += sprintf(ans+index,"%s ", buf);
        }else{
            index += sprintf(ans+index,"%s ", p);
        }

        p = strtok(NULL," ");
    }
    ans[index-1] = 0;
    return ans;
}
```
