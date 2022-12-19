将所有数据入栈，入栈时将当前字符逐个从栈顶开始对比、栈顶大于当前字符时将栈顶出栈，当不小于栈顶数据时停止出栈，将当前字符入栈
当全部入栈后k不为0， 说明还可以删除数据，由于站内数据当前是从小到大，所以直接将最后k个数删掉，如果deep<k则直接返回‘0’
```
char * removeKdigits(char * num, int k){
    int len = strlen(num);
    char *stack = malloc(sizeof(char) * len + 2);
    int deep = -1;
    int i;
    for (i = 0; i < len; i++) {
        //栈内有数据时，将当前字符逐个从栈顶开始对比、栈顶大于当前字符时出栈，当不小于栈顶数据时停止出栈
        while (deep >= 0 && num[i] < stack[deep] && k > 0) {
            deep--;
            k--;
        }
        deep++;
        stack[deep] = num[i];
        //栈内唯一数据为‘0’时清空栈
        if (stack[0] == '0') {
            deep = -1;
        }
        //printf("stack[%d]=%c\n", deep, stack[deep]);
    }
    //当全部入栈后k不为0， 说明还可以删除数据，由于站内数据当前是从小到大，所以直接将最后k个数删掉，如果不足则直接返回‘0’
    if (deep >= k) {
        stack[deep - k + 1] = '\0';
    } else {
        stack[0] = '0';
        stack[1] = '\0';
    }
    return stack;
}
```
