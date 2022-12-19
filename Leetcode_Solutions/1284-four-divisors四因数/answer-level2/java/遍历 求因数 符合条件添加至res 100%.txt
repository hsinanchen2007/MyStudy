contest的时候把每个数的因数从1遍历到本身 所以超时了
打完比赛仔细想想其实遍历到开方就可以了 哎

```
class Solution {
    public int sumFourDivisors(int[] nums) {
        int res = 0;
        for (int i = 0; i < nums.length; i ++) {
            int sum = 0;
            int cnt = 0;
            int cur = nums[i];
            for (int j = 1; j * j <= cur; j ++) {
                if (cur % j == 0) {
                    cnt ++;
                    sum += j;
                    cnt ++;
                    sum += cur / j;
                }
                if (j * j == cur) {
                    cnt --;
                    sum -= j;
                }
            }
            if (cnt == 4) {
                res += sum;
            }
        }
        
        return res;
    }
}
```
