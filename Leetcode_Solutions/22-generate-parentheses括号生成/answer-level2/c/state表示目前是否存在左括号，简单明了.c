### 解题思路
max记录还可以插入多少个左括号，state记录已使用多少个左括号。代码很短好理解。

### 代码
```c

void MyDfs (char **ans, char *record, int pos, int* floor, int state, int max, int n) {
    if (pos == n) {
        ans[*floor] = (char *)malloc(sizeof(char) * (n + 1));
        for (int i = 0; i < n; i++)  ans[*floor][i] = record[i];
        ans[*floor][n] = '\0';
        (*floor)++;
        return;
    } 
    if (state == 0) {//必须用左括号
        record[pos] = '(';
        MyDfs (ans, record, pos + 1, floor, state + 1, max - 1, n);//max减一表示可用左括号减一
    } else {//左右括号都可以插入
        if (max > 0) {
            record[pos] = '(';
            MyDfs (ans, record, pos + 1, floor, state + 1, max - 1, n);
        }
        record[pos] = ')';
        MyDfs (ans, record, pos + 1, floor, state - 1, max, n);//用了右括号，state减一
    }
    return;
} 
char ** generateParenthesis(int n, int* returnSize){
    char **ans = (char **)malloc(sizeof(char *) * 10002);
    char *record = (char *)malloc(sizeof(char) * 2 * n);
    int floor = 0, pos = 0;
    int state = 0;
    MyDfs(ans, record, pos, &floor, state, n, n * 2);
    *returnSize = floor;
    return ans;
}
```