### 解题思路
由于糖果分配符合$a_{i} = 1,2,3,..., a_{i-1}, a_{i}, a_{i+1}$的规律，
可以计算出分配糖果的和为 $a_{1} + a_{2} + ...+ a_{n} = 1+2+3+..+n = \frac{(n+1)n}{2} = candies$
$$=>\frac{n^2 + n}{2} = candies \\=> n^2 + n - 2*candies = 0$$
解一元二次方程的**正根**，可以计算出 
$$n(总分配次数) = -1 + \sqrt{\frac{1-4*(-2*candies))}{2}} $$

所以可以计算出一共分配了 `r` 到 `r+1`（边界情况） 轮
$$r = \frac{n}{num_{people}}$$

**算法流程**
1. 先计算前 `r` 轮的分配
    $ans[0] = 1 + (1+num_{people}) + (1 + 2*num_{people}) + ... + (1 + (r-1)*num_{people});$
    $=>ans[0] = 1 * r + num_{people} * \frac{r*(r-1)}{2};$
    $=>ans[i] = (i+1) * r + num_{people} * \frac{r * (r-1)}{2};$
2. 再遍历模拟单独处理 `r+1` 轮的分配

**复杂度分析**
* 时间复杂度 $O(N_{people})$
* 空间复杂度 $O(N_{people})$

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] ans = new int[num_people];
        // 计算出一共可以分配多少次糖果, 1+2+3+...+n = (n+1)n/2 = candies => n = (-1 + sqrt(1-4*(-2*candies)))/2
        int N = (int)((Math.sqrt(1.0+8.0*candies)-1)/2);
        // 一共可以分配多少轮糖果
        int round = N / num_people;
        // 处理边界数据
        int leftCandies = candies;
        //System.out.println(N + ", round=" + round);
        
        //先按照可以全部分完的整数分配
        for (int i = 0; i < num_people; ++i) {
            // for (int r = 0; r < round; ++ r) {
            //     ans[i] += (i+1) + r * num_people;
            // }
            ans[i] = (i+1) * round + num_people * round * (round-1)/2;
            leftCandies -= ans[i];
        }

        //最后一轮分配，按照剩余的糖果数分配
        int allotCandies = 1 + round * num_people;
        //System.out.println(leftCandies + ", allot=" + allotCandies);
        for (int i =0; i < num_people; ++i) {
            if (allotCandies <= leftCandies) {
                ans[i] += allotCandies;
                leftCandies -= allotCandies;
                allotCandies++;
            } else {
                ans[i] += leftCandies;
                break;
            }
        }
        return ans;
    }
}
```