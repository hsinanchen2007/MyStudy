

```java
    public int reverseBits(int n) {
        int n1 = 0;  //返回结果
        //遍历n二进制的每一位
        for (int i = 0; i <= 32; i++) { 
            n1 <<= 1;            //每次循环都把结构左移一位
            n1 += ((n >> i) & 1);   //遍历n二进制的每一位， 得到最后一位

        }
        return n1;
    }
```