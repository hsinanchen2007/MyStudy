class Solution {
    public int findKthLargest(int[] nums, int k) {
        //最后一个参数为第k大元素在从小到大排序的情况下的第几个        
        return quickSortInternally(nums,0,nums.length-1,nums.length+1-k);
    }

    private static int quickSortInternally(int[] a,int p,int r,int k){
        if (p>=r){
            return a[k-1];
        }
        int q = partition(a,p,r);
        if (q+1 == k){
            return a[q];
        }else if (k < q+1){
            return quickSortInternally(a,p,q-1,k);
        }else {
            return quickSortInternally(a,q+1,r,k);
        }
    }
    private static int partition(int[] a, int p, int r) {
        int pivot = a[r];
        int i = p;
        for (int j=p;j<r;j++){
            if (a[j]<pivot){
                if (i==j){
                    i++;
                }else {
                    int tmp = a[i];
                    a[i++] = a[j];
                    a[j] = tmp;
                }
            }
        }

        int tmp = a[i];
        a[i] = a[r];
        a[r] = tmp;
        return i;
    }
}