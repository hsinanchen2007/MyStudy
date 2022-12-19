![奇怪的知识增加了.jpg](https://pic.leetcode-cn.com/92ea472523892ec50f261a71889616ba4ba86490ae76a333efb4403b855acf2a-%E5%A5%87%E6%80%AA%E7%9A%84%E7%9F%A5%E8%AF%86%E5%A2%9E%E5%8A%A0%E4%BA%86.jpg)

例子：
3345
计算位数count = 4；border = 10^3 = 1000
分成两部分：0~999 1000~3345
第二部分最高位为1的个数：1000~1999、2000~2999、3000~3345 = 1000
第二部分其余位为1的个数：f(999)*2+f(345)
故一共的1的个数为：f(999) + 1000 + f(999)*2 + f(345) = f(border-1)*high + border + f(last);

同理：当第一位为1的时候：
1234：0~999、1000~1234
1的总数为：f(border-1) + last + 1 + f(last);


### 代码

```java
class Solution {
    public int countDigitOne(int n) {
        return f(n);
    }
    public int f(int n){
        if(n <= 0) return 0;
        int tmp = n;
        int count = 1;
        while(tmp/10 != 0){
            count ++;//计数位数
            tmp /= 10;
        }
        int border = (int) Math.pow(10, count-1);
        int high = n / border;//最高位
        int last = n % border;//除最高位，其余的数
        if(high != 1){
            return f(border-1)*high + border + f(last);
        }else{
            return f(border-1) + last + 1 + f(last);
        }
    }
}
```