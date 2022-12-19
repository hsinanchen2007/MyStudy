### 解题思路
按题目思路，翻译成C语言

### 代码

```c
int numberOfSteps (int num){
    int steps=0;
    while(num!=0)
    {
        if(num%2==0)
            num/=2;
        else
            num-=1;
        steps=steps+1;
    }
    return steps;
}
```