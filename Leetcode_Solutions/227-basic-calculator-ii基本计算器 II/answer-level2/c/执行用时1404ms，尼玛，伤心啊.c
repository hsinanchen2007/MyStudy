

### 解题思路
此处撰写解题思路

### 代码

```c
int GetNum(char *s, int *i, int len)
{
    int index = *i;
    while ((s[index] < '0') || (s[index] > '9')) {
        index++;
    }

    int temp = s[index++] - '0';
    while ((index < len) && ((s[index] >= '0') && (s[index] <= '9'))) {
        temp *= 10;
        temp += (s[index] - '0');
        index++;
    }

    *i = index - 1;
    return temp;
}
int calculate(char *s)
{
    int i, rlt, temp, index, len, symbol;
    int *data;
    char *myS;

    if (strlen(s) == 0) {
        return 0;
    }
    if (strlen(s) == 1) {
        return (*s - '0');
    }

    len = strlen(s);
    data = (int *)calloc(len, sizeof(int));
    len += 2;
    myS = (char *)malloc(len);
    strncpy(myS, s, strlen(s));
    myS[len - 2] = '+';
    myS[len - 1] = '\0';
    //DebugString(myS, len);

    index = 0;
    symbol = 1;
    for (i = 0; i < strlen(myS); i++) {
        switch (myS[i]) {
            case '+':  // 加号，暂存数据入队列
                data[index++] = temp;
                symbol = 1;
                break;
            case '-':  // 减号，暂存数据入队列
                data[index++] = temp;
                symbol = -1;
                break;
            case '*':  // 乘号，找出乘号前完整数字，计算出乘积，暂存
                temp *= GetNum(myS, &i, len);
                break;
            case '/':  // 除号，找出除号前完整数字，计算出商，暂存
                temp /= GetNum(myS, &i, len);
                break;
            case ' ':  // 空格，跳过不处理
                break;
            default:  // 数字，是一个新值，暂存，用于后续保存或计算
                temp = GetNum(myS, &i, len) * symbol;
                break;
        }
    }

    //DebugOneArray(data, index);
    rlt = 0;
    for (i = 0; i < index; i++) {
        rlt += data[i];
    }

    return rlt;
}
```