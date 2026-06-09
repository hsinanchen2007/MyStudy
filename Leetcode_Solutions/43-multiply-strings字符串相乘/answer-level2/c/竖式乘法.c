```
/*
    字符串存放方式：
      0   1   2    3
    --------------------
    | 4 | 5 | 6 | '\0' |
    --------------------

    乘法运算:
        1 2 3
    x   4 5 6
    ----------
          1 8       --2 2
        1 2         --1 2
        6           --0 2
        1 5         --2 1
      1 0           --1 1
      5             --0 1
      1 2           --2 0
      8             --1 0
    4               --0 0
    -----------
    0 1 2 3 4   ----位置   每位的结果，结果放在i + j、i + j - 1
    4|5|0|8|8   ----结果个位
    1|1         ----结果进位
    ----------
    5|6|0|8|8


        9 9
    x   9 9 
    --------
        8 1     -- 1 1
      8 1       -- 0 1
      8 1       -- 1 0
    8 1         -- 0 0 
    --------
    0 1 2 3      --每位结果高位放在i + j，低位放在i + j + 1。
    8|7|0|1
    1|1|0|0
    --------
    9|8|0|1

        9 9 
    x     9


综上，
1、结果数组按最大长度，每位运算结果放在i+j, i+j+1。
123x456的结果调整为:
    0 1 2 3 4 5 
    0|4|5|0|8|8    
    0|1|1|0|0|0     
    -----------
    0|5|6|0|8|8
2、计算结束后,如果前面的位值位0，则用后面的往前移动。
3、结果字符串长度为num1Len + num2Len，在数组的num1Len+num2Len位置要填字符串结束符‘\0’
4、数字的有效起始位从第一个不为0的数字开始。特殊情况，结果为0时除外。
*/


/*字符串的最右位为数字的最低位，是数组的最高位*/
char * multiply(char * num1, char * num2){
    /*乘积位数最大位两数位数之和，按最大值算，取110 * 2*/
    int num1Len = strlen(num1);
    int num2Len = strlen(num2);
    int resultLen = num1Len + num2Len;
    int i;
    int j;
    int k;
    int m;
    /* 用整数数组计算结果，最后转换成字符串。使用int型数组，防止中间过程计算的数值比较大。 */
    int *tmpresult = (int *)malloc(sizeof(int) * (resultLen + 1));   
    char *result = (char *) malloc(resultLen + 1);
    memset(tmpresult, 0, sizeof(int) * (resultLen + 1));
    memset(result, 0, resultLen + 1);

    /*第一步：逐位计算，高位放在i+j，低位i+j+1位*/
    for (i = num1Len - 1; i >= 0; i--) {
        for (j = num2Len - 1; j >= 0; j--) {
            tmpresult[i + j] += ((num1[i] - '0') * (num2[j] - '0')) / 10;
            tmpresult[i + j + 1] += ((num1[i] - '0') * (num2[j] - '0')) % 10;
        }
    }

    /*第二步：从低位往高位做进位运算。*/
    for (k = resultLen - 1; k > 0; k--) {
        tmpresult[k - 1] += tmpresult[k] / 10;
        tmpresult[k] %= 10;
    }

    /*第三步：找出数字起始位置*/
    for (m = 0; m < resultLen - 1; m++) {
        if (tmpresult[m] != 0) {
            break;
        }
    }
    int valueindex = m;

    /*第四步：数字转换成字符串*/
    for (k = m; k < resultLen; k++) {
        result[k] = tmpresult[k] + '0';
    }
    free(tmpresult);
    result[resultLen] = '\0';
    
    return &result[valueindex];
}
```
