### 解题思路
1. 去掉多余空格；
2. 整体翻转；
3. 单词逐个翻转

### 代码

```c
void ReverseString(char* s, int start, int end)
{
    if (s == NULL ) {
        return;
    }

    while (start < end) {
        char c = s[start];
        s[start] = s[end];
        s[end] = c;
        start++;
        end--;
    }
}

char * reverseWords(char * s)
{
    if (s == NULL || strlen(s) == 0) {
        return s;
    }

    // 1. 去掉多余空格 申请空间 赋值到新数组中
    int len = strlen(s);
    char *newStr = (char *)malloc((len + 1) * sizeof(char));
    if (newStr != NULL) {
        memset(newStr, 0, len * sizeof(char));
    }

    int index = 0;
    char c = s[0];
    int startIndex = 0;
    for (int i = 0; i < len; i++) {
        c = s[i];
        if (c != ' ') {
            startIndex = i; // 第一个非空格字符index
            break;
        }   
    }

    for (int i = startIndex; i < len; i++) {
        c = s[i];
        if (c == ' ') {
            if (i == (len -1)) {
                break;
            }
            if (s[i + 1] == ' ') {
                continue;
            }
            if (s[i + 1] != ' ') {
                newStr[index] = c;
                index++;
            }
        } else {
            newStr[index] = c;
            index++;
        }
    }
    newStr[index] = '\0';

    // 2. newStr 整体翻转
    int newStrLen = strlen(newStr);
    ReverseString(newStr, 0, newStrLen - 1);

    // 3. 逐个翻转单词
    bool isNewWord = true;
    int start = 0;
    int end = 0;
    for (int i = 0; i < newStrLen; i++) {        
        if (newStr[i] != ' ' && isNewWord) {
            start = i;
            isNewWord = false;
        }

        if (newStr[i] == ' ') {
            end = i - 1;
            ReverseString(newStr, start, end);
            isNewWord = true;
        }

        //the last word
        if (!isNewWord && (i == newStrLen - 1)) {
            end = i;
            ReverseString(newStr, start, end);
        }
    }

    // 4. 返回结果
    return newStr;
}
```