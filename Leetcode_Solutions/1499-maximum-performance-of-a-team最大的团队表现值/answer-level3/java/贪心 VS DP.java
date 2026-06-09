### 解题思路
DP 也能解，时间复杂度为 O(n * k) ,在遇到 10w 量级时会超时。

### 贪心解法

```java
class Solution {
    
    public int maxPerformance(int n, int[] speed, int[] efficiency, int k) {
        long MOD = (long) Math.pow(10, 9) + 7L;
        int[][] A = new int[n][2];
        Queue<Integer> queue = new PriorityQueue<>(k, (a, b) -> a - b);
        long ans = 0L, sum = 0L;

        for(int i = 0; i < n; i++) {
            A[i] = new int[] {speed[i], efficiency[i]};    
        }
        Arrays.sort(A, (a, b) -> b[1] - a[1]);
        
        for(int[] a : A) {
            if(queue.size() == k) {
                sum -= queue.poll();
            }
            queue.add(a[0]);
            sum += a[0];
            ans = Math.max(ans, sum * a[1]);
        }
        
        return (int) (ans % MOD);
    }
}
```

### DP 解法

```java
public int maxPerformance(int n, int[] speed, int[] efficiency, int k) {
    // f[i][j] 以第 j 个工程师结尾的里找 i 个速度总和的最大值
    // f[i][j]  = max{ f[i-1][s]} + sp[j]  s>=0 & s <j
    // init: f[0][j]= 0  ans: max{f * eff[j]}  order: 递增
    long MOD = (long) Math.pow(10, 9) + 7L;
    int[][] A = new int[n][2];
    long[] f = new long[n];
    long ans = 0L;
    int i, j, s;

    Arrays.fill(f, 0L);
    for(i = 0; i < n; i++) {
        A[i] = new int[] {speed[i], efficiency[i]};    
    }
    Arrays.sort(A, (a, b) -> b[1] - a[1]);
    
    for(i = 1; i <= k; i++) {
        long max = 0L;
        for(j = 0; j < n; j++) {
            long temp = f[j]; 
            f[j] = max + A[j][0];
            ans = Math.max(ans, (f[j] * A[j][1])); // 易错点: 对ans mod 会让两个候选值比较大小时失衡。
            max = Math.max(max, temp); // 维护上一行 0...j 的最大值，供当前行的 j+1 时使用
        }
    }
    
    return (int) (ans % MOD);
}
```
