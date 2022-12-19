### 解题思路
递归解题，思路清晰，方便高效
基于每个数字进行递归，深度优先遍历

![image.png](https://pic.leetcode-cn.com/3d36fd0224b703d143840d0466c6772fb3068ce32a16e8b365f733564985989c-image.png)



### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 // 14:35
 // 注意：数字可能重复
#include <math.h>

char stringLayer[][5] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
int numsPerLayer[] = {3,3,3,3,3,4,3,4};

void GetOutStrings(char **outString, int *returnSize, int *numsArray, int numsCount, int curLayer, char *tmpString)
{
    int i;

    //printf("curLayer = %d;*returnSize = %d;numsCount = %d;numsArray[curLayer] = %d;\n", curLayer, *returnSize, numsCount, numsArray[curLayer]);
    //printf("numsPerLayer[numsArray[curLayer]] = %d;\n", numsPerLayer[numsArray[curLayer]]);
    for (i = 0; i < numsPerLayer[numsArray[curLayer]]; ++i) {
        tmpString[curLayer] = stringLayer[numsArray[curLayer]][i];

        if(curLayer < (numsCount - 1)) {
            GetOutStrings(outString, returnSize, numsArray, numsCount, curLayer + 1, tmpString);
        } else {
            // 字符串存放
            tmpString[numsCount] = '\0';
            //printf("tmpString1: %s;\n", tmpString);
            //printf("outString: %p;\n", outString);
            //printf("*returnSize: %d;\n", *returnSize);
            //printf("outString + *returnSize: %p;\n", outString + *returnSize);
            *(outString + *returnSize) = (char *)malloc(numsCount + 1);
            //printf("tmpString2: %s;\n", tmpString);
            memcpy(*(outString + *returnSize), tmpString, numsCount + 1);
            //printf("tmpString3: %s;\n", tmpString);
            (*returnSize)++;
            //printf("tmpString: %s;\n", tmpString);
        }
    }

    return;
}

char ** letterCombinations(char * digits, int* returnSize){
    int numsCount;
    int *numsArray;
    int i;
    char **outString;
    int curLayer = 0;
    char *tmpString;

    *returnSize = 0;
    numsCount = strlen(digits);
    if(numsCount == 0) {
        return NULL;
    }
    
    numsArray = (int *)malloc(numsCount * sizeof(int));
    for (i = 0; i < numsCount; ++i) {
        numsArray[i] = digits[i] - '0' - 2; // 转换为0~7
        //printf("numsArray[%d] = %d;\n", i, numsArray[i]);
    }

    // 需要吸收一下别人的经验，怎么高效管理这种二维字符串
    //printf("numsCount = %d; pow(4, numsCount) = %d;\n", numsCount, pow(4, numsCount));
    outString = (char **)malloc(pow(4, numsCount) * sizeof(char *));
    //outString = (char **)malloc(16 * sizeof(char *));

    tmpString = (char *)malloc(numsCount + 1);

    GetOutStrings(outString, returnSize, numsArray, numsCount, curLayer, tmpString);

    free(tmpString);

    //printf("END");
    return outString;
}
```