![image.png](https://pic.leetcode-cn.com/bfed2f12404dd968013e439463f58548842f4343f5065b17b5270e05f3869f28-image.png)
1、4个数据先随便选两个进行各种计算，变成3个
2、递归3个数据先随便选两个进行各种计算，变成2个
3、递归2个数据各种运算，判断是否为24点

注意doule数据的相等判断，坑人(fabs((nums[0] - 24)) <= 1e-6);
```
typedef double (*ClacFunc) (double a, double b);
#define DEBUG_PRINTF // printf

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
    
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            double result[3] = {0};
            int cnt = 0;

            for (int k = 0; k < size; k++) {
                if (k != i && k != j) {
                    result[cnt++] = nums[k];
                }
            }

            for (int k = 0; k < CLAC_TYPE; k++) {
                int calcCnt = cnt + 1; 
                bool isOK = false;
                if (g_clacFunc[k].isSwap) {
                    result[cnt] = g_clacFunc[k].func(nums[j], nums[i]);
                    isOK = calc(result, calcCnt);
                    if (isOK) {
                        return true;
                    }
                }

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
