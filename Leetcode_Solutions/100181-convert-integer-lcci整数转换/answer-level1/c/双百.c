### 解题思路

将两者异或后看有几个1

### 代码

```c
int convertInteger(int A, int B){
    unsigned int c=(unsigned int)A^(unsigned int)B;
    int sum=0;
    while(c>0){
        sum+=(c%2);
        c=c>>1;
    }
    return sum;
}
```