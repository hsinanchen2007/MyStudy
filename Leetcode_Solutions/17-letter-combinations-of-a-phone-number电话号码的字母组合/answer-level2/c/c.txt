### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize){
    
    if (*digits == 0)
    {
        *returnSize = 0;
        return NULL;
    }

    char *table[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int l = strlen(digits);
    char **answer = (char**)malloc(sizeof(char*)*pow(4,l));
    for(int i = 0; i < pow(4,l); i++)
    {
        answer[i] = (char*)malloc(sizeof(char)*(l+1));
    }

    int sum = 1;
    for(int i = 0; i < l; i++)
    {
        int idx = (int)(digits[i]-'0')-2;
        if (idx < 0)
        {
            *returnSize = 0;
            return NULL;
        }
        sum = sum * strlen(table[idx]);
    }
    *returnSize = sum;

    int c = 0;
    while(c < sum)
    {
        int tmp = c;
        for(int i = 0; i < l; i++)
        {
            int idx = (int)(digits[i]-'0')-2;
            int len = strlen(table[idx]);
            answer[c][i] = table[idx][tmp%len];
            tmp = tmp/len;
        }
        answer[c][l] = 0;
        c++;
    }
    
    return answer;
}
```