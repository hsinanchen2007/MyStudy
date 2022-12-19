### 解题思路
此处撰写解题思路

### 代码

```c
void toBit(int num, int *val) {
    int i = 0;
    while(num) {
        val[i] = num & 1;
        num >>= 1;
        i++;
    }
}
int reverseBits(int num){
    int val[32] = {0};
    toBit(num, val);
    
    int count = 0;
    int countPre = 0;
    int max = 0;
    for (int i = 0; i < 32; i++) {
        if (val[i] == 1) {
            count++;
        } else {
            if (countPre + count + 1 > max) {
                max = countPre + count + 1;
            }
            countPre = count;
            count = 0;
        }
    }

    return max;
}
```