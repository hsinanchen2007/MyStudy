### 解题思路
抄的一位老哥的代码，直到现在我依然不能融会贯通里面所有的逻辑。倒是代码风格非常好，值得学习。
1.需要用到的变量一次全部定义，统一初始化。
2.每个数学运算符都要有空格
3.括号还是空一格好看

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 typedef struct node{
     char num;//z数字字符
     int len;//单键字符长度
     char ichar[5];
 }HASH;

 HASH hash[10] = {
     '0', 0, "",
     '1', 3, "!@#",
     '2', 3, "abc",
     '3', 3, "def",
     '4', 3, "ghi",
     '5', 3, "jkl",
     '6', 3, "mno",
     '7', 4, "pqrs",
     '8', 3, "tuv",
     '9', 4, "wxyz"
 };

int JudegNum(char* digits, int* iRangerNum){
     int i = 0;
     int iLen = 0;
     int amount = 1;

    for (i = 0; digits[i] != '\0'; i++){
        if ((digits[i] >= '2') && (digits[i] <= '9')){
            iLen++;
            amount *= hash[digits[i] - '0'].len;
        }
        else{
            iLen = 0;
            break;
        }
     }
     
     *iRangerNum = amount;

     return iLen;
 }
char ** letterCombinations(char * digits, int* returnSize){
        char    **ppRet     = NULL;
        int     iRangerNum  = 0;
        int     i           = 0;
        int     j           = 0;
        int     k           = 0;
        int     interval    = 0;
        int     NumSize     = 0;

        NumSize = JudegNum(digits, &iRangerNum);
        if (NumSize <= 0){
            *returnSize = 0;
            return NULL;
        }

        ppRet = (char **)malloc(sizeof(char*) * iRangerNum);
        interval = iRangerNum;
        *returnSize = iRangerNum;

        for(i = 0; i < NumSize; i++){//正个for用于把一个按键上的字母可能全部输出
            k = hash[digits[i] - '0'].len;
            interval /= k;//这个字母的深度，及这个字母之后还有多少种组合

            for(j = 0; j < iRangerNum; j++){
                if (i == 0){//申请新的节点，存放char*类型的数组指向这些申请来的内存
                    ppRet[j] = (char *)malloc(sizeof(char) * (NumSize + 1));
                    ppRet[j][NumSize] = '\0';
                }
                ppRet[j][i] = hash[digits[i] - '0'].ichar[(j / interval) % k];
            }

        }

        return ppRet;

}
```