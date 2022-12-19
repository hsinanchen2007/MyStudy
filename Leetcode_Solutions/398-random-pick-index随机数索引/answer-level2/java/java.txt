执行用时 : 225 ms , 在所有Java提交中击败了 82.86% 的用户 内存消耗 : 73.8 MB , 在所有Java提交中击败了 40.32% 的用户


```java []

class Solution {
    
    private int[] n;
    private int x = 0;

    public Solution(int[] nums) {
        this.n = nums;
    }

    public int pick(int target) {
        do {
            if (x == n.length) {
                x = 0;
            }
        } while (n[x++] != target);
        return x - 1;
    }
}
```
