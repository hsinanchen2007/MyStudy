### 解题思路
思路详见代码和注释，重点是找到字典序下的循环规律

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
const char g_beginChar[8] = {'a', 'd', 'g', 'j', 'm', 'p', 't', 'w'}; 
const char g_charNum[8] = {3, 3, 3, 3, 3, 4, 3, 4};

char ** letterCombinations(char * digits, int* returnSize){
    if (digits == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int sLen = strlen(digits);

    if (sLen == 0) {
        *returnSize = 0;
        return NULL;
    }

    // 计算总的结果数量
    int fourCharNum = 0;
    for (int i = 0; i < sLen; i++) {
        if ((digits[i] == '9') || (digits[i] == '7')) {
            fourCharNum++;
        }
    }

    int rsltNum = 1;
    for (int i = 0; i < sLen; i++) {
        rsltNum *= 3;
    }

    for (int i = 0; i < fourCharNum; i++) {
        rsltNum = rsltNum * 4 / 3;
    }
    
    // 申请输出空间
    *returnSize = rsltNum;
    char ** rslt = (char **)malloc(sizeof(char *) * rsltNum);
    for (int i = 0; i < rsltNum; i++) {
        rslt[i] = (char *)malloc(sLen + 1);
        rslt[i][sLen] = 0;
    }

    // 执行计算
    /* 举个例子，输入789，总共有4*3*4=48种可能，对于任何一个数字，其所包含的字母出现的次数都是相同的， 
       比如8对应的三个字母各出现48/3次， 7则是48/4次，按照字典序排列则可发现这样一个规律，
       输出结果的第一个字母从前往后分别是12个pqrs，12个一循环
       输出结果的第二个祖母从前往后分别是4个tuv（12个为一周期，每个周期内前一个字母都是相同的），重复4次，即当首字母为p时，第2个字母从前往后是4个tuv，当首字母分别为qrs时第2个字母也是4个tuv
       为此，把握这种循环规律，用循环的方式来填充输出，具体如下： */
    int leftNum = rsltNum;
    for (int i = 0; i < sLen; i++) {
        char digValue = digits[i] - '2'; // 转换成下表，便于查表
        char beginChar = g_beginChar[digValue]; // 获取每个数字对应的第一个字母
        int charNum = g_charNum[digValue]; // 每个数对应的字母数量
        int loopNum = leftNum / charNum;   // 前一个字母固定的情况下，当前数字的每个字母出现的次数， 不理解的代入注释中的例子debug下
        leftNum /= charNum;

        for (int j = 0; j < rsltNum; j++) {
            char currChar = beginChar + ((j / loopNum) % charNum);
            rslt[j][i] = currChar;
        }
    }

    return rslt;
}
```