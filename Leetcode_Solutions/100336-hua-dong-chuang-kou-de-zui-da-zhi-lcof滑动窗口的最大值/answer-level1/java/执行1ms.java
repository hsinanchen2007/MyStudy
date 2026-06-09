### 解题思路
1ms 双百分百=。=

### 代码

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if(nums.length==0)
            return new int[0];
        int[] A = new int[nums.length - k + 1];
        int posMax = -1;//指向当前最大值的有效位   比如4，2，3，5，1，2，3  k=3
                        //当前i是指向5的话，那么posmax指向5的后面的2
                        
        int max = 0;
        for (int i = 0; i < nums.length; i++) {
            if (posMax != -1 && nums[i] >= max) {
                A[i - k + 1] = nums[i];
                max = nums[i];
                posMax=i+k-1;
            } else if (i <= posMax) {
                A[i - k + 1] = max;
            } else {
                if(posMax==-1)
                    i=i+k-1;
                int start = i-k+1;
                int max1 = nums[start];
                int max_i = start;
                for (int l = start+1; l <= i; l++) {
                    if(nums[l]>=max1){
                        max1 = nums[l];
                        max_i = l;
                    }
                }
                max = max1;
                A[i - k + 1] = max1;
                posMax=max_i+k-1;
            }
        }
        return A;
    }
}
```