### 解题思路
此处撰写解题思路
需要一个辅助数组，将原始数组的前k个数的和进行保存，从求i到j时直接相减即可；且为了操作方便，辅助数组的维度为n+1，将第一个数初始为0，这样再求0到j的时候不会减去额外的第一个数。
### 代码

```java
class NumArray {
    int[] help;
    public NumArray(int[] nums) {
        help = new int[nums.length+1];
        for(int i = 1; i <= nums.length; i++){
            help[i] = nums[i-1];
            help[i] += help[i-1];
        }
    }
    
    public int sumRange(int i, int j) {
        return help[j+1] - help[i];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
```