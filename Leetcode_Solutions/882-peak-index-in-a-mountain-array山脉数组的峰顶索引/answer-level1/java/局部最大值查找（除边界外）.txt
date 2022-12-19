1.二分法：局部最大的特点为该点值大于其左右相邻的两点值，取中间位置的点，如果其小于右边点的值，则局部最大值在右半部分；若小于左边点的值，则局部最大值在左半部分；最后情况即该点为局部最大点。

    代码：
    public int peakIndexInMountainArray(int[] A) {
        int i=0;
        int j=A.length-1;
        int mid=0;
        while(i<=j){
            mid=(i+j)/2;
            if(A[mid]<A[mid+1]){
                i=mid+1;
            }else if(A[mid]<A[mid-1]){
                j=mid-1;
            }else{
                return mid;   
            }
        }
        return -1;
    }