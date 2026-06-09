### 解题思路
哨兵节点没有像官网这样一直放在最末端。
这样容易出bug。还是官方的快排写得好。

### 代码

```java
class Solution {
    public int[] sortArray(int[] nums) {
        if(nums==null || nums.length<=1){
            return nums;
        }

        binarySort(nums,0, nums.length-1);

        return nums;
    }

    void binarySort(int[] nums, int low, int high){
        if(low >= high){
            return;
        }

        int origLow = low;
        int origHigh = high;

        //
        int sentinel = nums[low++];
        int mid = low;
        while(low <= high){
            if(nums[low] <= sentinel){
                nums[low-1] = nums[low];

                mid = low;
                low++;
            }else{
                swap(nums, low, high);

                high--;
                mid = high;
            }
        }
        nums[mid] = sentinel;

        //
        if(origLow<mid-1){
            binarySort(nums, origLow, mid-1);
        }
        if(mid+1<origHigh){
            binarySort(nums, mid+1, origHigh);
        }
    }

    void swap(int[] nums, int a, int b){
        if(a==b){
            return;
        }

        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
}
```