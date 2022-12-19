思路写注释里了。
```
class Solution {
    public int search(int[] arr, int target) {
        return binarySearch(arr, target, 0, arr.length-1);
    }
    private int binarySearch(int[] arr, int target, int l, int r){
        if(l > r)
            return -1;
        if(l == r){
            if(target == arr[l])
                return l;
            else
                return -1;
        }
        int mid = l + (r - l) / 2;
        //如果左区间为升序的话
        if(arr[l] < arr[mid]){
            //target在左区间范围
            if(target <= arr[mid] && target >= arr[l])
                return binarySearch(arr, target, l, mid);
            else
                return binarySearch(arr, target, mid+1, r);
        }else if(arr[l] > arr[mid]){ //左区间不为升序
            //还是以左区间搜索为优先, 如果条件成立，target还是在左区间中
            if(target <= arr[mid] || target >= arr[l])
                return binarySearch(arr, target, l, mid);
            else
                return binarySearch(arr, target, mid+1, r);
        }else{
            //此时左区间两端点值相同，是最坏的情况两边都需要搜索
            //[5,5,5,5,5,2,3,4,5]或[5,2,3,4,5,5,5,5,5]如果搜索2的话
            //这两种情况左右区间都有可能存在，所以如果左区间找到了不为-1，就返回，否则返回右区间找的结果。
            //如果这种情况还有优化的余地希望告知一下
            int res = binarySearch(arr, target, l, mid);
            if(res != -1)
                return res;
            else
                return binarySearch(arr, target, mid+1, r);
        }
    }
}
```
