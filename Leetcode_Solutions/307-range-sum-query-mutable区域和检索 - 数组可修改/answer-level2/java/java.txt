### 解题思路
这一题也可以像之前有一道题的智能计算一样解决求和问题。设置一个dp数组，然后做减法就好了。

### 代码

```java
class NumArray {
    private int[] nums;
    public NumArray(int[] nums) {
        this.nums = nums;
    }
    
    public void update(int i, int val) {
        this.nums[i] = val;
    }
    
    public int sumRange(int i, int j) {
        int sum = 0;
        for(; i <= j; i++){
            sum += this.nums[i];
        }
        return sum;
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
```