### 解题思路
看其他题解用的与运算和或运算，但要注意的是，c语言中int 型做左移运算时，因为有符号位，所以会溢出，必须强制转化成无符号数。

### 代码

```c
int add(int a, int b){
    while(a!=0){
        int temp=a^b;
       a=((unsigned int)(a&b)<<1);
      b=temp;
    }
    return b;
}
```