### 解题思路
很容易得到答案是所有质数的全排列与所有非质数全排列的乘积，
用筛法求质数的个数，
可以在乘积的过程中mod,不要等到最后再mod不然数会很大

### 代码

```java
class Solution {
 public int numPrimeArrangements(int n){
        /** 找出n以内的全部质数 */
        boolean [] arr=new boolean[n+1];
        Arrays.fill(arr,true);
        for(int i = 2;i*i <= n;i++){
            if(arr[i] == true) {
                for(int j = i*i;j <= n;j += i){
                    arr[j] = false;
                }
            }
        }

        int countPrime = 0;
        for(int i = 2;i <= n;i++){
            if(arr[i]) countPrime++;
        }
        int notCountPrime = n - countPrime;
        /** 质数的全排列乘以非质数的全排列 */
        long count=1;
        int min = Math.min(countPrime,notCountPrime);
        for(int i = 1;i <= min ;i ++){
            count = (count * i * i) % 1000000007;
        }
        for (int i = min+1; i <= Math.max(countPrime,notCountPrime) ; i++) {
            count = (count * i) % 1000000007;
        }
        return  (int)(count);
    }
}
```