### 解题思路
归并排序

### 代码

```java
class Solution {
    public int reversePairs(int[] nums) {
        return mergeSortAndCountReversePairs(nums , 0 ,nums.length - 1) ;
    }

    public int mergeSortAndCountReversePairs(int[] nums , int start , int end) {
        if (start < end) {
            if (start + 1 == end) {
                if (nums[start] > nums[end]){
                    int temp = nums[start]  ;
                    nums[start] = nums[end] ;
                    nums[end] = temp ;
                    return 1 ;
                }else
                    return 0 ;
            }
            int mid = (start + end) >> 1 ;

            int leftRPairs = mergeSortAndCountReversePairs(nums,start,mid) ;
            int rightRPairs = mergeSortAndCountReversePairs(nums,mid+1,end) ;

            int reversePairsCount = 0 ;
            int i = start ;
            int j = mid + 1 ;
            int[] sorted = new int[end - start + 1] ;
            int k = 0 ;
            while (i <= mid && j <= end) {
                while (i <= mid && j <= end && nums[i] > nums[j]) {
                    sorted[k++] = nums[j++] ;
                    reversePairsCount += mid - i + 1 ;
                }
                while (i <= mid && j <= end && nums[i] <= nums[j]) {
                    sorted[k++] = nums[i++] ;
                }
            }
            while (i <= mid) {
                sorted[k++] = nums[i++] ;
            }
            while (j <= end) {
                sorted[k++] = nums[j++] ;   
            }

            for (int m=start ; m <= end ; m++) {
                nums[m] = sorted[m - start] ;
            }


            return reversePairsCount + leftRPairs + rightRPairs ;
            
        }else
            return 0 ;
    }


}
```