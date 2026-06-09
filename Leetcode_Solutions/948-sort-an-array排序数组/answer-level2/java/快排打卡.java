### 解题思路
使用最简单的快速排序

### 代码

```java
class Solution {
    public static int[] sortArray(int[] nums) {
        int a[] = quickSort(nums,0,nums.length-1);
        return a;                               
    }

    public static int[] quickSort(int[] nums,int low,int high){
        if (low > high){
            return null;
        }
        int i = low;
        int j = high;
        int temp = nums[low];
        while(i<j){
            while(temp<=nums[j] && i<j){
                j--;
            }
            while(temp>=nums[i] && i<j){
                i++;
            }
            if(i<j){
                int z = nums[i];
                int y = nums[j];
                nums[j] = z;
                nums[i] = y;
            }
        }
        nums[low] = nums[j];
        nums[j] = temp;
        quickSort(nums,low,j-1);
        quickSort(nums,j+1,high);
        return nums;
    }
}
```