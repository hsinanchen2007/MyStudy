/*
1.注意将符号处理转化为数字处理；
2.数组采用动态分配内存；
3.注意对比时使用栈顶两个元素对比，不要用栈顶元素和未入栈元素对比；
4.注意栈变为空但字符串未遍历完时，此时要入栈两个元素。
*/
bool isValid(char * s){
    int len = strlen(s);
    int j;
    char temp1,temp2;
    int cnt = 0;
    char *stack = (char *)malloc(len * sizeof(char));

    if(len == 0) {
        return true;
    } else {
        if(len % 2 != 0) {
            return false;
        }
    }

    stack[cnt] = s[0];
    cnt++;

    for(j = 1; j < len; j++) {
        if(cnt == 0) {
            stack[cnt] = s[j];
            cnt++;
            j++;
        }
        stack[cnt] = s[j];
        temp1 = stack[cnt - 1];
        temp2 = stack[cnt];

        if(abs(temp2 - temp1 == 1) || abs(temp2 - temp1 == 2)) {
            cnt--;
        } else {
            cnt++;
        }
    }

    free(stack);
    return cnt == 0 ? true : false;
}