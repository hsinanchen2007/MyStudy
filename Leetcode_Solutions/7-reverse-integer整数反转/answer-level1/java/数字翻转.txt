### 解题思路
如果只有一位 返回自身即可；
如果不为一位，则循环将最后一位弹出再*10 + 最后一位，进而得到结果。
可能存在int值溢出问题，我用long存储，最后判断是否大于或小于最大最小值。

### 代码

```java
class Solution {
    public int reverse(int x) {
        //如果x为正负 单位数 就返回自身
        if (x > -10 && x < 10 ){
            return x;
        }
        long temp = 0;
        int c = 0;
        while (x != 0){
            //返回最后一位
            c = x % 10;
            //剔除最后一位
            x /= 10;
            //临时数 = 临时数乘10加c
            temp = temp * 10 + c ;
        }
        return (temp > Integer.MAX_VALUE || temp < Integer.MIN_VALUE) ? 0 : (int)temp;
    }
}
```


```
代码块
```
