就比如101，即5吧，补数是2，为什么呢?101要用3个二进制位，2的三次方=8，补数就是8-1-5=2.
再比如1011，即11，补数是2的4次方-1-11=4.
就酱！

```
int findComplement(int num) {
        long long temp = 1;
        while(num>=temp){
            temp <<= 1;
        }
        return temp-1-num;
    }
```
