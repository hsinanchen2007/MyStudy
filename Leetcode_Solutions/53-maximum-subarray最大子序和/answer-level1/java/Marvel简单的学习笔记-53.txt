## 官方题解的解法二三其实是同一种解法。
看完下面就知道为什么这么说了。

### 动态规划
用变量$cur$记录元素作为序列末尾时能得到的最大子列和。
从下标0开始，nums[0]作为序列末尾能得到的最大子列和只能是它本身，记为$cur0$。
接下来是下标1，nums[1]作为序列末尾时能得到的最大子列和$cur1$为：
$cur1 = max(nums[1], nums[1] + cur0)$
类推下去，可以得到下标为i的元素作为序列结尾时能得到的最大子列和为：
$curi = max(nums[i], nums[i] + cur(i-1))$
这就是状态转移方程，$curi$为问题的状态，该状态被转移为$cur(i-1)$。而$cur0 = nums[0]$为边界。
**动态规划就是这样从边界出发，通过状态转移方程求解问题**。
以上就是本法的核心内容。

代码：
```java
class Solution {
    public int maxSubArray(int[] nums) {
        int cur = nums[0];
        int sum = cur;
        for(int i = 1; i < nums.length; i++)
        {
            cur = Math.max(nums[i], nums[i] + cur);
            sum = Math.max(sum, cur);
        }
        return sum;
    }
}
```
上面是根据核心内容写出来的代码，也就是官方解法二。
下面是官方解法三：
```java
class Solution {
    public int maxSubArray(int[] nums) {
        int sum = nums[0];
        for(int i = 1; i < nums.length; i++)
        {
            if(nums[i - 1] > 0) 
                nums[i] += nums[i - 1];
            sum = Math.max(sum, nums[i]);
        }
        return sum;
    }
}
```
为什么说上面两种解法都是一样的？
其实解法三也是不断地求cur，即每个元素作为序列末尾时能得到的最大和。
只不过解法三中cur求出来后直接存到数组nums[]中了，即curi的结果直接存到nums[i]中。即循环结束后，数组中的每个元素代表的是原来这个位置的元素作为序列末尾时能得到的最大和。
因此解法三代码也可以这样写：
```java
class Solution {
    public int maxSubArray(int[] nums) {
        int cur = nums[0];
        int sum = cur;
        for(int i = 1; i < nums.length; i++)
        {
            if(cur > 0) cur += nums[i];
            else        cur = nums[i];
            sum = Math.max(sum, cur);
        }
        return sum;
    }
}
```
官方解法三中就是把上面代码的cur存到了原数组nums[]中。
为什么说它和官方解法二是一样的呢？将它和官方解法二对比，可以发现，不同的地方在于：
```java
//官方解法二
cur = Math.max(nums[i], nums[i] + cur);

//官方解法三
if(cur > 0) cur += nums[i];
else        cur = nums[i];
```
解法二中，cur取nums[i]和nums[i] + cur中的较大者，只有当cur大于0，才会取后者，即`cur = nums[i] + cur;`
解法三中，也是只有当cur大于0，`cur = cur + nums[i];`，其余情况`cur = nums[i];`。
因此两者的实质是一样的。

综上，重要的是理解动态规划的思想，但这只是第一步，接下来要辅以大量的练习和总结。