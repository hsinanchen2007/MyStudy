```
static char* keys[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
char** res;
int resLen;

//digits:数字字符串
//index:在数字字符串第几个
//item:会加进答案数组的字符串
void backtrack(char* digits, int index, char* item){
    if(index == strlen(digits)){
        strcpy(res[resLen], item);
        puts(item);
        resLen++;
        return ;
    }
    char c = digits[index];
    char* letters = keys[c-'0'];
    for(int i = 0; i < strlen(letters); i++){
        item[strlen(item)] = letters[i];
        //递归到下一个数字上
        backtrack(digits, index+1, item);
        item[strlen(item)-1] = '\0';
    }
}

char** letterCombinations(char * digits, int* returnSize){
    res = (char**)malloc(1000*sizeof(char*));
    int digitsLen = strlen(digits);
    for(int i = 0; i < 1000; i++){
        res[i] = (char*)malloc((digitsLen+1)*sizeof(char));
        memset(res[i], '\0', (digitsLen+1)*sizeof(char));
    }
    resLen = 0;
    if(strcmp(digits,"") == 0){
        *returnSize = 0;
        res[0] = NULL;
        return res;
    }
    char* item = (char*)malloc((digitsLen+1)*sizeof(char));
    memset(item, '\0', (digitsLen+1)*sizeof(char));
    backtrack(digits, 0, item);
    *returnSize = resLen;
    return res;
}
```
