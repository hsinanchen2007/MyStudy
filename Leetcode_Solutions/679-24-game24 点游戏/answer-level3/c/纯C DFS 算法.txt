深度优先算法
（1）6种运算
      a + b、a * b、a - b、 b - a、a / b、b / a.
（2）2 种数值的组合方式
    （（a b）c）d  
    （a b）（c d）
（3）DFS的截止条件：4个数值全部取完，满足24点
（4）需要使用debouble类型，因存在除法

```
typedef enum {
    MIN,
    ADD,
    MULTI,
    MINUS1,
    MINUS2,
    DIVIDE1,
    DIVIDE2,
    MAX,
}CALTYPE;
#define NUMLEN 3
/* 共计6种结果 */
double Calcute(double a, double b, CALTYPE calTye)
{
    switch(calTye) {
        case ADD: {
            return a + b;
        }
        case MULTI: {
            return a * b;
        }
        case MINUS1: {
            return a - b;
        }
        case MINUS2: {
            return b - a;
        }
        case DIVIDE1: {
            return a / b;
        }
        case DIVIDE2: {
            return b / a;
        }
        default: {
            break;
        }
    }
    return -1;
}
/* 检查2个元素之和是否为24点 */
bool CalcuteAll(double a, double b)
{
    for (CALTYPE i = ADD; i < MAX; i++) {
        if (fabs(Calcute(a, b, i) - 24) <= 1e-6) {
            return true;
        }
    }
    return false;
}
bool Dfs(int unSelectnums[], double currentRes, double currentElement, int unSelectNum)
{
    bool checkRes = false;
    if (unSelectNum == 0) {
        if (CalcuteAll(currentRes, currentElement)) {
            return true;
        }  
        return false;      
    }
    if (unSelectNum == 2) {
        for (CALTYPE i = ADD; i < MAX; i++) {
            double res = Calcute(currentRes, currentElement, i);
            int nums[NUMLEN] = { 0 };
            nums[0] = unSelectnums[1];
            checkRes = Dfs(nums, res, unSelectnums[0], 1);
            if (checkRes) {
                return true;
            }
            nums[0] = unSelectnums[0];
            checkRes = Dfs(nums, res, unSelectnums[1], 1);  
            if (checkRes) {
                return true;
            }
            for (CALTYPE j = ADD; j < MAX; j++) {
                double res2 = Calcute(unSelectnums[0], unSelectnums[1], j);
                checkRes = Dfs(unSelectnums, res, res2, 0);
                if (checkRes) {
                    return true;
                }
            }      
        }
    }
    if (unSelectNum == 1) {
        for (CALTYPE i = ADD; i < MAX; i++) {
            double res = Calcute(currentRes, currentElement, i);
            checkRes = Dfs(unSelectnums, res, unSelectnums[0], 0);
            if (checkRes) {
                return true;
            }          
        }
    }
    return false;
}
void GetUnSelect(int* nums, int index1, int index2, int unSelect[], int numsSize)
{
    int len = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i == index1 || i == index2) {
            continue;
        }
        unSelect[len++] = nums[i];
    }
    return;
}


bool judgePoint24(int* nums, int numsSize){
    bool checkRes = false;
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            int unSelectnums[NUMLEN] = { 0 };
            GetUnSelect(nums, i, j, unSelectnums, numsSize);
            checkRes = Dfs(unSelectnums, nums[i], nums[j], 2); 
            if (checkRes) {
                return true;
            }
        }
    }
    return false;
}
```
