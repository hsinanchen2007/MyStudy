![Snipaste_2020-03-11_12-28-37.png](https://pic.leetcode-cn.com/14d1e7421816af45e93fc46cb480248565a8b2cff0c5b9dc38e4583d3f8cc76d-Snipaste_2020-03-11_12-28-37.png)

### 解题思路
这题其实题目也给了提示，我们最终的目的其实就是找到一个i值和j值，使得 `i<j-1`，并且0~i 和 j~len-1和ij中间的元素相等即可。那么首先，我们可以对数组整体求和，对于和不能被3整除的情况，那肯定是不符合的。然后我们求出每段需要达到的target。之后只需要设置一个指针i从数组头部开始遍历，一个指针j从数组尾部开始遍历即可，分别表示前后两段。i只能++，j只能--。而等到任何一段的和已经等于target时，那这一段就可以确定下来了，因为如果继续往后面加元素，那么要想达到最终的target值，后续所有加进来的元素的和还是必须为0，而对于这段和为0的元素，放在任何一段都是无所谓的。当 pre = target = post的时候，由于我们前面判断过数组总和可以被3整除，说明其实已经分成功了。返回true即可。
还有要注意的就是，题目中说明了三段不能为空，所以给中间位置必须要至少留一个元素，因此循环的终止条件是 i < j-1。

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        long sum = 0;
        for (int i : A)
            sum += i;
        if (sum % 3 != 0)
            return false;
        long target = sum / 3;
        long pre = A[0];
        long post = A[A.length-1];
        for (int i=0,j=A.length-1;i<j-1;){
            if (pre == target && post == target){
                return true;
            }else if (pre == target)
                post += A[--j];
            else if (post == target)
                pre += A[++i];
            else{
                pre += A[++i];
                post += A[--j];
            }
        }
        return false;
    }
}
```