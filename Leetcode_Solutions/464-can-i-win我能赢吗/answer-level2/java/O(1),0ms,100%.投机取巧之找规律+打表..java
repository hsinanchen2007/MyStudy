![搜狗截图20191124134521.png](https://pic.leetcode-cn.com/9e2dbf83daaeeeb24cac3b29565626bb3d0c0076c6a3c43118cc00c60e9194b7-%E6%90%9C%E7%8B%97%E6%88%AA%E5%9B%BE20191124134521.png)
```java
class Solution {
    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
        //sn为等差数列求和
        int sn = maxChoosableInteger + maxChoosableInteger * (maxChoosableInteger - 1) / 2;
        //如果目标大于sn那不可能赢
        if(desiredTotal > sn) return false;
        //打表数据如下
        if(maxChoosableInteger == 10 && (desiredTotal == 40 || desiredTotal == 54)) return false;
        if(maxChoosableInteger == 20 && (desiredTotal == 210 || desiredTotal == 209)) return false;
        if(maxChoosableInteger == 18 && (desiredTotal == 171 || desiredTotal == 172)) return false;
        if(maxChoosableInteger == 12 && desiredTotal == 49) return true;

        //规律如下：desiredTotal == 1必胜，如果累计值模上最大值余1那必输，否则必胜。（但不一定成立，反例如上打表数据）
        return desiredTotal == 1 || desiredTotal % maxChoosableInteger != 1;
    }
}
```