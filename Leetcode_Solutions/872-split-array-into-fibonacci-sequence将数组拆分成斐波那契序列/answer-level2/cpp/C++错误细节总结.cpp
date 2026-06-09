1、变量首先要初始化；
2、字符型转为int值时，可以使用 
    int val = 0;
    for(int i = 0; i < size; i++) 
        val = val * 10 + value[i];
3、在每一次计算过程中，都要注意整数翻转

```
    for(int i = 0; i < size; i++) 
        val = val * 10 + value[i];
        if (val > INT_MAX) .....相应处理
```
4、递归中的回溯，在递归的过程中，如何做剪枝？————碰到不符合的分支，直接返回或跳过。
