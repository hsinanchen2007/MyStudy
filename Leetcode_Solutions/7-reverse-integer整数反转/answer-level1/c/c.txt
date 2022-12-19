### 解题思路
如果new_num不溢出的话，强制转换为int后和new_num的值是相等的，如果不相等就说明溢出，返回0

### 代码

```c
int reverse(int x){
    int n;
    long new_num;
    new_num=0;
    while(x!=0)
    {   
        n=x%10;
        new_num=n+new_num*10;
        x=x/10;
    }
    if((int)new_num!=new_num)
        return 0;
    else
        return (int)new_num;

}
```