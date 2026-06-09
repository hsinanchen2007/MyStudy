### 解题思路
此处撰写解题思路

### 代码

```c
int bitwiseComplement(int N){
    char bit[64];
    int i = 0;
    if(!N) {
        return 1;
    }
    
    while(N) {
        bit[i++] = N % 2;
        N /= 2;
    }

    int left,right,tmp;
    left = 0;
    right = i - 1;
    while(left < right) {
        tmp = bit[left];
        bit[left] = bit[right];
        bit[right] = tmp;
        left++;
        right--;
    }

    int res = 0;
    for (left = 0; left < i; left++) {
        if (bit[left] == 0) {
            res = res * 2 + 1;
        }
        else {
            res = res * 2;
        }
    }

    return res;
}
```