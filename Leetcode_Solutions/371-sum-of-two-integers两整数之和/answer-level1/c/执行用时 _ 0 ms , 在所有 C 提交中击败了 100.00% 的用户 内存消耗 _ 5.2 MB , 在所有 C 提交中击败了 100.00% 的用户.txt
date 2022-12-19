### 解题思路
此处撰写解题思路

### 代码

```c
int getSum(int a, int b){
    int sum;
    unsigned int carry;
    while(1){
        sum = a ^ b;
        carry = a & b;
        if(carry == 0)
            break;
        a = sum;
        b = carry << 1;
    }
    return sum;
}
```