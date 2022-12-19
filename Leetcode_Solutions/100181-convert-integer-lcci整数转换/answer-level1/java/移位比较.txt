Java中int有32bit,可以分别比较AB每一位是否一样。

```java
    public int convertInteger(int A, int B) {
        int count = 0;
        for(int i = 0;i < 32;i++){
            if((A & 1) != (B & 1)) count++;//取AB最低位比较
            A = A >>> 1;//无符号右移，因为AB可能为负数
            B = B >>> 1;
        }
        return count;
    }
```
