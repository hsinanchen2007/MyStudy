**解题思路**
     回溯算法+哈希表索引

**代码如下**
```
typedef struct hash{
    char  Num;
    int   Len;
    char  Str[5];
} HASH;
HASH HashMap[10] = {'0', 0, "", '1', 3, "!@#",
                '2', 3, "abc",  '3', 3, "def",  '4', 3, "ghi",
                '5', 3, "jkl",  '6', 3, "mno",  '7', 4, "pqrs",
                '8', 3, "tuv",  '9', 4, "wxyz",
};
int numofletterCombination(char* digits, int* letter){
    int N = 1;
    while(digits[*letter] != '\0'){
        if(digits[*letter] == '7' || digits[*letter] == '9')
            N *= 4;
        else N *= 3;
        (*letter)++;
    }
    return N;
}
void trackback(char* digits, int lettersSize, char** res, int index, char* path, int* pos, int* num){
    if(digits[index] == '\0'){
        path[lettersSize] = '\0';
        strcpy(res[(*num)++], path);
        return;
    }
    int len =  HashMap[digits[index]-'0'].Len;
    for(int i=0; i<len; i++){
        path[(*pos)++] = HashMap[digits[index]-'0'].Str[i];
        trackback(digits, lettersSize, res, index+1, path, pos, num);
        (*pos)--;
    }
}

char** letterCombinations(char* digits, int* returnSize){ 
    if(digits[0] == '\0'){
        *returnSize = 0;
        return NULL;
    }
    int lettersSize= 0;
    int N = numofletterCombination(digits, &lettersSize);
    *returnSize = N;
    char** res = (char**)malloc(N*sizeof(char*));
    for(int i=0;i<N;i++){
        res[i] = (char*)malloc((lettersSize+1)*sizeof(char));
        res[i][lettersSize] = '\0';
    }
    char* path = (char*)malloc((lettersSize+1)*sizeof(char));
    int pos = 0, num = 0;
    trackback(digits, lettersSize, res, 0, path, &pos, &num);
    free(path);
    return res;
}
```
![image.png](https://pic.leetcode-cn.com/0ad9e83835bca2f9ecd90e62cdbbc10c62f8350827494a46cd1597f5184fe211-image.png)
