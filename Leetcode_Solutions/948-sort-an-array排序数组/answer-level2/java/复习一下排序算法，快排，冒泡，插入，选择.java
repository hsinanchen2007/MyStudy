### 通过情况：
* 快排是理想答案
* 插入排序勉强通过，1400+ms
* 冒泡排序最后一个测试用例超时
* 选择排序显示十个测试用例都通过，但是显示超时
### 代码

```java
class Solution {
    public int[] sortArray(int[] nums) {
        if(nums.length < 2){
            return nums;
        }
        quickSort(nums, 0, nums.length-1);
        //bubbleSort(nums);
        //selectSort(nums);
        //insertSort(nums);
        return nums;
    }
    public void bubbleSort(int[] nums){
        for(int i=0; i<nums.length-1; i++){
            boolean flag = false;
            for(int j=0; j<nums.length-i-1; j++){
                if(nums[j+1]<nums[j]){
                    swap(nums, j, j+1);
                    flag = true;
                }
            }
            if(!flag){
                break;
            }
        }
    }

    public void selectSort(int[] nums){
        for(int i=0; i<nums.length-1; i++){
            int min = i;
            for(int j=i+1; j<nums.length; j++){
                min = nums[j]<nums[min]?j:min;
            }
            swap(nums, i, min);
        }
    }

    public void insertSort(int[] nums){
        for(int i=1; i<nums.length; i++){
            for(int j=i; j>0; j--){
                if(nums[j]<nums[j-1]){
                    swap(nums, j, j-1);
                }
            }
        }
    }

    public void quickSort(int[] nums, int left, int right){
        if(left < right){
            int index = partition(nums, left, right);
            quickSort(nums, left, index-1);
            quickSort(nums, index+1, right);
        }
    }
    public int partition(int[] nums, int start, int end){
        int flag = nums[start];
        int i = start;
        int j = end;
        while(i<j){
            while(i<j && nums[j]>=flag){
                j--;
            }
            swap(nums, i, j);
            while(i<j && nums[i]<=flag){
                i++;
            }
            swap(nums, i, j);
        }
        return i;
    }
    public void swap(int[] nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}
```