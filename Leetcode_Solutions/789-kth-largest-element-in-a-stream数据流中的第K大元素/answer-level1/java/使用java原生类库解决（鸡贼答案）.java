### 解题思路
利用java的工具库Arrays的数组复制和排序功能

### 代码

```java
class KthLargest {

    private int[] nums;

    private int k;

    public KthLargest(int k, int[] nums) {
        this.k = k;
        this.nums = nums;
    }

    public int add(int val) {
        this.nums = Arrays.copyOf(this.nums,this.nums.length+1);
        this.nums[this.nums.length-1] = val;
        Arrays.sort(this.nums);
        if(k>=this.nums.length){
            return this.nums[0];
        }
        int tail = this.nums.length-1;
        for(int i=0;i<this.k;i++){
            tail--;
        }
        return this.nums[tail+1];
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
```