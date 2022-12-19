```
typedef double (*ClacFunc) (double a, double b);
#define DEBUG_PRINTF  // printf

void debugPrintf(double* nums, int size)
{
    DEBUG_PRINTF("calc[%d]:", size); 
    for (int k = 0; k < size; k++) {
        DEBUG_PRINTF("%lf ", nums[k]); 
    }

    DEBUG_PRINTF("\n");
}

double Add(double a, double b) { DEBUG_PRINTF("%lf+%lf=%lf\n", a, b, a + b); return a + b; };
double Sub(double a, double b) { DEBUG_PRINTF("%lf-%lf=%lf\n", a, b, a - b);  return a - b; };
double Mul(double a, double b) { DEBUG_PRINTF("%lf*%lf=%lf\n", a, b, a * b);  return a * b; };
double Div(double a, double b) { DEBUG_PRINTF("%lf/%lf=%lf\n", a, b, a / b);  return a / b; };

typedef struct {
    bool isSwap;    // 是否交换
    ClacFunc func;  // 函数
}CLAC;

#define CLAC_TYPE 4
#define NUM_SIZE 4
static CLAC g_clacFunc[CLAC_TYPE] = {
    {0, Add},
    {1, Sub},
    {0, Mul},
    {1, Div}
};

bool calc(double* nums, int size){
    debugPrintf(nums, size);
    if (size == 1) {
       return (fabs((nums[0] - 24)) <= 1e-6); 
    }
    //当四个的时候，第一次选两个数时有4*3种，之后选运算符为12*4=48，
    //然后3个选两个为3*2种，之后选运算符：6*4 = 24；
    //最后2个选运算符：2*4种（有先后顺序之分）
    //不过+和*满足交换律
    //任选两个数
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            double result[3] = {0};
            int cnt = 0;
            //不能添加i，j  因为i和j所在位置的数接下里要进行计算
            for (int k = 0; k < size; k++) {
                if (k != i && k != j) {
                    result[cnt++] = nums[k]; // 存剩下的待做计算的几位数
                }
            }
            //任意进行4种运算
            for (int k = 0; k < CLAC_TYPE; k++) {
                int calcCnt = cnt + 1; 
                bool isOK = false;
                //#1不满足交换律 - / 所以 #2计算完 a - b 之后还得这里得重新计算 b - a
                if (g_clacFunc[k].isSwap) {
                    result[cnt] = g_clacFunc[k].func(nums[j], nums[i]);
                    isOK = calc(result, calcCnt); // 递归时的参数，是新数组 result，里面存着未剩下的数和新得到的结果
                    if (isOK) {
                        return true;
                    }
                }
                //#2 全部计算一遍
                result[cnt] = g_clacFunc[k].func(nums[i], nums[j]);
                isOK = calc(result, calcCnt);
                if (isOK) {
                    return true;
                }
            }
        }
    }

    return false;
}
bool judgePoint24(int* nums, int numsSize)
{
    double tmpNums[NUM_SIZE] = {0};

    for (int i = 0; i < numsSize; i++) {
        tmpNums[i] = nums[i]; 
    }

    return calc(tmpNums, numsSize);
}
```
