这道题我使用二分查找的第一种思路就是如果当前的这个数字小于它的后一个元素，那么它肯定不是峰顶，但是如果大于的话，那么它就可能是波峰，这样就诞生了第一个二分查找的模板代码
```
class Solution {
    public int peakIndexInMountainArray(int[] A) {
        int l=0;int r=A.length-1;
        while(l<r){
            int mid=r+l>>1;
            //如果这个数小于它右边的数，那它就一定不是山脉峰顶
            if(A[mid]<A[mid+1]){
                l=mid+1;
            //否则的话如果大于右边的数，那它可能是山脉峰顶
            }else{
                r=mid;
            }
        }
        return l;
    }
}
```
第二种思路当然就是反过来，如果当前的这个数字小于它的前一个元素，那么它就一定不是峰顶，如果大于它的前一个元素，那它就可能是峰顶,这样就有了第二种二分查找的模板代码
```
class Solution {
    public int peakIndexInMountainArray(int[] A) {
        int l=0;int r=A.length-1;
        while(l<r){
            int mid=r+l+1>>1;
            //如果这个数小于它左边的数，那它就一定不是山脉峰顶
            if(A[mid]<A[mid-1]){
                r=mid-1;
            //否则的话如果大于左边的数，那它可能是山脉峰顶
            }else{
                l=mid;
            }
        }
        return l;
    }
}
```