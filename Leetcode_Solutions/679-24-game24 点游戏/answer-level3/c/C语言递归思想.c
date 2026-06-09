### 解题思路
递归思想：总共有N张
1 退出条件：总数1张
2 选取两个数运算，运算结果组成1个新的数，总数变成N-1;
3 递归Step 2

这里主要有两个点需要提前识别：
1 整数的/运算是整数除法，浮点运算需要用double类型，运算结果需要考虑double的精度(fabs(ret - 24) < 1e-6)
2 括号(，)主要是在于提高运算等级，可以通过遍历所有组合来实现

参考：https://leetcode-cn.com/problems/24-game/solution/ying-he-cyu-yan-di-gui-by-zzcc-3/

### 代码

```c
#define PRINTF //printf
#define CALTYPES 4
#define CALNUMS 4
typedef bool (*CalFuc) (double a, double b, double *c);
#define SUM(a, b) (a + b)
#define MIN(a, b) (a - b)
#define MUL(a, b) (a * b)
#define DIV(a, b) (a / b)

bool CalFucSum(double a, double b, double *c)
{
    PRINTF("%d + %d\n", a, b);
    *c = SUM(a, b);
    return true;
}
bool CalFucMin(double a, double b, double *c)
{
    PRINTF("%d - %d\n", a, b);
    *c = MIN(a, b);
    return true;
}
bool CalFucMul(double a, double b, double *c)
{
    PRINTF("%d * %d\n", a, b);
    *c = MUL(a, b);
    return true;
}
bool CalFucDiv(double a, double b, double *c)
{
    bool ret = false;
    PRINTF("%d / %d\n", a, b);
    if(b == 0){
        return ret;
    }
    *c = DIV(a, b);
    ret = true;
    return ret;
}
typedef struct stCal{
    bool isSwap; // 是否需要交换 true表示需要交换，即交换后不一样  false表示不需要交换，即交换后一样
    CalFuc pfFun; // 函数指针
}CALC;

CALC CalArray[CALTYPES] = {
    {false, CalFucSum},
    {true, CalFucMin},
    {false, CalFucMul},
    {true, CalFucDiv}
};
bool CalNums(double *nums, int numsSize)
{
    if(numsSize == 1){ // 计算完成，和目标点数比较
        if(fabs(nums[0] - 24) < 1e-6){ // 1e-6
            PRINTF("%0.8lf\n", nums[0]);
            return true;
        }
        //PRINTF("%lf\n", nums[0]);
        return false;
    }
    for(int i = 0; i < numsSize; i++){
        for(int j = 0; j < numsSize; j++){
            if(i == j){ // 不同数
                continue;
            }
            double tmpNums[CALNUMS] = {0};
            int curSize = 0;
            for(int k = 0; k < numsSize; k++){
                if((k == i) || (k == j)){
                    continue;
                }
                tmpNums[curSize] = nums[k];
                curSize++;
            }
            for(int k  = 0; k < CALTYPES; k++){
                if(CalArray[k].pfFun(nums[i], nums[j], &tmpNums[curSize]) == false){
                    return false;
                }
                if(CalNums(tmpNums, (curSize + 1)) == true){
                    return true;
                }
                if(CalArray[k].isSwap == false){ // 不需要交换，继续
                    continue;
                }
                if(CalArray[k].pfFun(nums[j], nums[i], &tmpNums[curSize]) == false){
                    return false;
                }
                if(CalNums(tmpNums, (curSize + 1)) == true){
                    return true;
                }
            }

        }
    }
    return false;
}

bool judgePoint24(int* nums, int numsSize)
{
    double tmpNums[CALNUMS] = {0};
    for(int i = 0; i < numsSize; i++){
        tmpNums[i] = nums[i];
    }
    return CalNums(tmpNums, numsSize);
}
```