### 解题思路
主要思路是遍历输入数组，判断当前字符应该在输出结果的哪一行。为了节约空间，需要算出每一行的起始偏移量。相对于其他c的方法，当输入字符串长度和行数都比较大的时候，时间复杂度会小一些。

### 代码

```c
char* convert(char* s, int numRows)
{
    char* result = NULL;
    int len = 0;
    int start = 0;
    int groupSize = 0;
    int row = 0;
    int rowIndex[numRows];
    int where = 0;
    int i;

    if (!s || !numRows) {
        goto out;
    }

    len = strlen(s);

    result = (char*)malloc(len + 1);
    if (!result) {
        goto out;
    }

    groupSize = numRows > 1 ? (numRows * 2 - 2) : 1;
    for (i = 0; i < numRows; ++i) {
        rowIndex[i] = start;
        if (!i || i == numRows - 1) {
            start += len / groupSize + ((len % groupSize) > i);
        } else {
            start += len / groupSize * 2 + ((len % groupSize) > i) + ((len % groupSize) >= numRows * 2 - i - 1);
        }
    }

    for (i = 0; i < len; ++i) {
        where = i % groupSize;
        if (where < numRows) {
            row = where;
        } else {
            row = groupSize - where;
        }
        result[rowIndex[row]++] = s[i];
    }
    result[len] = '\0';

out:
    return result;
}
```