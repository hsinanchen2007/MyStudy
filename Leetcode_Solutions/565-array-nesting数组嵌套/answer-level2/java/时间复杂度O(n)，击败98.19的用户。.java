首先可以明确，这里面的嵌套关系构成循环序列。同一循环序列之内无论起点在何处，长度都是一样的。而不同的序列之间不会有交集。
基于上述事实，我们可以针对每一次扫描，对于已经扫过的数，直接变成-1。循环中，碰到-1的数就直接终止即可。
具体代码如下：

class Solution {
    public int arrayNesting(int[] nums) {
        int ans = 0;
        for (int i = 0; i < nums.length; i++) {
            int n = i;
            int count = 0;
            while ((n != -1) && (nums[n] != -1)){
                count++;
                int t = nums[n];
                nums[n] = -1;
                n = t;
            };
            if (count > ans) ans = count;
        };
        return ans;
    }
}