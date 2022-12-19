### 解题思路
丑数就是只包含质因数 2, 3, 5 的正整数。
这句话也就是这样的表达意思：一个数可以被拆成2的m次方*3的n次方*5的q次方
即只要不断地把这个数除以2、3、5
如果恰好能满足那样的形式就会得到最终num为1（1*任何数都得任何数）
不满足的话就得不到1

### 代码

```c
bool isUgly(int num){
    if(num<1) return 0;
    while(num%5==0) num=num/5;
    while(num%3==0) num=num/3;
    while(num%2==0) num=num/2;
    return num==1?1:0;
}
```