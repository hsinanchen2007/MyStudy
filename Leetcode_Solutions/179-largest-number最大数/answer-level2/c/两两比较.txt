### 解题思路
此处撰写解题思路

### 代码

```c

int comp(const void *a, const void *b)
{
    char tmp[100] = { 0 };
    char tmp1[100] = { 0 };
    long long atmp;
    long long btmp;

    strcpy(tmp, *(char **)a);//strcpy字符串复制
    strcat(tmp, *(char **)b);
    btmp = atoi(tmp);//atoi转换成int型

    strcpy(tmp1, *(char **)b);
    strcat(tmp1, *(char **)a);
    atmp = atoi(tmp1);
    
    return atmp - btmp;
}

char * largestNumber(int* nums, int numsSize){
    int count = 0;
    int i;
    char **strNum;
    char *res;
    //判断数组中0的个数，若全为0，则返回0即可。
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            count++;
        }
    }
    
    if (count == numsSize) {
        return "0";
    }

    strNum = (char **)malloc(numsSize * sizeof(char *));//二维数组
    for (i = 0; i < numsSize; i++) {
       strNum[i] = (char *)malloc(100 * sizeof(char));
       memset(strNum[i], 0, 100 * sizeof(char));//memset对内存进行初始化
    }

    for (i = 0; i < numsSize; i++) {
        sprintf(strNum[i], "%d", nums[i]);//sprintf将文本写入到字符串中
    }

    qsort(strNum, numsSize, sizeof(strNum[0]), comp);//qsort对数组进行排序
    res = (char *)malloc(1000 * sizeof(char));
    memset(res, 0, 1000 * sizeof(char));
    for (i = 0; i < numsSize; i++) {
        strcat(res, strNum[i]);//strcat追加字符串
    }

    return res;
}

```