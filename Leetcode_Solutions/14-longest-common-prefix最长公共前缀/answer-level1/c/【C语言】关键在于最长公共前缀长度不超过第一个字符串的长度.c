### 解题思路
// 解法1：
// 每个字符串可能不等长，但没关系，最长公共前缀的长度一定不超过数组中最短字符串的长度
// 以第一行为对比标准,curr = strs[0][j], j = 0, 1, 2,……,columnLen, columnLen = str(strs[0])
// 行列指针遍历字符串数组，最大遍历范围为 strsSize * columnLen
// 从第一列开始，先固定某一列，遍历所有行(i++)，如果遇到不一样的，说明当前字符并不是公有的，结束遍历，返回common;
// 如果遍历完所有行以后(i = strsSize)，没有遇到不一样的，说明当前字符是公有的，添加到common中，然后移动到下一列(j++)
// 如果没有下一列(j == columnLen)，返回common
// strlen()函数在<string.h>
// 时间复杂度:O(n)，只需要遍历一遍二维数组
// 空间复杂度:O(n)

### 代码

```c
#include <string.h>
#define N 100000 
char * longestCommonPrefix(char ** strs, int strsSize)
{
    // 处理空字符串
    if (strs == NULL || strsSize < 1) {
        return "";
    }
    // 只有一个字符串，直接返回
    if (strsSize == 1) {
        return strs[0];
    }

    char* common = (char*)malloc(N * sizeof(char));
    memset(common, 0, N * sizeof(char));

    int i;  // 行指针，遍历每个字符串
    int j; // 列指针，遍历单个字符串的每个字符
    int k = 0;  // common指针
    int columnLen = strlen(strs[0]);
    
    for (j = 0; j < columnLen; j++) {
        for (i = 1; i < strsSize; i++) {
            if (strs[i][j] != strs[0][j]) {
                return common;
            }
        }
        // 将公有字符加到common中
        common[k++] = strs[0][j];
    }
    
    common[k] = '\0';

    return common;
}
```


/ 解法2
// 不需要申请新的数组，直接把公共前缀放在第一个字符串中，返回时，先将当前位置赋值为'\0'，再返回
// 否则不需要改动

```
#include <string.h>
char * longestCommonPrefix(char ** strs, int strsSize)
{
    // 处理空字符串
    if (strs == NULL || strsSize < 1) {
        return "";
    }
    // 只有一个字符串，直接返回
    if (strsSize == 1) {
        return strs[0];
    }

    int i;  // 行指针，遍历每个字符串
    int j; // 列指针，遍历单个字符串的每个字符
    
    for (j = 0; j < strlen(strs[0]); j++) {
        for (i = 1; i < strsSize; i++) {
            if (strs[i][j] != strs[0][j]) {
                strs[0][j] = '\0';
                return strs[0];
            }
        }
    }

    return strs[0];
}
```
