```
int calPoints(char ** ops, int opsSize){
    int *VGPR = (int *)malloc(1000 * sizeof(int)); // VGPR(Valid Game Point Records)，使用数组作为栈记录每回合的分数
    int top = -1; // 栈顶
    int sum = 0; // 记录总分
    for (int i = 0; i < opsSize; i++) {
        if (strcmp(ops[i], "+") == 0) {
            VGPR[top + 1] = VGPR[top] + VGPR[top - 1];
            top++;
        }
        else if (strcmp(ops[i], "D") == 0) {
            VGPR[top + 1] = 2 * VGPR[top];
            top++;
        }
        else if (strcmp(ops[i], "C") == 0) {
            top--;
        }
        else {
            VGPR[++top] = atoi(ops[i]);
        }
    }
    while(top > -1) {
        sum += VGPR[top--];
    }

    return sum;
}
```
