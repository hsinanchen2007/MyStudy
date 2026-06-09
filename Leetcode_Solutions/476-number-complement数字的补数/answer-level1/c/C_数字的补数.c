### 解题思路
借助一个栈即可实现

### 代码

```c
int findComplement(int num){
    int stack[31];
    int top=0;
    while(num!=0)
    {
        stack[top++]=num%2==0?1:0;
        num/=2;
    }
    while(top!=0)
        num=num*2+stack[--top];
    return num;
}
```