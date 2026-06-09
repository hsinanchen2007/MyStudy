### 解题思路
字母最多26个，因此我们用一个矩阵记录每个单词的字母出现次数

然后比较每一列 的单词次数是否>0，有>0 则说明 这是三个共同拥有的字母，放到结果集中即可。

思路很简单

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_LEN 100
#define ZIMU_LEN 26

char ** commonChars(char ** A, int ASize, int* returnSize){
    int words[MAX_LEN][ZIMU_LEN] = {0};
    char **result = (char **)malloc(MAX_LEN * sizeof(char *));
    
    char ** p = result;
    
    int num = 0;
    
    for (int i = 0; i < ASize; i++) {
        for (int j = 0; j < strlen(A[i]); j++) {
            words[i][A[i][j] - 'a']++;
        }
    }
    

    
    for (int i = 0; i < ZIMU_LEN; i++) {
        int min = MAX_LEN;
        for (int j = 0; j < ASize; j++) {
            if (words[j][i] < min) {
                min = words[j][i];
            }
        }
        
        if (min != 0) {
            for (int k = 0; k < min; k++) {
                result[num] = (char *)malloc(2 * sizeof(char));
                result[num][0] = i + 'a';
                result[num][1] = '\0';
                num++;
            }
        }
    }
    
    *returnSize = num;
    return result;
}
```