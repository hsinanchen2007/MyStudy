### 题目
给定两个二进制字符串，返回他们的和（用二进制表示）。
输入为非空字符串且只包含数字 1 和 0。

示例 1:
输入: a = "11", b = "1"
输出: "100"

示例 2:
输入: a = "1010", b = "1011"
输出: "10101"

### 解题思路
第一种方法，从输入的两个字符串的最后一个字符开始，提取字符转换为数字，相加后判断进位，并转换为字符，保存到输出字符串中；输出字符串需要提前申请空间，申请空间的长度，可以设置为两个输入字符串的较长的长度加2；多出来的两个字符用来保存字符串结束符和最后进位的位；生成的输出字符串，是倒序的数据，需要进行字符串反转操作，生成最终需要的正序字符串；
第二种方法，分别将两个输入字符串，通过strtol()函数，将二进制数字字符串转换为数据，两个输入数据相加的到的数值转换为二进制字符串，作为输出结果；整数值转换为字符串时，没有库函数可以使用，需要自己封装；字符串的长度，可以通过将数值逐次右移一位判断是否为0，并进行计数的方法来获得；申请空间时要预留保存'\0'的空间；
第一种方法，适用于任意长度的输入字符串；
第二种方法，由于使用了strtol()函数，这就限制了输入字符串的长度，不能超过32位；此种方法在本题的验证中是不会通过的；

### 代码

```c
#if 1

// Reverse the string
int string_reverse(char *str, int len)
{
    char tmp = 0;
    int pos = 0;

    if ((!str) || (!len)) {
        return -1;
    }

    len = len - 1;
    while (pos < (len >> 1)) {
        tmp = *(str + pos);
        *(str + pos) = *(str + (len - pos) - 1);
        *(str + (len - pos) - 1) = tmp;
        pos++;
    }

    return 0;
}

char * addBinary(char * a, char * b)
{
    char *pOut = NULL;
    char *pa = NULL;
    char *pb = NULL;

    int pos = 0;
    int alen = 0;
    int blen = 0;
    int len = 0;
    int cnt = 0;
    char plus = 0;
    char flag = 0;
    char aChar = 0;
    char bChar = 0;
    char tmp = 0;
    int ret = -1;

    if ((!a) || (!b)) {
        printf("param is null!\n");
        return NULL;
    }
    pa = a;
    pb = b;

    alen = strlen(a);
    blen = strlen(b);
    len = alen > blen ? alen : blen;

    pOut = (char *)malloc(sizeof(char) * (len + 2));
    if (!pOut) {
        printf("malloc failed!\n");
        return NULL;
    }

    while ((alen > 0) || (blen > 0) || (flag > 0)) {
        if (alen > 0) {
            aChar = *(pa + alen - 1) - '0';
        } else {
            aChar = 0;
        }
        if (blen > 0) {
            bChar = *(pb + blen - 1) - '0';
        } else {
            bChar = 0;
        }

        plus = aChar + bChar + flag;
        flag = plus / 2;
        plus = plus % 2;

        *(pOut + pos) = plus + '0';
        pos++;
        if (alen > 0) {
            alen--;
        }
        if (blen > 0) {
            blen--;
        }
    }
    *(pOut+pos) = '\0';

    ret = string_reverse(pOut, strlen(pOut) + 1);
    if (ret) {
        return NULL;
    }

    return pOut;
}

#else

// 第二种方法，适用于数据长度在32位以内的整数加法

int get_data_bit(int data)
{
    int i = 0;

    if (!data)
        return 1;

    while (data) {
        data = data >> 1;
        i++;
    }

    return i;
}

int data_to_string(int data, char *str, int len)
{
    int pos = len - 1;

    if (!data) {
        *str = '0';
    }
    *(str + len) = '\0';    
    while ((data) && (pos >= 0)) {
        *(str + pos) = data % 2 + '0';
        data = data / 2;
        pos--;
    }

    return 0;
}

char * addBinary(char * a, char * b)
{
    unsigned long aData = 0;
    unsigned long bData = 0;
    unsigned long total = 0;
    int len = 0;
    int ret = -1;
    char *pOut = NULL;

    if ((!a) || (!b)) {
        printf("param is null!\n");
        return NULL;
    }

    aData = strtol(a, NULL, 2);
    bData = strtol(b, NULL, 2);
    total = aData + bData;

    len = get_data_bit(total);

    pOut = (char *)malloc(sizeof(char) * (len + 1));
    if (!pOut) {
        printf("malloc failed!\n");
        return NULL;
    }

    ret = data_to_string(total, pOut, len);
    if (ret) {
        printf("data_to_string error, ret: %d\n", ret);
        return NULL;
    }

    return pOut;
}

#endif
```