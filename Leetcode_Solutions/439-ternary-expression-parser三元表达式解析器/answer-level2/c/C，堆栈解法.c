
这题咋一看找不到头绪，但是只要说一下解题方法就不难了，关键点：
1，由于是右结合，所以需要从字符串的尾部往前处理
2，如果是数字或者T或者F就压栈，：号不需要压栈
3，碰到？号需要：1）从栈内弹出2各元素；2）取？号前面一个字符然后根据字符内容确定取弹出元素的哪一个；3）别忘了再把本次结果压栈

char * parseTernary(char * expression){
    int len = strlen(expression);
    if (expression == NULL || len == 0) {
        return NULL;
    }
    char stack[10000];
    int id = 0;
    char l;
    char r;
    char *res = malloc(2);
    while (len > 0) {
        if (isdigit(expression[len - 1]) 
            || (expression[len - 1] == 'F')
            || (expression[len - 1] == 'T')) {
            stack[id++] = expression[len - 1];  //数字,T,F就压栈
        } else if (expression[len - 1] == '?') { //碰到？就从栈内弹出两个元素
            //出栈两个元素
            l = stack[--id];  
            r = stack[--id]; 
            len--;  //为了往？号前取的T或F元素
            if (expression[len - 1] == 'T') {
                stack[id++] = l;  //跟据T或F对应的获取本次表达式的结果，然后再次压栈
            } else {
                stack[id++] = r;
            }
        }
        len--;  //本轮处理结束后再往前取下一个待处理字符
    }
    
    res[0] = stack[--id];
    res[1] = '\0';
    return res;

}![image.png](https://pic.leetcode-cn.com/2b6a45db4fef86ccc31add5650e5539800d03a197b88451fc7b64c8a0666e49a-image.png)
