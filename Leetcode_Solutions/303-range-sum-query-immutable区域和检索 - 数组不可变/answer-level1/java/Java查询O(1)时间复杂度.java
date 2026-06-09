平均下来时间复杂度是O(1)，超过99.82%
```java
class NumArray {

    private int[] sum;
    public NumArray(int[] nums) {
        sum = new int[nums.length+1];
        for(int i=1;i<=nums.length;i++){
            sum[i] = nums[i-1]+sum[i-1];
        }
    }
    
    public int sumRange(int i, int j) {
        return sum[j+1]-sum[i];
    }
}
```