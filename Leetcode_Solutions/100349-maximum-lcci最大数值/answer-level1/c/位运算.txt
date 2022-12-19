### 解题思路
既然不能用if-else和其他的比较运算符，那么只能通过两数相减观察其差的符号位来判断大小。
注意此处要用long类型因为两个int型数值的差可能大于int的范围

### 代码

```c
int maximum(int a, int b){
    long fuhao = (((long)a-(long)b)>>63) & 1;
    return b*fuhao + a *(fuhao^1);
}
```