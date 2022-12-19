### long防止溢出！！！
**1.先判断是几位数字**
    //1位数 0-9 10个
    //2位数 10-99 90个 180位
    //3位数 100-999 900个 900*3 = 2700位
    //4位数 1000-9999 9000个 9000*4=36000位
    //m位数 m!=1 9*10^(m-1)*m位
    //首先判断n是几位数
**2.再判断是这几位数字的第几个以及第几个的第几位**
### 代码

```java
class Solution {
    public int findNthDigit(int n) {
        //1位数 0-9 10个
        //2位数 10-99 90个 180位
        //3位数 100-999 900个 900*3 = 2700位
        //4位数 1000-9999 9000个 9000*4=36000位
        //m位数 m!=1 9*10^(m-1)*m位
        //首先判断n是几位数
        if(n <= 9){
            return n;
        }
        int m = 2;
        long bottom = 9;
        long top = 9;
        while(true){
            bottom = top;                               
            top = bottom + 9*(long)Math.pow(10, m-1)*m;
            if(n > bottom && n <= top){
                break;
            }
            m++;
        }
        System.out.println(m);

        //求m位数字的第几个数字
        long gap = (n - bottom - 1) / m;//例如9 10 11 这样可以求出是第几位数字，下标从0开始
        long index = (n - bottom - 1) % m;//例如9 10 11 这样可以求出是第几位数字的第几个数字，下标从0开始
        long number  = (long)Math.pow(10, m-1) + gap;
        String str = String.valueOf(number);
        System.out.println(str);
        System.out.println(index);
        char ans = str.charAt((int)index);
        return Integer.valueOf(ans - '0');
    }
}
```