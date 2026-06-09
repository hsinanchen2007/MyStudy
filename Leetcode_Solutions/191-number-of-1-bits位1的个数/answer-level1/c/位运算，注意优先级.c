### 解题思路
见代码。
值得注意的一点是："&"的优先级是低于各个判断运算符"<,>,==,!=",而左移、右移"<<,>>"
优先级高于判断运算符。
所以不加括号时n & x!=0 表达式结果始终为0。

### 代码

```c
int hammingWeight(uint32_t n) {
    int count=0;
    uint32_t x= 1;
    for(int i=0;i<32;i++){
        if((n & x )!= 0){//注意n&x要加括号
            count++;
        }
        x <<= 1;
    }
    return count;    
}
```