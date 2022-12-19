### 解题思路
此处撰写解题思路

### 代码

```java
class NumArray {
    // 用于储存从下标0到指定下标的所有元素的和
    private int[] sum;
    private int n;

    public NumArray(int[] nums) {
        this.n = nums.length;
        this.sum = new int[n+1];
        // sum[n]不包含n项
        this.sum[0] = 0;
        for(int i = 1; i <= n; i++){
            this.sum[i] = this.sum[i-1] + nums[i-1];
        }
    }
    
    public int sumRange(int i, int j) {
        if(i < 0 || j >= n){
            return 0;
        }
        // 前j项和减去前i-1项和
        return sum[j+1] - sum[i];

    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
```