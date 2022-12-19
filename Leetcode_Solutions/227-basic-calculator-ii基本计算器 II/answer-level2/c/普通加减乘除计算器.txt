```
/*
1、表达式中可能有空格
2、只有+ - * /
3、碰到加减，算出结果，入栈。同时更新后面运算的符号。碰到乘除，算出结果，先不入栈。结果保存给左值，右值清0。更新后面运算类型为乘除，本次运算结果符号为正.碰到数字，更新右值。（左值只用来临时保存乘除法的被乘数或被除数）
*/
#define IS_PLUS   1
#define IS_MINUS  (-1)
#define IS_MULTI  0
#define IS_DIV    2

int calculate(char * s){
    int num = 0;
    int leftnum = 0;
    int rightnum = 0;
    int arrindex = 0;
    int plusOrMinus = IS_PLUS;
    int multioOrDiv = IS_PLUS;

    printf("%s", s);
    int sLen = strlen(s);
    int arrlen = sLen;
    int *arr = (int *)malloc(arrlen * sizeof(int));

    memset(arr, 0, arrlen * sizeof(int));
    for (int i = 0; i <= sLen; i++) {
        switch(s[i]) {
            /*碰到加减，算出结果，入栈。同时更新后面运算的符号。*/
            case '+':
                if (multioOrDiv == IS_PLUS) {
                    arr[arrindex] = leftnum + rightnum * plusOrMinus;
                } else if (multioOrDiv == IS_MULTI) {
                    arr[arrindex] = leftnum * rightnum * plusOrMinus;
                } else if (multioOrDiv == IS_DIV) {
                    arr[arrindex] = leftnum / (rightnum * plusOrMinus);
                }               
                arrindex++;
                plusOrMinus = IS_PLUS;
                multioOrDiv = IS_PLUS;
                leftnum = 0;
                rightnum = 0;
                break;
            case '-':
                if (multioOrDiv == IS_PLUS) {
                    arr[arrindex] = leftnum + rightnum * plusOrMinus;
                } else if (multioOrDiv == IS_MULTI) {
                    arr[arrindex] = leftnum * rightnum * plusOrMinus;
                } else if (multioOrDiv == IS_DIV) {
                    arr[arrindex] = leftnum / (rightnum * plusOrMinus);
                }  
                arrindex++;
                plusOrMinus = IS_MINUS;
                multioOrDiv = IS_PLUS;
                leftnum = 0;
                rightnum = 0;
                break;               
            /*碰到乘除，算出结果，先不入栈。结果保存给左值，右值清0。更新后面运算类型为乘除，本次运算结果符号为正*/
            case '*':
                if (multioOrDiv == IS_PLUS) {
                    leftnum = leftnum + rightnum * plusOrMinus;
                } else if (multioOrDiv == IS_MULTI) {
                    leftnum = leftnum * rightnum * plusOrMinus;
                } else if (multioOrDiv == IS_DIV) {
                    leftnum = leftnum / (rightnum * plusOrMinus);
                }
                rightnum = 0;
                multioOrDiv = IS_MULTI;
                plusOrMinus = IS_PLUS;
                break;
            case '/':
                if (multioOrDiv == IS_PLUS) {
                    leftnum = leftnum + rightnum * plusOrMinus;
                } else if (multioOrDiv == IS_MULTI) {
                    leftnum = leftnum * rightnum * plusOrMinus;
                } else if (multioOrDiv == IS_DIV) {
                    leftnum = leftnum / (rightnum * plusOrMinus);
                }
                rightnum = 0;
                multioOrDiv = IS_DIV;
                plusOrMinus = IS_PLUS;
                break;
            /*算式结束，算出结果，入栈*/
            case '\0':
                printf("left: %d  right:%d plusormins: %d multiordiv: %d arrindex: %d", leftnum, rightnum, plusOrMinus, multioOrDiv, arrindex);
                if (multioOrDiv == IS_PLUS) {
                    arr[arrindex] = leftnum + rightnum * plusOrMinus;
                } else if (multioOrDiv == IS_MULTI) {
                    arr[arrindex] = leftnum * rightnum * plusOrMinus;
                } else if (multioOrDiv == IS_DIV) {
                    arr[arrindex] = leftnum / (rightnum * plusOrMinus);
                }  
                printf("result: %d", arr[arrindex]);
                arrindex++;
                plusOrMinus = IS_PLUS;
                multioOrDiv = IS_PLUS;
                leftnum = 0;
                rightnum = 0;
                break;
            /*跳过空格*/
            case ' ':
                break;
            /*碰到数字，更新右值。（左值只用来临时保存乘除法的被乘数或被除数）*/
            default:
                /*考虑中间运算数字长度可能超过32bit，要先算出字节对应在数字*/
                rightnum = s[i] - '0' +  rightnum * 10; 
                break;
        }
    }

    int result = {0};
    for (int i = 0; i < arrlen; i++) {
        result += arr[i];
    }
    free(arr);
    return (int)result;
}
```
