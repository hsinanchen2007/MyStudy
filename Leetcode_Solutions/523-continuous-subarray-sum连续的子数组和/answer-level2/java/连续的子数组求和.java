### 方法一：暴力法（通过）
#### 思路：
我们可以将问题转化为求该数组中是否存在一个长度大于等于 $2$ 的子数组，其中所有数之和可以被 $k$ 整除，即 $sum\%k=0$。对于 $k=0$ 的特殊情形，我们单独讨论。对于求区间和的问题，我们很容易想到利用前缀和数组来优化其查询速度，参考 [前缀和](https://oi-wiki.org/basic/prefix-sum/)。

#### 算法：
- 预处理数据生成前缀和数组。
- 遍历查询所有子数组 $nums[i:j]$ 的和，并判断它 $\%k$ 是否等于 0，由于题目要求子数组长度大于等于 $2$，因此需要保证 $j-i >= 2$。
- 对于 k 等于 0 的情形我们进行特判，详情见代码。

```Java []
class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {        
        int N = nums.length;
        
        int[] sum = new int[N+1];
        for (int i = 0; i < N; i++)
        	sum[i+1] = sum[i] + nums[i];

        for (int i = 0; i < N; i++) {
            for (int j = i+2; j <= N; j++) {
                int res = sum[j] - sum[i];
        	if (k == 0) {
                    if (res == 0) return true;
                } else {
                    if (res % k == 0) return true;
                }
            }
        }
        return false;
    }
}
```

#### 复杂度分析：
- 时间复杂度：$O(N^2)$。
- 空间复杂度：$O(N)$。

### 方法二：哈希表
#### 思路：
在方法一中我们利用前缀和数组来求解问题，对于子数组 $nums[i:j]$ (不包含下标 j )，其区间和为 $sum[j] - sum[i]$ (其中 sum 为预处理得到的前缀和数组)，
- 我们要判断的是 $(sum[j] - sum[i])\%k$ 是否等于 0。
- 根据 $mod$ 运算的性质，我们知道 $(sum[j] - sum[i])\%k = sum[j]\%k - sum[i]\%k$。
- 故若想 $(sum[j] - sum[i])\%k = 0$，则必有 $sum[j]\%k = sum[i]\%k$。

#### 算法：
- 每当我们计算出一个前缀和 $sum[j]$ 时，我们判断哈希表中是否存在键值为 $sum[j]\%k$，若存在则有 $sum[j]\%k=sum[i]\%k$，我们返回 ${True}$。
- 由于我们需要控制子数组长度大于等 2，因此每次计算出的 $sum[j]\%k$ 的值，我们不能立即放入字典中，而是引入一个中间变量 $cache$ 缓存我们的值，待下一次计算时再加入字典，以保证满足条件的子数组长度至少为 $2$。
- 对 $k=0$ 的情形，我们需要特判。

```Java []
class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int N = nums.length, cache = 0;
        int[] sum = new int[N+1];
        HashSet<Integer> set = new HashSet<>();

        for (int i = 0; i < N; i++) {
            sum[i+1] = sum[i] + nums[i];
            int res = k == 0 ? sum[i+1] : sum[i+1] % k;
            if (set.contains(res)) return true;
            set.add(cache);
            cache = res;
        }
               
        return false;
    }
}
```

#### 复杂度分析：
- 时间复杂度：$O(N)$。
- 空间复杂度：$O(N)$。

