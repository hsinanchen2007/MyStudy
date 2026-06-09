第一次写题解，老哥们捧个场~~~~/\ /\
归并排序，通过排序降低复杂度， 复杂度说明：根据递推式 T(n) = 2T(n/2) + 2n, 其中一个n为归并时的复杂度，另外一个n则是在比较得逆序数时的最坏情况。最后可得总的复杂度为T(n) = n + 2n*log(n)
```
class Solution {
    //定义全局变量，
    int count = 0; 
    public int reversePairs(int[] nums) {
        if(nums.length == 0){
            return 0;
        }
        mergesort(nums, 0, nums.length - 1);
        return count;
    }

    //归并排序与计数
    public void mergesort(int[] nums, int start, int end){
        int mid = (start + end) / 2;
        if(start == end){
            return ;
        }

        //对当前区间再分开
        mergesort(nums, start, mid);
        mergesort(nums, mid + 1, end);

        //将左右两部分拷贝出来进行赋值
        int[] left = new int[mid - start + 1];
        int[] right = new int[end - mid];
        for(int i = start; i <= mid; i++){
            left[i - start] = nums[i];
        }
        for(int i = mid + 1; i <= end; i++){
            right[i - (mid + 1)] = nums[i];
        }

        // 最为关键部分，由于是递归得到的左右数组，且每个数组都是有序的，下面开始计数
        int left_index = 0; int right_index = 0;
        int temp = 0;
        while(left_index < left.length && right_index < right.length){
            while(left[left_index] > right[right_index]) {  // 从左边起始位置开始与右边
                temp++;                                     // 数据进行比较，如果左边数
                right_index++;                              // 较大，则将temp加1，直到找到  
                if(right_index == right.length){           // 右边数组比左边数组大的数，更新
                    break;                                //左边数组的索引。
                }
            }
            count += temp * (left.length - left_index) ; //当当前左数组索引不满足后，对当前左
            temp = 0;                                    //数组得到的temp 加到总的count中，
            left_index++;                      //由于数组是有序的，这里将左边数组比当前索引大
        }                     //的值都可以加到count中，使得右边数组的索引可以不用回退，所以这在一                        //方面降低了复杂度，最后使得temp = 0; 开始下轮比较。
        
        // 下面没啥好说的，是归并排序中的排序，对左右数组归并
        int l = 0; int r = 0; int i = 0;
        for(i = start; i <= end; i++){
            if(l == mid - start + 1 || r == end - mid){
                break;
            }
            if(left[l] <= right[r]){
                nums[i] = left[l++];
            }
            else if(left[l] > right[r]){
                nums[i] = right[r++];
            }
        }
        while(i <= end && l <= mid - start){
            nums[i++] = left[l++];
        }
        while(i <= end && r < end - mid){
            nums[i++] = right[r++];
        }
    }
}
```
