### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<Integer> sortArray(int[] nums) {
        // QuickSort(nums,0,nums.length-1);
        // List<Integer> res = new ArrayList<>();
        // for(int num:nums){
        //     res.add(num);
        // }
        Arrays.sort(nums);
        return Arrays.stream(nums).boxed().collect(Collectors.toList());
    }
    // private void QuickSort(int[] nums,int start,int end){
    //     if(start < end){
    //         //定义一个基准交换值
    //         int mid = (start + end)/2;
    //         // int random = (int) (start + Math.random() * (end - start + 1));
    //         int base = nums[mid];
    //         int i = start,j = end;
    //         while(i <= j){
    //             while((nums[i] < base) && (i < end))
    //                 i++;
    //             while((nums[j] > base) && (j > start))
    //                 j--;
    //             if(i <= j){
    //                 swap(nums,i,j);
    //                 i++;
    //                 j--;
    //             }
    //         }
    //         if(start < j)
    //             QuickSort(nums,start,j);
    //         if(end > i)
    //             QuickSort(nums,i,end);
    //     }
    // }
    // private void swap(int[] nums,int i,int j){
    //     int temp = nums[i];
    //     nums[i] = nums[j];
    //     nums[j] = temp;
    // }
}
```