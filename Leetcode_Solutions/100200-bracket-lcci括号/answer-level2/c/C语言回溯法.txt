### 解题思路
1.构造一个结束条件
2.找到每个解空间树节点的特征，也就是说要明确解空间树节点是什么，本题中的节点是结果字符串的一个状态
3.回溯
本题中的结束条件为左右括号都消耗完，而构造节点时，应该首先考虑插入左侧节点，前提是左侧节点没有消耗完。
然后相同的位置，如果剩的右括号比较多，可以插右括号，而如果右括号剩的与左括号相同或更少，那么插右括号
会导致非法情况的出现。这里在同一位置先插左括号再查右括号的做法就是回溯的关键，而对右括号是否非法的判断
则是对解空间的一种剪纸方法。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void fillArr(int leftNum, int rightNum, char **retArr, char *temp, int *count, int n, int index)
{
    // 结束条件，如果左右括号都插完了，说明结束了，拷贝返回
    if (leftNum == 0 && rightNum == 0) {
        retArr[*count] = (char *)malloc(sizeof(char) * (2 * n + 1));
        strcpy(retArr[(*count)++], temp);
        return;
    }
    // 如果左括号有剩，优先插左括号
    if (leftNum > 0) {
        temp[index] = '(';
        // 进入分支中继续插下一个位置的括号
        fillArr(leftNum - 1, rightNum, retArr, temp, count, n, index + 1);
    }
    // 这个位置插过左括号后，如果右括号剩的比较多，就可以尝试插右括号，这样不会造成非法组合
    if (rightNum > leftNum) {
        temp[index] = ')';
        // 进入分支中继续插下一个位置的括号
        fillArr(leftNum, rightNum - 1, retArr, temp, count, n, index + 1);
    }

    return;
}
char** generateParenthesis(int n, int* returnSize){
    char **retArr = (char **)malloc(sizeof(char *) * 5000);
    char *temp = (char *)malloc(sizeof(char) * (2 * n + 1));
    // 字符穿最后一个位置置 \0
    temp[2 * n] = '\0';
    int count = 0;
    int index = 0;
    int leftNum = n;
    int rightNum = n;

    fillArr(leftNum, rightNum, retArr, temp, &count, n, index);
    *returnSize = count;
    
    return retArr;
}
```