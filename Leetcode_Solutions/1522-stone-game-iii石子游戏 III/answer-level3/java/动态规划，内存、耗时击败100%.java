### 解题思路
关键点就是从末尾反向往前推是无后效性的。
假设当第i堆石头由Alice来取时Alice的最大优势为dpAlice[i],那么Alice可以在取第i堆时可以分别考虑取1-3堆，取完之后就是Bob取，那么Alice考虑Bob的最优策略即可，
所以，再假设dpBob[i]为Bob在取第i堆时Alice的优势，因此Bob应该考虑让dpBob[i]的值越小越好，负数的话就是Bob一定会胜出。
dpAlice[i]=max(dpBob[i+1]+stoneValue[i],dpBob[i+2]+stoneValue[i]+stoneValue[i+1],dpBob[i+3]+stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]);
dpBob[i]=min(dpAlice[i+1]-stoneValue[i],dpAlice[i+2]-stoneValue[i]-stoneValue[i+1],dpAlice[i+3]-stoneValue[i]-stoneValue[i+1]-stoneValue[i+2]);
时间复杂度O(n)
代码其实还可以优化一下，dpAlice和dpBob都可以用三个变量来存，完全不需要用数组，空间复杂度就O(1)了。
### 代码

```java
class Solution {
    public String stoneGameIII(int[] stoneValue) {
        int[] dpAlice = new int[stoneValue.length + 1];
        int[] dpBob = new int[stoneValue.length + 1];
        Arrays.fill(dpAlice, Integer.MIN_VALUE);
        Arrays.fill(dpBob, Integer.MAX_VALUE);
        dpAlice[stoneValue.length] = 0;
        dpBob[stoneValue.length] = 0;
        for (int i = 0; i < stoneValue.length; i++) {
            int ii = stoneValue.length - i - 1;
            int tsum = 0;
            for (int j = 0; j < 3 && ii + j < stoneValue.length; j++) {
                tsum += stoneValue[ii + j];
                dpAlice[ii] = Math.max(dpAlice[ii], dpBob[ii + j + 1] + tsum);
                dpBob[ii] = Math.min(dpBob[ii], dpAlice[ii + j + 1] - tsum);
            }
        }
        return dpAlice[0] == 0 ? "Tie" : (dpAlice[0] > 0 ? "Alice" : "Bob");
    }
}
```