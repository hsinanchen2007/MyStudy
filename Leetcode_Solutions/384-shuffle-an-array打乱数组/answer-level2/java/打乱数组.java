### 解题思路


### 代码

```java
class Solution {
        static int originalarr[];
        static int resarr[];

        public Solution(int[] nums) {
                this.originalarr = nums.clone();
                this.resarr = nums;
        }

        /** Resets the array to its original configuration and return it. */
        public int[] reset() {
                return originalarr;

        }

        /** Returns a random shuffling of the array. */
        public int[] shuffle() {
                int len = resarr.length;
                Random random = new Random();
                
                for (int i = 0; i < len; i++) {
                int a = random.nextInt(len) ;
                int tmp = resarr[i];
                resarr[i] = resarr[a];
                resarr[a] = tmp;

                }                                                                                                                           
        return resarr;

        }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */
```