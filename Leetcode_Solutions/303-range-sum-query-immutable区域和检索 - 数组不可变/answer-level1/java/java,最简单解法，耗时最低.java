### 解题思路
此处撰写解题思路

### 代码

```java
class NumArray {

    private int[] result;

    public NumArray(int[] nums) {
        result = new int[nums.length];
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            result[i]=sum;
        }
    }

    public int sumRange(int i, int j) {
        if(i>0){
            return result[j]-result[i-1];
        }else{
            return result[j];
        }
        
    }

}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
```