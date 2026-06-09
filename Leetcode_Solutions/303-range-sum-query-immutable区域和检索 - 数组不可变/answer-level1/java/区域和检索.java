### 解题思路
1.看清题目要求，多次调用sumRange()方法，为了减少空间限制，只需计算一次求和，然后记录下来即可。

### 代码

```java
class NumArray {
    private int[] sums;
    public NumArray(int[] nums) {
        sums=new int[nums.length];
        
        if(nums.length==0) return;
        sums[0]=nums[0];
        for(int i=1;i<nums.length;i++){
            sums[i]=sums[i-1]+nums[i];
        }
    }
    
    public int sumRange(int i, int j) {
        if(i==0) return sums[j];
        else{
            return sums[j]-sums[i-1];
        }
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
```