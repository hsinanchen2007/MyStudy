# 思路
   不清楚有多少位会被改变，处理完一定会改变的位后交给递归解决，注意变量**len**和**i**要用long类型。
# code
```java
    public int rangeBitwiseAnd(int m, int n) {
        if(m == n) return m;
        long len = (long)n - (long)m;
        long i = 1, count = 0;
        while (i <= len){
            i <<= 1;
            count++;
        }
        m >>>= count;
        n >>>= count;
        return rangeBitwiseAnd(m ,n) << count;
    }
```