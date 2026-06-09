### 解题思路
此处撰写解题思路

### 代码

```c
int hammingWeight(uint32_t n) {
    if( n < 0){
        return -1;
    }
    int num = 0;
    while(n){
        num = (n & 1) == 1 ? num + 1 : num;
        n = n >> 1; 
    }
    return num;
}
```