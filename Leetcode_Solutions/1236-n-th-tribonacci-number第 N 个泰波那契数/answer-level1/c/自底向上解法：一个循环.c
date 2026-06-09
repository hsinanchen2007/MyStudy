
自底而上解法：
1、如果为0、1、2，就直接返回a、b、c
2、如果n大于2，进入循环更新a、b、c的值，
3、跳出循环时c就是解

int tribonacci(int n){
    int a = 0;
    int b = 1;
    int c = 1;
    
    if(n == 0)
    {
        return a;
    }else if(n == 1)
    {
        return b;
    }else if(n == 2)
    {
        return c;
    }
    
    for(int i = 3; i <= n; i++)
    {
        int tmp = a+b+c;
        a = b;
        b = c;
        c = tmp;
    }
    
    return c;   
}