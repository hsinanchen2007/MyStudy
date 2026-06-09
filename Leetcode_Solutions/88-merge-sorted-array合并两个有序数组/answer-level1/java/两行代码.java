```
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        System.arraycopy(nums2,0,nums1,m,n);
        Arrays.sort(nums1);
          
    }
}
```
System.arraycopy(a,b,c,d,e);
 arraycopy方法中
        a：源数组，就是准备插入另一个数组的那个
        b:原数组的起始位置，默认为0开始；
        c:目标数组
        d:目标数组可以被插入的起始位置；
        e:目标数组的容量；
Array.sort()方法中，添加被排序数组名字，
        收工。