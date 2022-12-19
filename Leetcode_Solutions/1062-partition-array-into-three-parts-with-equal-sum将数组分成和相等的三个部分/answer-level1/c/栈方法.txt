### 解题思路
1. 求和数组, 检查数组是不是3的倍数, 如果不是3的倍数, 直接返回False
2. 总和除以3, 得到各部分的和
3. 将数组的 项加栈顶 压入栈(初始栈顶temp为0), 如果栈顶temp == sum, 则清空栈, 并记录一次清空
4. 如果发生第二次清空, 前两个清空的栈符合条件, 此时第三个栈必定符合条件, 直接返回true
### 代码

```c
bool canThreePartsEqualSum(int* A, int ASize){
    int sum =  0;
    for (int i=0; i<ASize; i++) sum += A[i]; // Done

    if (sum %3 != 0) return false;
    else sum /= 3;
    int i, temp = 0;
    int index = 0;
    for (i=0; i<ASize; i++){
        temp += A[i];
        if (temp == sum ){
            if (index==1){ return true; }
            else index=1;
            temp = 0;
        }
    }
    return false;
}
```