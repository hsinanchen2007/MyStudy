从后往前计算，每一步之前先将分数倒转。

```
class Solution {
    public int[] fraction(int[] cont) {
        if (cont == null || cont.length == 0) {
            return new int[2];
        }
        
        int[] ans = new int[2];
        
        for (int i = cont.length - 1; i >= 0; i--) {
            if (i == cont.length - 1) {
                ans[0] = cont[i];
                ans[1] = 1;
            } else {
                swap(ans, 0, 1);
                ans[0] += cont[i] * ans[1];
            }
        }
        return ans;
    }
    
    private void swap(int[] nums, int a, int b) {
        int tem = nums[a];
        nums[a] = nums[b];
        nums[b] = tem;
    }
}
```
