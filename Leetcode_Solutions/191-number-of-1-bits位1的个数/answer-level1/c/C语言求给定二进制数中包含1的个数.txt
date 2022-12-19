### 解题思路
用n和1进行与运行可以每次得到最低位的数字，然后n每次向右移一位，直到n等于0为止

### 代码

```c
int hammingWeight(uint32_t n) {
    int count = 0;
    while (n != 0) {
      if(n & 1 != 0) {
          count++;
      } 
        n = n >> 1;
    }
    return count;
}
```