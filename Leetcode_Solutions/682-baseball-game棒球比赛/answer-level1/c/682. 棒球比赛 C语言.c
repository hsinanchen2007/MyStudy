### 解题思路
首先，思考是否必须使用栈，如果不使用栈我们可以节省 N 的空间：
A. 观测到‘C’的操作为删除操作，且没有限制‘C’使用的数量，即可以无限使用‘C’。如果不使用额外的空间（如栈）进行记录分数的话，我们就需要进行实时计算来算出‘C’需要删除的分数。这将导致我们消耗了更多的时间，这是不值得的。
综上所述，我们需要使用额外的空间（如栈）进行分数的保存。

然后，思考使用什么样的栈，如果数据种类单一，则只需统计数量变化即可（只需一个变量），比如计算单一种类的括号；否则则需要使用传统的栈（需要 N 的空间）：
A. 由于数据种类不单一(有不同的数字和‘C’‘D’‘+’三种符号)，所以只能使用传统的栈

据此我们完成代码。

### 代码

```c
int calPoints(char ** ops, int opsSize){
    int i = 0;
    int j = 0;
    int record[1000];
    int total = 0;
    for (i = 0; i < opsSize; i++) {
        if (ops[i][0] == '+' && ops[i][1] == '\0') {
            record[j] = 0;
            if ((j - 1) >= 0)
                record[j] += record[j-1];
            if ((j - 2 >= 0))
                record[j] += record[j-2];
            total += record[j];
            j++;
        } else if (ops[i][0] == 'D' && ops[i][1] == '\0') {
            record[j] = 0;
            if ((j - 1) >= 0)
                record[j] = 2 * record[j - 1];
            total += record[j];
            j++;
        } else if (ops[i][0] == 'C' && ops[i][1] == '\0') {
            if (j > 0) {
                j--;
                total -= record[j];
            }
        } else {
            int goal = atoi(ops[i]);
            record[j++] = goal;
            total += goal;
        }
    }

    return total;
}
```

### 优化
时间消耗4ms，但还有更低的。我们尝试将其优化到0ms。
A. 使用栈空间而不是堆空间
    将代码 record = malloc(opsSize * sizeof(int)) 修改为 record[1000];
    因为 1.堆空间分配时间耗时大大高于栈 2.使用堆空间时可能会切页
    可以参考 https://blog.csdn.net/qq1184810369/article/details/17238725

    修改后，依然为4ms。可能是因为只分配了一次，基本上没有什么变化。

B. 减少函数调用
    将 判断语句 !strcmp(ops[i], +) 修改为 ops[i][0] == '+' && ops[i][1] == '\0'
    因为 函数调用涉及到栈分配、PC指针跳转、函数返回等操作，可能时间会花费多一些。但由于编译器优化，一般没什么效果。

    修改后,依然为4ms。

C. 牺牲部分健壮性，减少判断条件
    将 判断语句ops[i][0] == '+' && ops[i][1] == '\0' 修改为 ops[i][0] == '+'。
    这样将减少最多一半的判断耗时。

    修改后，耗时0ms。
