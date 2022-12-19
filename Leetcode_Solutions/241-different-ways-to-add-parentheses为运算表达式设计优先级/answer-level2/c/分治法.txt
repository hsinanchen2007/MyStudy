1. 根据运算符划分，递归调用
2. 只有一个数字的时候，返回atoi，否则11只会返回1，因为识别的是字符
3. 返回值是一个数组，需要根据结果重新分配，使用realloc
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diffWaysToCompute(char * input, int* returnSize){
    if(input == NULL){
        *returnSize = 0;
        return NULL;
    }
    int len = strlen(input);
    int index = 0;
    int calflag = 0;
    int* returnArray = (int *)malloc(sizeof(int) * 1);;
    int returnCnt = 0;
    char * leftStr = (char *)malloc(sizeof(char) * len);
    char * rightStr = (char *)malloc(sizeof(char) * len);
    while(index < len){
        if(input[index] >= '0' && input[index] <= '9'){
            index ++;
            continue;
        }
        calflag = 1;
        memcpy(leftStr,input,index);
        leftStr[index] = '\0';
        memcpy(rightStr,input + index + 1,len - index - 1);
        rightStr[len - index - 1] = '\0';
        int leftReturnSize = 0;
        int rightReturnSize = 0;
        int* leftRet = diffWaysToCompute(leftStr, &leftReturnSize);
        int* rightRet = diffWaysToCompute(rightStr, &rightReturnSize);
        returnArray = (int*)realloc(returnArray,sizeof(int) * (returnCnt + leftReturnSize * rightReturnSize));
        for(int i = 0; i < leftReturnSize; i++){
            for(int j = 0; j < rightReturnSize; j++){
                switch(input[index]){
                    case '+':
                        returnArray[returnCnt++] = leftRet[i] + rightRet[j];
                        break;
                    case '-':
                        returnArray[returnCnt++] = leftRet[i] - rightRet[j];
                        break;
                    case '*':
                        returnArray[returnCnt++] = leftRet[i] * rightRet[j];
                        break;
                    default:
                        break;
                } 
            }
        }
        index ++;
    }
    if(calflag == 0){
        *returnSize = 1;
        returnArray[0] = atoi(input);
    }else{
        *returnSize = returnCnt;
    }
    return returnArray;
}
```
