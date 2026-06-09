```
class Solution {
    private int findSmallOne(int a, int b) {
        if (a > 0 && b > 0 || a < 0 && b < 0)
            return Math.min(a, b);
        return a > 0 ? a : b;
    }
    
    private int findBigOne(int a, int b) {
        if (a > 0 && b > 0 || a < 0 && b < 0)
            return Math.max(a, b);
        return a < 0 ? a : b;
    }
    
    public int maxProduct(int[] nums) {
        if (nums.length == 0)
            return 0;
        
        int[] products = new int[nums.length + 1];
        int[] positive = new int[nums.length + 1];
        int[] negative = new int[nums.length + 1];
        boolean[] zeros = new boolean[nums.length + 1];
        products[0] = 1;
        positive[0] = 1;
        negative[0] = 1;
        zeros[0] = true;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0)
                zeros[i + 1] = true;
            if (nums[i] == 0)
                products[i + 1] = 1;
            else
                products[i + 1] = products[i] * nums[i];
        }
        for (int i = 1; i <= nums.length; i++) {
            if (zeros[i]) {
                positive[i] = 1;
                negative[i] = 1;
            } else {
                positive[i] = findSmallOne(products[i], positive[i - 1]);
                negative[i] = findBigOne(products[i], negative[i - 1]);
            }
        }
        int ret = nums[0];
        for (int i = 1; i <= nums.length; i++) {
            if (zeros[i])
                ret = Math.max(ret, 0);
            else {
                if (products[i] > 0)
                    ret = Math.max(ret, products[i] / positive[i - 1]);
                else
                    ret = Math.max(ret, products[i] / negative[i - 1]);
            }
        }
        return ret;
    }
}
```
