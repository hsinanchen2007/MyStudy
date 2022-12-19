注意在索引后移时，res[idx[j]] * primes[j]是最小值min的所有索引位置j都要+1。
```java
class Solution {
    public int nthSuperUglyNumber(int n, int[] primes) {
        //idx保存每个primes中的值下次要做乘法的res数组中的数的位置指针
        int[] idx = new int[primes.length];
        int[] res = new int[n];
        res[0] = 1;
        for(int i = 1; i < n; i++) {
            int min = Integer.MAX_VALUE;
            List<Integer> idxNeedIncrease = new LinkedList<>();
            for(int j = 0; j < primes.length; j++) {
                if(res[idx[j]] * primes[j] < min) {
                    min = res[idx[j]] * primes[j];
                    idxNeedIncrease.clear();
                    idxNeedIncrease.add(j);
                }
                else if(res[idx[j]] * primes[j] == min) {
                    idxNeedIncrease.add(j);
                }
            }
            res[i] = min;
            for(int idxInc : idxNeedIncrease) {
                idx[idxInc]++;
            }
        }
        return res[n - 1];
    }
}
```