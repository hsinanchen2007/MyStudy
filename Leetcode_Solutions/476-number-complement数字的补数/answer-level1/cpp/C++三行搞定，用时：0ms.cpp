```
    int findComplement(int num) {
        // 防止左移溢出
        unsigned int n = num;
        // 不断清除最右边的1，直到只剩最高位的1
        /*
            说明：n&(n-1) 清除最低位的1
            n&(n-1) == 0 说明n只剩最高位的1
        */
        while ((n&(n-1)) != 0) n &= n-1;
        // 懂得都懂
        n = (n<<1) - 1;
        return n^num;
    }
```


