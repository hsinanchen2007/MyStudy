### 解题思路
    先copy一份数组，然后给排序一下，用二分查找找到每个元素在排好序数组中的位置，位置是多少，前面就有几个比它小的，如果有重复的就往左循环移动。

### 代码

```java
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] res = new int[nums.length];
        int[] copy = Arrays.copyOf(nums,nums.length);
        Arrays.sort(copy);
        for (int i = 0; i < res.length; i++) {
            int pos = recursionBinarySearch(copy,nums[i],0,nums.length-1);
            while (pos -1 >= 0 && copy[pos - 1] == copy[pos]){
                pos--;
            }
            res[i] = pos;
        }

        return res;
    }

    public static int recursionBinarySearch(int[] arr,int key,int low,int high){

        if(key < arr[low] || key > arr[high] || low > high){
            return -1;
        }

        int middle = (low + high) / 2;			//初始中间位置
        if(arr[middle] > key){
            //比关键字大则关键字在左区域
            return recursionBinarySearch(arr, key, low, middle - 1);
        }else if(arr[middle] < key){
            //比关键字小则关键字在右区域
            return recursionBinarySearch(arr, key, middle + 1, high);
        }else {
            return middle;
        }

    }
}
```