### 解题思路
C语言中的位操作
for循环使得每次取到n的第i位
和1进行与运算得到判断条件（即该位是否为1）
如果真则进行count++

### 代码

```c
int hammingWeight(uint32_t n) {
    int count=0;
    for(int i=31;i >= 0;i--){
        if((n>>(31-i)&1)==1){
            count++;
        }
    }
    return count;
}
```