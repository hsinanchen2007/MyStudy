### 解题思路
先将负数转换成正数，用一个flag来表示正负，因为负数比正数多一个表示，也要先用一个long int 来存储x，防止边界的负数转换成正数不能表达，然后用一个数乘以10加上x除以10的余数来分别进行各个位数的调换。最后根据flag来添加符号，返回前进行值的判断是否返回得到的值，最后返回。

### 代码

```c
int reverse(int x){
    int flag = 0;
    long int rever=0;
    long int x1=x;
    if(x < 0){
        flag = 1;
        x1 = 0-x1;
    } 
    while(x1>=10)
    {
        rever=rever*10+(x1%10);
        x1=x1/10;
    }
    rever = rever*10+x1;
    if(flag == 1)
    {
        rever=0-rever;
    }
    int i;
    long int max=1;
    for(i=0;i<31;i++)
    {
        max=max*2;
    }
    if(rever > max-1 ||rever <-max) return 0;
    return (int)rever;
}
```