### 方法一： 暴力法（超时）

#### 思路：
题目要求我们找到满足数组中所有元素之和能够被K整除的子数组的数量，对于求区间和的问题，我们很容易想到利用前缀和数组来优化其查询速度，参考[前缀和](https://oi-wiki.org/basic/prefix-sum/)。相似问题[523.连续的子数组和](https://leetcode-cn.com/problems/continuous-subarray-sum/)。

##### 算法：
- 预处理生成前缀和数组
- 利用前缀和数组枚举出所有子区间的和，判断其能否被K整除。

```Java []
class Solution {
    public int subarraysDivByK(int[] A, int K) {
        int N = A.length, ans = 0;
        int[] sum = new int[N+1];

        for (int i = 0; i < N; i++) {
        	sum[i+1] = sum[i] + A[i];
        }

        for (int i = 0; i < N; i++) {
        	for (int j = i+1; j <= N; j++) {
        		int res = sum[j] - sum[i];
        		if (res % K == 0) ans++; 
        	}
        }
        return ans ;
    }
}

```
#### 复杂度分析：
- 时间复杂度: $O(N^2)$
- 空间复杂度: $O(N)$

### 方法二：哈希表（通过）
#### 思路：
在方法一中我们利用前缀和数组来求解问题，对于子数组$nums[i:j]$(不包含下标$j$)，其区间和为$sum[j] - sum[i]$(其中$sum$为预处理得到的前缀和数组),
- 我们要判断的是$(sum[j] - sum[i])\%K$是否等于0。
- 根据$mod$运算的性质，我们知道$(sum[j] - sum[i])\%K = sum[j]\%K - sum[i]\%K$。
- 故若想$(sum[j] - sum[i])\%K = 0$，则必有$sum[j]\%K = sum[i]\%K$。
- 所有满足$nums[i:j]$中元素之和可以被K整除的开始下标$i$，必有$sum[j]\%K = sum[i]\%K$。我们以$sum[i]\%K$作为键值统计其出现的频率，从而对于每个下标$j$我们可以立即获得能和它组成满足要求的子数组的开始下标$i$的数量。

#### 算法：
- 生成前缀和数组的过程中，将$key = sum[j]\%k$ 出现的频率加入结果数组， 同时将 $key = sum[j]\%k$的出现频率加$1$。
- 由于数组中有可能出现负数，我们需要将其加$K$从而使其$\%K$之后的值为正数。
```java []
class Solution {
    public int subarraysDivByK(int[] A, int K) {
        int N = A.length, sum = 0, ans = 0;
        int[] map = new int[K];
        map[0] = 1;
        for (int i = 1; i <= N; i++) {
            sum = sum + A[i-1]; 
            int key = (sum % K + K) % K;
            ans += map[key];
            map[key]++;
        }
        return ans;
    }
}
```

#### 复杂度分析：
- 时间复杂度: $O(N)$
- 空间复杂度: $O(K)$
