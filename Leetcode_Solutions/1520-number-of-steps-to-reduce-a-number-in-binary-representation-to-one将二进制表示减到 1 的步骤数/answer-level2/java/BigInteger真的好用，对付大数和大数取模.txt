今天又涨知识了，原来BigInteger可以进制转换，临时百度的，之前只知道大数取模很好用，就是不知道速度怎么样
```
import java.math.BigInteger;
class Solution {
    public int numSteps(String s) {
        int step=0;
        
        //二进制转换
        BigInteger b=new BigInteger(s,2);
        BigInteger one=new BigInteger("1");
        BigInteger two=new BigInteger("2");
        while (!b.equals(one)) {
            BigInteger mod=b.mod(two);
            if (!mod.equals(one)) {
                b=b.divide(two);
            } else {
                b=b.add(one);
            }
            step++;
        }

        return step;
    }
}
```
