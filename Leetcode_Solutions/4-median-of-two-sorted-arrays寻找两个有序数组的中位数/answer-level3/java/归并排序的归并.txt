### 解题思路
先排序再计算
### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int i = 0;
        int j = 0;
        int k = 0;
        int[] arr = new int[nums1.length + nums2.length];
        while(i < nums1.length && j< nums2.length){
            if(nums1[i] < nums2[j]){
                arr[k++] = nums1[i++];
            }else{
                arr[k++] = nums2[j++];
            }
        }
        while(i < nums1.length){
            arr[k++] = nums1[i++];
        }
        while(j < nums2.length){
            arr[k++] = nums2[j++];
        }
        boolean flag = (arr.length % 2 == 0);
        if(flag){
            int v = arr.length / 2;
            return (double)(arr[v] + arr[v-1])/2;
        }else{
            int v = arr.length / 2;
            return arr[v];
        }
    }
}
```