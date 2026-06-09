### 解题思路
此处撰写解题思路
1step  申请一个长度为1000的数组;
2step **ops 二维指针,*ops表示指向的每一行的开头;
3 step strcmp() 函数比较是否满足条件;
4 step 再满足规律进栈加退栈减的情况下将sum一个循环算出;
### 代码

```c

int calPoints(char ** ops, int opsSize){
  int  p[1000]={0};
   int  top=0;
    int sum = 0 ,i; // 记录总分
    for (i = 0; i < opsSize; i++) {
        if (strcmp(ops[i], "+") == 0) {
            p[top] = p[top-1] + p[top-2];
            sum+=p[top];
            top++;
        }
        else if (strcmp(ops[i], "D") == 0) {
            p[top] = 2 * p[top-1];
            sum+=p[top];
            top++;
        }
        else if (strcmp(ops[i], "C") == 0) {
            top--;
            // 退栈sum--;
            sum-=p[top];
        }
        else {
            // 进栈sum++;
            p[top] = atoi(ops[i]);
            sum+=p[top];
            top++;
        }
    }
/*i=0;
for(i=0;i<top;i++)
sum+=p[i];
*/
    return sum;
}


```