### 解题思路
此处撰写解题思路

### 代码

```java
class NumArray {
    
   private int [] arr;   
 public NumArray(int[] nums) {
     if(nums==null||nums.length==0) return;
     arr= new int[nums.length+1];
     arr[0]=nums[0];
     for(int i=1;i<nums.length;i++){
         arr[i]=arr[i-1]+nums[i];
     }}
    
    public int sumRange(int i, int j) {
            if(i==0){
            return arr[j];
        }else{

         return arr[j]-arr[i-1];
    }
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
```