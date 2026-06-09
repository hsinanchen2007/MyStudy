EXP->EXPEXP

EXP->(EXP)

EXP->()

从语法易得，表达式只以左括号为入口，如果一个表达式结束后，还有后续字符，那么结果会是EXP1+EXP2。(这里比较难明白的是Exp2可以继续分解成Exp2.1+Exp2.2……，但由加法结合律可知(Exp1+Exp2.1)+Exp2.2等于Exp1+(Exp2.1+Exp2.2)。

从左括号入口，如果下一位是左括号，那是Exp->(Exp1)，取2*exp1，并定位到下一个表达式；如果下一位是右括号，取1，并定位到下一个表达式。

-   执行用时 :0 ms, 在所有 c 提交中击败了100.00% 的用户
-   内存消耗 :6.8 MB, 在所有 c 提交中击败了85.71%的用户

```
int scoreOfParentheses(char * S){
    int left = 0;
    int sum = 0;

    if('(' != *S){
        return 0;
    }
    if('(' == *S && '(' == *(S+1)){
        left = 1;
        sum = 2*scoreOfParentheses(S+1);        
    }
    if('(' == *S && ')' == *(S+1)){
        left = 1;
        sum = 1;
    }
    //find this exp end;
    while(left && *(++S)){
        if('(' == *S){
            left++;
        }
        if(')' == *S){
            left--;
        }
        if(!left)
            break;
    }
    return sum + scoreOfParentheses(S+1);
}

```
