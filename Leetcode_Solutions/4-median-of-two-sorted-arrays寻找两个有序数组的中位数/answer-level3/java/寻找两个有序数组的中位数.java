### 解题思路
最笨的方法 复杂度不对
建大数组
循环一遍挨个往里面放

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int length1=nums1.length;
        int length2=nums2.length;
        int length=length1+length2;

        if(length1==0){
            if(length2%2==0){
                return (double)(nums2[length2/2-1]+nums2[length2/2])/2;
            }else{
                return nums2[(length2+1)/2-1];
            }
        }

        if(length2==0){
            if(length1%2==0){
                return (double)(nums1[length1/2-1]+nums1[length1/2])/2;
            }else{
                return nums1[(length1+1)/2-1];
            }
        }

        int[] nums=new int[length];
        int ptr1=0,ptr2=0;
        int val1=0,val2=0;
        int i=0;
        while(ptr1<length1 && ptr2<length2){
            nums[i]=Math.min(nums1[ptr1],nums2[ptr2]);
            i++;
            if(nums1[ptr1]<nums2[ptr2]){
                ptr1++;
            }else{
                ptr2++;
            }   
        }
        if(ptr1==length1){
            while(ptr2<length2){
                nums[i]=nums2[ptr2];
                i++;
                ptr2++;
            }
        }
        if(ptr2==length2){
            while(ptr1<length1){
                nums[i]=nums1[ptr1];
                i++;
                ptr1++;
            }
        }
        int j=0;
        while(j<length){
            //System.out.println(nums[j]);
            j++;
        } 
        if(length%2!=0){
            return nums[(length+1)/2-1];
        }else{
            return (double)(nums[length/2-1]+nums[length/2])/2;
        }
    }
}
```