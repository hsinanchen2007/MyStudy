### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int in1=0;
        int in2=0;
        List<Integer> nums = new ArrayList<Integer>();
        while(in1<nums1.length&&in2<nums2.length){
            if(nums1[in1]<=nums2[in2]){
                nums.add(nums1[in1]);
                in1++;
            }
            else{
                nums.add(nums2[in2]);
                in2++;
            }
        }
        while(in1<nums1.length){
            nums.add(nums1[in1]);
            in1++;
        }
        while(in2<nums2.length){
            nums.add(nums2[in2]);
            in2++;
        }       
        int middle = nums.size()/2;
        if(nums.size()%2==0){
            return (nums.get(middle)+nums.get(middle-1))/2.0;
        }
        return nums.get(middle);

    }
}
```