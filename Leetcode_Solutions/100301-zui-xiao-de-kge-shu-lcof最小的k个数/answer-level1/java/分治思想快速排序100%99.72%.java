运用分治算法，即快速排序思想：首先以第一个元素a为准，划分数组为前后两部分，前半部分元素全部小于等于a，后半部分全部大于等于a。如果前半部分数据个数大于k，则递归，在前面部分取前k大的数；如果前半部分数据个数小于k，再递归，在后半部分取前（k - 前半部分数据个数）小的数。最后，取原数组前k个数即为解。
```
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        int[] res = new int[k];
        if(k == 0){
            return res;
        }
        partGet(arr, k, 0, arr.length - 1);
        System.arraycopy(arr, 0, res, 0, k);
        return res;
    }
     public void partGet(int[] arr, int k, int left, int right){
         int i = left, j = right;
         int mid = arr[left];
         while(i < j){
             for(; j > i && arr[j] > mid; j--);
             if(j > i){
                 arr[i] = arr[j];
                 i++;
             }
             for(; i < j && arr[i] < mid; i++);
             if(i < j){
                 arr[j] = arr[i];
                 j--;
             }
         }
         arr[i] = mid;
         int len = i - left + 1;
         if(i - left + 1 < k){
             partGet(arr, k - (i - left + 1), i + 1, right);
         }
         if(i - left > k){
             partGet(arr, k, left, i - 1);
         }
     }
}

```
