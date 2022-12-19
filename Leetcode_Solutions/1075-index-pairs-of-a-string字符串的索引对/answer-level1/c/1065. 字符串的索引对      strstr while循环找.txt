### 解题思路
给出 字符串 text 和 字符串列表 words, 返回所有的索引对 [i, j] 使得在索引对范围内的子字符串 text[i]...text[j]（包括 i 和 j）属于字符串列表 words。

 

示例 1:

输入: text = "thestoryofleetcodeandme", words = ["story","fleet","leetcode"]
输出: [[3,7],[9,13],[10,17]]


### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b){
    int* aa = (int*)a;
    int* bb = (int*)b;

    if(aa[0] != bb[0])
        return aa[0] - bb[0];
    else
        return aa[1] - bb[1];
}

int** indexPairs(char * text, char ** words, int wordsSize, int* returnSize, int** returnColumnSizes){
    int i, k = 0, len, res[1000][2], **result;
    char *temp;

    for (i = 0; i < wordsSize; i++) {
        temp = strstr(text, words[i]);
        len = strlen(words[i]);
        while (temp) {
            res[k][0] = temp - text;
            res[k][1] = res[k][0] + len - 1;
            k++;
            temp = strstr(temp + 1, words[i]);
        }
    }

    qsort(res, k, 2*sizeof(int), cmp);

    result = malloc(k * sizeof(char *));
    *returnColumnSizes = malloc(k * sizeof(int));
    for (i = 0; i < k; i++) {
        result[i] = malloc(2*sizeof(int));
        result[i][0] = res[i][0];
        result[i][1] = res[i][1];
        (*returnColumnSizes)[i] = 2;
    }

    *returnSize = k; 
    return result;
}
```