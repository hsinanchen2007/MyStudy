执行用时 :0 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗 :34.3 MB, 在所有 Java 提交中击败了48.92%的用户

![摆动序列.png](https://pic.leetcode-cn.com/3a7a1a3e0744131495e2aa841f42072af2e62ed18fe0a1be929797d133142a6f-%E6%91%86%E5%8A%A8%E5%BA%8F%E5%88%97.png)
**结论为：去掉所有处于非波峰或波谷的点结果就是最大波动点**
反证法证明
如图，假设Y1左边和Y7右边已经达到最大点。假设存在Y2是非波峰使得当前的四个有效点+1变为5个。
因为Y2>Y1。
又因为 Y2<Y3
所以 选择Y2 必然丢弃Y3.
而如果Y3丢弃之后的点有一条更好的路径，那么必然是Y1<Y2>Yxx。并且4个有效点+1变为5个。
那么Y1<Y3>yxx显然也能够出现结果为5个点。显然与已知的结论四个点矛盾。
```
 public int wiggleMaxLength(int[] nums) {
        if (nums.length < 1) {
            return 0;
        }
        int lastDir = 0;
        int suc = 1;
        int start = 0;
        int lastValidValue = nums[0];
        for (start = 1; start < nums.length; start++) {
            if (nums[start] != nums[start - 1]) {
                lastDir = nums[start] > nums[start - 1] ? 1 : -1;//斜率
                lastValidValue = nums[start];
                suc=suc+1;
                break;
            }
        }


        for (; start < nums.length; start++) {
            if (-1 * lastDir * (nums[start] - nums[start - 1]) > 0) {
                suc++;
                lastDir = -1 * lastDir;
            } lastValidValue = nums[start];
        }
        return suc;
    }
```
