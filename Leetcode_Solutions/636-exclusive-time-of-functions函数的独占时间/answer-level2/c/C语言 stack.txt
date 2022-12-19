思路：
遇到start入栈，遇见end，如果出栈后，栈不为空，需要将栈里所有的函数起始时间增加出栈函数所占时间
![QQ截图20190723183049.png](https://pic.leetcode-cn.com/e8bedbc8a4c2864897ce22aaa0134f8d17672b5ed59eb69c0dcd273bf4b08c04-QQ%E6%88%AA%E5%9B%BE20190723183049.png)



#define <string.h>

int getFunId(char *str){
    return atoi(str);
}

int getFunTime(char *str){
    char *ptr = NULL;    
    ptr = strrchr(str, ':');
    return atoi(ptr+1);
}

struct funStartTime{
    int funId;
    int startTime;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* exclusiveTime(int n, char ** logs, int logsSize, int* returnSize){

    if(n <= 0 || logs == NULL || logsSize <= 0){
        *returnSize = 0;
        return NULL;
    }
    
    struct funStartTime *stack = NULL; 
    int i, j;
    int index = -1;
    int *buff = NULL;
    
    stack = (struct funStartTime*)malloc(sizeof(struct funStartTime)*logsSize);
    buff = (int *)malloc(sizeof(int)*(n));
    if(buff == NULL){
        *returnSize = 0;
        return NULL;        
    }
    
    memset(buff, 0, sizeof(int)*(n));
    
    for(i = 0; i < logsSize; i++){
        if(strstr(logs[i], "start") != NULL){
            index++;
            stack[index].funId = getFunId(logs[i]);
            stack[index].startTime = getFunTime(logs[i]);
        }
        else if(strstr(logs[i], "end") != NULL){
            buff[stack[index].funId] += getFunTime(logs[i]) - stack[index].startTime + 1;
            //printf("%d %d\n", stack[index].funId, buff[stack[index].funId]);
            index--;
            if(index != -1){
                j = index;
                while(j >= 0){
                    stack[j--].startTime += getFunTime(logs[i]) - stack[index+1].startTime + 1;
                }
            }
            
        }
    }
    free(stack);
    *returnSize = n;
    return buff;     
}
                                                
                                                
                                                
                                                
                                                

