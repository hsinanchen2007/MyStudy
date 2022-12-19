### 解题思路
数字按位与，即所有数字里，某一位上只要有一个数字里是0，则最后结果里这一位就是0；
1. 首先，检查参数范围，不在范围内直接返回0；
2. 当只有一个数字时，按位与的值就是该数字；
3. 当m为0时，0与任何数字与都是0；
4. 如果范围内有一个数为2^a，那输出结果里除了第a位可能为1外，其他位就都是0；
5. 在4的基础上，如果里面还有一个数小于2^a，而小于2^a的数第a位上肯定是0；
6. 结合4/5分析得到：当[m,n]里包含2^a-1和2^a时，结果为0；即找到里n最近且小于n的2^a，如果m也小于2^a，则满足本条件，返回0；
7. 剩余的情况即2^a<=m<n<2^(a+1)，在此范围内的数字第a位一定为1,a以上的位一定为0，所以可以转换为：
2^a加上[m-2^a,n-2^a]按位与的结果。

### 代码

```java
class Solution {
    public int rangeBitwiseAnd(int m, int n) {
        if (m < 0 || n < m || n > 2147483647) {
            return 0;
        }
        if ((m == n) || (m == 0)) {
            return m;
        }
        int nNear = (int)Math.pow(2,(int)(Math.log(n)/Math.log(2)));
        if(m<nNear)
            return 0;
        return (nNear+rangeBitwiseAnd(m-nNear, n-nNear));
    }
}
```