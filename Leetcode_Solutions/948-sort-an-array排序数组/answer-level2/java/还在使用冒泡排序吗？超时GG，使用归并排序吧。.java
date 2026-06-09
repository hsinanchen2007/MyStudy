### 解题思路
使用归并排序即可

### 代码

```java
class Solution {
    public int[] sortArray(int[] nums) {
        int[] temp = new int[nums.length];
        sort(nums,0,nums.length-1,temp);
        return nums;
    }

    private static void sort(int[] nums,int left,int right,int[] temp){
        if(left == right){
            return;
        }
        int mid = left + (right - left) / 2;
        sort(nums,left,mid,temp);
        sort(nums,mid + 1,right,temp);
        merge(nums,left,mid,right,temp);
    }

    private static void merge(int[] nums,int left,int mid, int right,int[] temp){
        int i = left;
        int j = mid + 1;
        int k = 0;

        while (i <= mid && j <= right){
            temp[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
        }

        while (i <= mid){
            temp[k++] = nums[i++];
        }
        while (j <= right){
            temp[k++] = nums[j++];
        }

        k = 0;

        while (left <= right){
            nums[left++] = temp[k++];
        }
    }
}
```