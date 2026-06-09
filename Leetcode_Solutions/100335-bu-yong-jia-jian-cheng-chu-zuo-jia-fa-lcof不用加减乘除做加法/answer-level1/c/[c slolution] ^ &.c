### 解题思路
此处撰写解题思路

### 代码

```c
int add(int a, int b){
    while(b != 0){
        int tmp = a^b;
        b = (uint32_t)(a&b)<<1;
        a = tmp;
    }
    return a;
}
```