
#### 分治思想; 本题中使用分治的方法得到的不是众数, 那得到的是什么? 这么说吧, 如果某个元素出现的次数超过了长度的一半, 那么使用分治的思想一定可以得到这个数
再次强调: 某个元素出现的次数超过了长度的一半, 该算法才有效, 反例: {2,2,3,3,2,2,5,5}, 使用下面的算法返回的是5; 虽然众数是2, 但是2的出现次数没有大于数组长度的一半,所以算法失效了
```java
class Solution {
    public int majorityElement(int[] nums) {
        return core(nums, 0, nums.length-1);
    }
    private int core(int[] nums, int left, int right){
        //base case
        if(left==right)
            return nums[left];
        //
        int mid = left + ((right-left)>>1);
        int leftRes = core(nums, left, mid);
        int rightRes = core(nums, mid+1, right);
        if(leftRes == rightRes)
            return leftRes;
        int leftCount = count(nums, left, mid, leftRes);
        int rightCount = count(nums, mid+1, right, rightRes);
        return leftCount>rightCount? leftRes:rightRes;
    }
    private int count(int[] arr, int left, int right, int target){
        int count = 0;
        for(int i=left; i<=right; i++){
            if(arr[i] == target)
                count++;
        }
        return count;
    }
}
```


#### 位运算的思想: 如果一个数字的出现次数超过了数组长度的一半, 那么这个数字二进制的各个bit的出现次数同样超过了数组长度的一半
```java
class Solution {
    public int majorityElement(int[] nums) {
        int[] bit = new int[32];
        int n = nums.length;
        for(int a : nums){
            for(int i=0; i<32; i++){
                //无符号右移; 负数的无符号右移移动的是补码还是原码?
                if(((a>>>i) & 1) == 1)
                    bit[i]++;
            }
        }
        
        int res=0;
        for(int i=0; i<32; i++){
            if(bit[i]>n/2)
                res = res | (1<<i);
        }
        return res;
    }
}
```