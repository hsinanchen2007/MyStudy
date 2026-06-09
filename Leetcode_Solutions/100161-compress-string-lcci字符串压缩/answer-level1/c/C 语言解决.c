### 解题思路
1. 先压缩字符串
2. 再比较字符串

当统计到字符个数大于9时，需要注意，新增一个函数解决这个问题。

### 代码

```c

#define CHAR_ARRAY_SIZE 5

// 转换数字成字符串，并添加到结果数组中
int AddToStr(int count, char* resultStr, int index)
{
    if (resultStr == NULL) {
        return 0;
    }

    // 数字到字符的转换
    char str[CHAR_ARRAY_SIZE] = {0};
    sprintf(str, "%d", count); // sprintf最常见的应用之一莫过于把整数打印到字符串中
    int strLen = strlen(str);

    for (int j = 0; j < strLen; j++) {
        index++;
        resultStr[index] = str[j];
    }

    return strLen;
}

char* compressString(char* S)
{
    if (S == NULL || strlen(S) == 0) {
        return S;
    }

    int len = strlen(S);
    int count = 1;
    char temp = S[0];
    int index = 0;

    char *newStr = (char *)malloc(len * 2 * sizeof(char));
    memset(newStr, 0, len * 2 * sizeof(char));
    newStr[index] = temp;

    // 压缩字符串
    for (int i = 1; i < len; i++) {
        if (temp == S[i]) {
            count++;
        } else {
            // 转换数字成字符串，并添加到结果数组中
            index += AddToStr(count, newStr, index);

            index++;
            newStr[index] = S[i];
            temp = S[i];
            count = 1;
        }
    }

    index += AddToStr(count, newStr, index);

    // 比较字符串长度    
    if (index + 1 >= len) {
        return S;
    } else {
        newStr[++index] = '\0';
        return newStr;
    }
}
```