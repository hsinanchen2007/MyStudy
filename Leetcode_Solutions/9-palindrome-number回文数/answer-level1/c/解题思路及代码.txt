### 解题思路
此处撰写解题思路
1、输入限制整数，范围在[-2147483648,2147483647],字符长度不超过11，加上'\0'，不超过12
2、把整数转成字符串，获取字符串长度
3、双指针法，停止条件，前向指针大于后向指针j
4、特殊用例：1，-1,121,-121,1221，-1221，-2147483648
### 代码

```c
#define MAX_INT_LEN  12

bool isPalindrome(int x) {
    char str[MAX_INT_LEN];
    int i, j;
    int flag;

    sprintf(str, "%d", x);

    if (strlen(str) < 2) {
        return 1;
    }

    i = 0;
    j = strlen(str) - 1;
    flag = 0;
    while (i<j) {
        if (str[i] == str[j]) {
            i++;
            j--;
            flag = 1;
        }
        else {
            flag = 0;
            break;
        }
    }

    return flag;
}
```