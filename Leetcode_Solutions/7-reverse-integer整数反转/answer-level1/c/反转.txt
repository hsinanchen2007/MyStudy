### 解题思路
long(长整型)取值范围为(-2^31~2^31-1),unsigned long为无符号长整型。
尝试数值超出用-2^31~2^31判断，运行不报错，提交报错，希望知道的大兄弟留言
### 代码

```c
int reverse(int x){
    long ret=0;
    while(x!=0){
        ret=ret*10 + x%10;
        x=x/10;
    }
    if((int)ret != ret)
    {
        return 0;
    }
    else return (int)ret;
}
```