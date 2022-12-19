### 解题思路
####快排思想

### 代码

```java
class Solution {
    
    public int[] getLeastNumbers(int[] arr, int k) {
        //方法1：函数：
        // Arrays.sort(arr);
        // return Arrays.copyOf(arr, k); 
       //方法2：使用快排（中枢值取二分）
    //    quick_sort(arr,0,arr.length-1,k);
    //    return Arrays.copyOf(arr,k);
       //方法3：快排（中枢值取start）---- 找j
        if (k == 0 || arr.length == 0) {
            return new int[0];
        }
        // 最后一个参数表示我们要找的是下标为k-1的数
        return quickSearch(arr, 0, arr.length - 1, k - 1);

    }
     public int[] quickSearch(int[] nums, int lo, int hi, int k) {
        // 每快排切分1次，找到排序后下标为j的元素，如果j恰好等于k就返回j以及j左边所有的数；
        int j = partition(nums, lo, hi);
        if (j == k) {
            return Arrays.copyOf(nums, j + 1);
        }
        // 否则根据下标j与k的大小关系来决定继续切分左段还是右段。
        return j > k? quickSearch(nums, lo, j - 1, k): quickSearch(nums, j + 1, hi, k);
    }

    // 快排切分，返回下标j，使得比nums[j]小的数都在j的左边，比nums[j]大的数都在j的右边。
    public int partition(int[] nums, int lo, int hi) {
        int v = nums[lo];
        int i = lo, j = hi + 1;
        while (true) {
            while (++i <= hi && nums[i] < v);
            while (--j >= lo && nums[j] > v);
            if (i >= j) {
                break;
            }
            int t = nums[j];
            nums[j] = nums[i];
            nums[i] = t;
        }
        nums[lo] = nums[j];
        nums[j] = v;
        return j;
    }
    public void quick_sort(int[] arr,int start,int end,int k){ //快速排序
       if(start==end){return;}
       int left=start;
       int right=end;
       int privot=arr[(left+right)/2];
       while(left<=right){
           while(left<=right&&arr[left]<privot){
               left++;
           }
           while(left<=right&&arr[right]>privot){
               right--;
           }
           if(left<=right){
               int temp=arr[left];
               arr[left]=arr[right];
               arr[right]=temp;
               left++;
               right--;
           }
       } 
       if(right>=k){
           quick_sort(arr,start,right,k);
       }
       else{
           quick_sort(arr,left,end,k);
       }       
    }
}
```