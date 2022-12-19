### 解题思路
System.arraycopy(数组,数组起始位置,新数组,数组在新数组中的起始位置,数组长度);
### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] nums=new int[nums1.length+nums2.length];
        //第一个参数：要复制到新数组的数组，第二个参数：复制起始位置，
        //第三个参数：新数组，第四个是：新数组中的起始存放位置，第五个是：要复制到新数组中的数组长度。
        System.arraycopy(nums1,0,nums,0,nums1.length);
        System.arraycopy(nums2,0,nums,nums1.length,nums2.length);
        Arrays.sort(nums);
        if(nums.length%2==0){
            return ((nums[nums.length/2]+nums[(nums.length/2)-1])/2.0);
        }else{
            return nums[nums.length/2];
        }
    }
}
```