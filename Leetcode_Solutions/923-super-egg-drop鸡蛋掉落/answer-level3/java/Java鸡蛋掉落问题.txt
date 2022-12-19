解法一：状态转移求解鸡蛋掉落问题
```
class Solution {
    public int superEggDrop(int K, int N) {
        int i=1;
        while(g(i,K)<N){
            i++;
        }
        return i;
    }
    public int g(int i, int K) {
        return (i == 1 || K == 1) ? i : g(i - 1, K - 1) + g(i - 1, K) + 1;
    }
}
```

解法二：用O(n)的辅助空间优化时间复杂度
1ms,100%
```
class Solution {
    public int superEggDrop(int K, int N) {
        int[] res=new int[K];
        Arrays.fill(res,1);
        while (res[K-1]<N){
            for (int i=K-1;i>=1;i--){
                res[i]=res[i]+res[i-1]+1;
            }
            res[0]++;
        }
        return res[0];
    }
}
```