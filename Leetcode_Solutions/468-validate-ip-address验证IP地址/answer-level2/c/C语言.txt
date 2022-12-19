### 解题思路
没有用什么特殊的方法，写的也挺难看，就是切割字符串校验，但是速度和内存双百

### 代码

```c
bool isRightIPv4Str(char *str)
{
    char *p = str;
    // 长度为0不行，开头不能为0
    if (strlen(str) == 0 || (*p == '0' && strlen(str) > 1)) {
        return false;
    }
    while (*p) {
        // 不能是非数字
        if (!isdigit(*p)) {
            return false;
        }
        p++;
    }
    int i = atoi(str);
    // 数字不能大于255
    if (i > 255) {
        return false;
    }
    return true;
}
char *validIPv4(char *IP)
{
    char *p1 = IP;
    char *p2 = IP;
    int i = 0;
    int j;
    int count;
    char *ret = "Neither";
    // 统计 . 数量
    while (*p2){
        if (*p2 == '.') i++;
        p2++;
    }
    // 如果不是3个就不行
    if (i != 3) {
        return ret;
    }
    p2 = IP;
    // 以 . 分段处理字符串
    for (i = 0; i < 3; i++) {
        count = 0;
        while (*p2 != '.') {
            p2++;
        }
        // 分段字符串
        char temp[4] = { 0 };
        for (j = 0; j < 4; j++) {
            if (*p1 == *p2) {
                temp[j] = '\0';
                break;
            }
            temp[j] = *p1;
            p1++;
            // 记录分段字符串长度，超过3返回
            count++;
            if (count > 3) {
                return ret; 
            }
        }
        // p1和p2应该重合，此时判断分段字符串是否合法
        if ((*p1 != *p2) || !isRightIPv4Str(temp)) {
            return ret;
        }
        p1++;
    }
    // 最后一个字符串由于没有 . 分割，所以上面的循环中没有判断，需要再判断下
    if (!isRightIPv4Str(p1)) {
        return ret;
    }
    ret = "IPv4";
    return ret;
}
bool isRightIPv6Str(char *str)
{
    char *p = str;
    // 字符串长度为0或大于4不行
    if (strlen(str) == 0 || strlen(str) > 4) {
        return false;
    }
    while (*p) {
        // 出现非字母数字不行
        if (!isalnum(*p)) {
            return false;
        }
        if (isalpha(*p)) {
            // 出现a-f之外的大小写字母不行
            if (*p > 'f' && *p <= 'z' || *p > 'F' && *p <= 'Z') {
                return false;
            }
        }
        p++;
    }

    return true;
}
char *validIPv6(char *IP)
{
    char *p1 = IP;
    char *p2 = IP;
    int i = 0;
    int j;
    int count;
    char *ret = "Neither";
    // 统计 : 数量
    while (*p2){
        if (*p2 == ':') i++;
        p2++;
    }
    // 如果不是7个就不行
    if (i != 7) {
        return ret;
    }
    p2 = IP;
    // 以 : 分段处理字符串
    for (i = 0; i < 7; i++) {
        count = 0;
        while (*p2 != ':') {
            p2++;
        }
        // 分段字符串
        char temp[5] = { 0 };
        for (j = 0; j < 5; j++) {
            printf("%d %c %c\n", __LINE__, *p1, *p2);
            if (*p1 == *p2) {
                temp[j] = '\0';
                break;
            }
            temp[j] = *p1;
            p1++;
            // 记录分段字符串长度，超过4返回
            count++;
            if (count > 4) {
                return ret; 
            }
        }
        // p1和p2应该重合，此时判断分段字符串是否合法
        if ((*p1 != *p2) || !isRightIPv6Str(temp)) {
            return ret;
        }
        p1++;
    }
    // 最后一个字符串由于没有 ：分割，所以上面的循环中没有判断，需要再判断下
    if (!isRightIPv6Str(p1)) {
        return ret;
    }
    ret = "IPv6";
    return ret;
}
char * validIPAddress(char * IP){
    char *p = IP;
    char *ret = "Neither";
    // 找到第一个不是数字字母的字符
    while (isalnum(*p)) {
        p++;
    }
    // 如果是 . 或 : 进入对应判断逻辑，否则直接返回
    if (*p == '.') {
        ret = validIPv4(IP);
    } else if (*p == ':') {
        ret = validIPv6(IP);
    }

    return ret;
}
```