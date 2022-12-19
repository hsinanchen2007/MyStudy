### 解题思路
纯C

### 代码

```c
char * multiply(char * num1, char * num2){
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    char* pcRes = (char*)malloc((len1 + len2 + 1) * sizeof(char));
    memset(pcRes, '0', (len1 + len2) * sizeof(char));
    pcRes[len1 + len2] = '\0';

    int indexOfNum1 = 0;
    int indexOfNum2 = 0;
    int carry = 0;
    int pre = 0;

    for (indexOfNum2 = len2 - 1; 0 <= indexOfNum2; indexOfNum2--)
    {
        for (indexOfNum1 = len1 - 1; 0 <= indexOfNum1; indexOfNum1--)
        {
            int a = num1[indexOfNum1] - '0';
            int b = num2[indexOfNum2] - '0';
            int c = pcRes[indexOfNum2 + indexOfNum1 + 1] - '0';
            int d = a * b + c + carry;
            pcRes[indexOfNum2 + indexOfNum1 + 1] = d % 10 + '0';
            carry = d / 10;
        }
        
        if (carry)
        {
            pcRes[indexOfNum2] = carry + '0';
            carry = 0;
        }
    }

    while (pcRes[pre] == '0' && pre <= len1 + len2)
    {
        pre++;
    }

    if (pre == len1 + len2)
    {
        return "0";
    }
    else
    {
        return pcRes + pre;
    }
}
```