???还是接口什么的最香了
其实排序的算法有很多：
1. 选择排序
2. 冒泡排序
3. 归并排序
4. 快排
5. 堆排

### 接口

```java
class Solution {
    public int[] sortArray(int[] nums) {
        Arrays.sort(nums);
        return nums;
    }
}
```

### 堆排
时间复杂度：O（NlogN)
空间复杂度：O（1）
```
package sort;

/** 
 * time complexity:O(NlogN)
 * space complexity:O(1)
 */

class heapsort {

    public static int[] sortArray(int[] nums){
        int len = nums.length;
        // put arrays to heap'
        heapify(nums);
        for(int i = len - 1; i >= 1; ){
            swap(nums, 0, i);
            i--;
            siftDown(nums, 0, i);
        }
        return nums;
    }
    
    public static void heapify(int[] nums){
        int len = nums.length;
        for(int i = (len - 1) / 2; i >= 0; i--){
            siftDown(nums, i, len - 1);       
        }
    }

    private static void siftDown(int[] nums, int k, int end){
        while( 2 * k + 1 <= end){
            int j = 2 * k + 1;
            if( j + 1 <= end && nums[j + 1] > nums[j]){
                j++;
            }
            if(nums[j] > nums[k]){
                swap(nums, j, k);
            }else   break;   
            k = j;
        }
    }

    public static void swap(int[] nums, int index1, int index2){
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }

    public static void main(String[] args) {
        int[] nums = {12,4, 5, 7, 2, 100, 20, 90};
        int[] nums_new = sortArray(nums);
        for(int num: nums_new){
            System.out.print(num + " ");
        }
    }
}
```
