### 方法一：数学
#### 分析：
- 题目要求挑选出的子数组(不要求连续)的和能够被三整除，且最大。我们可以先贪心的累加所有数字的和，然后从中剔除一些数字使得其能够被三整除。
- 具体来说，如果整个数组的和恰好能够被三整除，那我们不需要做任何操作，直接返回。
- 如果最后的累加和$sum$ $mod$ $3$ $==$ $1$, 那我们可以有$2$种方式让其能够被$3$整除:
`1.剔除一个数组中满足mod3==1，且近可能小的数`
`2.剔除两个数组中满足mod3==2，且近可能小的数`
- 如果最后的累加和$sum$ $mod$ $3$ $==$ $2$, 那我们可以有$2$种方式让其能够被$3$整除:
`1.剔除一个数组中满足mod3==2，且近可能小的数`
`2.剔除两个数组中满足mod3==1，且近可能小的数`
- 最后的结果取上述方案中的最大值。

#### 代码实现

- 遍历数组，将$mod3=1$的数和$mod3=2$的数分别划分到对应的$list$中,同时计算所有数之和。
- 将两个$list$按从小到达排序。
- 判断所有数之和$mod3$运算的余数，再按照分析中的方法进行判断可能的最大值

```java []
class Solution {
    public int maxSumDivThree(int[] nums) {
        List<Integer> one = new ArrayList<>(); // 存放 mod3=1 的数
        List<Integer> two = new ArrayList<>(); // 存放 mod3=2 的数
        
        int sum = 0;
        for (int e : nums) {
            if (e % 3 == 1) one.add(e);
            if (e % 3 == 2) two.add(e);
            sum += e;
        }

        Collections.sort(one);
        Collections.sort(two);
        
        int res = sum % 3, ans = 0;
        
        if (res == 0) return sum;
        
        if (res == 1) {
            //剔除一个满足mod3==1的数， 或两个满足mod3==2的数
            if (two.size() >= 2) ans = Math.max(ans, sum-two.get(0)-two.get(1));
            if (one.size() >= 1) ans = Math.max(ans, sum-one.get(0));    
        } else if (res == 2) {
            //剔除一个满足mod3==2的数， 或两个满足mod3==1的数
            if (two.size() > 0) ans = Math.max(ans, sum-two.get(0));
            if (one.size() >= 2) ans = Math.max(ans, sum-one.get(0)-one.get(1)); 
        }
        return ans;
             
    }
}
```

#### 复杂度分析：

 - 时间复杂度： $O(NlogN)$ 其中$N$为数组长度，复杂度取决于代码中排序操作的时间复杂度
 - 空间复杂度： $O(N)$ 开辟的两个$list$所占用的空间