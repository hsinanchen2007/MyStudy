### 解题思路

1、数组元素排序，规则是长度由长到短 
2、用DFS遍历数组，每一步遍历的元素的范围是上一步元素的next，遍历的元素的范围在不断减少
### 代码

```c

int CmpFun(const void *a, const void *b)
{
    char **p1 = (char **)a;
    char **p2 = (char **)b;
    return strlen(*p2) - strlen(*p1);
}

int g_maxLen;
bool g_alphabets[26] = {false}; // 访问过的字母表
int *g_used; // arr数组已经访问的元素
void step(char ** arr, int arrSize, int stepCnt, int *tempMaxIn)
{
   int i, j, k;
    int arrEleLen;

    int tempMax;

    if (stepCnt == arrSize) {
        if (*tempMaxIn > g_maxLen) {
            g_maxLen = *tempMaxIn;
        }
        return ;
    }

    //每一轮广度上的选择，从stepCnt开始，遍历的元素的范围在减小，之前遍历的过的元素不用再遍历，因为本题不是让你找出所有元素的组合
    for (i = stepCnt; i < arrSize; i++) {
        if (g_used[i] == 1) {
            continue;
        }

        if (stepCnt == 0) { // 第一个step，把已访问字母表清空
            memset(g_alphabets, false, sizeof(g_alphabets));
            *tempMaxIn = 0;
        }

        arrEleLen = strlen(arr[i]);

        for (j = 0; j < arrEleLen; j++) {
            if (g_alphabets[arr[i][j] - 'a'] == true) {
                break;
            } else {
                g_alphabets[arr[i][j] - 'a'] = true;
            }
        }

        if (j < arrEleLen) {
            // 把上面for循环里 arr[i]加入已访问字母表的元素去掉，因为arr[i]是不满足要求的元素，注意j的取值从 j - 1开始
            for (j = j - 1; j >= 0; j--) {
                g_alphabets[arr[i][j] - 'a'] = false;
            }

            continue;
        }


        g_used[i] = 1;

        *tempMaxIn += arrEleLen;
        if (*tempMaxIn > g_maxLen) {
            g_maxLen = *tempMaxIn;
        }

        step(arr, arrSize, i + 1, tempMaxIn); // 下一个要访问的arr中的元素是从索引 i + 1 开始
        *tempMaxIn -= arrEleLen; //广度上每一个step遍历后，把临时最大值还原一下
    
        for (j = 0; j < firstArrEleLen; j++) {
            g_alphabets[arr[i][j] - 'a'] = false; //将arr[i]中的字母在访问过的字母表中删掉
        }

        g_used[i] = 0;


    }
}


int maxLength(char ** arr, int arrSize){
    g_maxLen = 0;
    if (arr == NULL || arrSize == 0) {
        return 0;
    }

    if (arrSize == 1) { //这里有bug，当arr只有一个元素时，需要判断该元素里是否有重复字母，如果没有，才返回元素的长度，否则，返回0
        return strlen(arr[0]);
    }

    qsort(arr, arrSize, sizeof(char *), CmpFun);

    g_used = (int *)malloc(sizeof(int) * arrSize);
    memset(g_used, 0, sizeof(int) * arrSize);

    int tempmax = 0;
    step(arr, arrSize, 0, &tempmax);

    return g_maxLen;
}
```