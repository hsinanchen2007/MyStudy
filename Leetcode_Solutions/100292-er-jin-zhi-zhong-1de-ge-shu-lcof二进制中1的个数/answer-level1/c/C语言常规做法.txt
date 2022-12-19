参考将十进制数转二进制的做法，每次除以2后，余数为1时，二进制中1的个数增加1。
```c
int hammingWeight(uint32_t n) {
    short count=0;
    while(n!=0){
        if(n%2==1) count++;
        n=n/2;
    }
    return count;
}
```