代码如下：
```
import java.util.*;
class Solution {
    public String getPermutation(int n, int k) {
        StringBuilder result = new StringBuilder();
        //1....n 是否被占用
        boolean[] hash = new boolean[n + 1];
        Arrays.fill(hash, false);
        //k-1表示在初始排序（最小值）基础上的第几个排序
        k = k - 1;
        for(int i = 0; i < n; i++) {
            /*factorial(n-i-1)表示在第i位的数字变大一级（后面还是最小排序），所增加的排序数
            如1234->1324 增加2个排序
             */
            //increase 表示该位需要变大几级；
            int increase = k / factorial(n - i - 1);
            //此时k表示在0...i位置确定值之后，在i+1...n-1保持最小排序的基础上需要增加的排序数
            k %= factorial(n - i - 1);
            for(int j = 1; j <= n; j++) {
                if(!hash[j]) {
                    if(increase == 0) {
                        hash[j] = true;
                        result.append((char)(j + '0'));
                        break;
                    }else increase --;
                }
            }
        }
        return result.toString();
    }

    //阶乘
    private int factorial(int n) {
        if(n < 0) return -1;
        if(n == 1 || n == 0)
            return 1;
        int result = 1;
        for(int i = 1; i <= n; i++) {
            result *= i;
        }
        return result;
    }
}
```

![截屏2020-01-13下午12.12.55.png](https://pic.leetcode-cn.com/ee008a725e6a5578bd6e421ad3fef0c9b7efc5d1a5bddb151ca6d702831b32af-%E6%88%AA%E5%B1%8F2020-01-13%E4%B8%8B%E5%8D%8812.12.55.png)
