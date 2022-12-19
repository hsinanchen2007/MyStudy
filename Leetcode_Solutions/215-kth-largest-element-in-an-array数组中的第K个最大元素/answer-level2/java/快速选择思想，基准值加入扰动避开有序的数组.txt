### 解题思路
执行用时 : 1 ms, 在所有 Java 提交中击败了99.98%的用户
这道题非常容易写错，终于写完了，debug花了我不少功夫，快速排序的写法也很多，感觉还是用partition最直观方便

### 代码

```java
class Solution {
    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];nums[i] = nums[j];nums[j] = temp;
    }
    private int partition(int[] array, int start, int end) {
        int i = start, j = end;
        swap(array, start, (start+end)/2);
        int temp = array[start];
        while (i != j) {
            while (array[j] <= temp && i < j) j--;
            while (array[i] >= temp && i < j) i++;
            if (i < j)
                swap(array, i, j);
        }
        swap(array, start, i);
        return i;
    }
    public int findKthLargest(int[] nums, int k) {
        int left = 0;
        int right = nums.length-1;
        while (left <= right) {
            int pos = partition(nums, left, right);
            if (pos == k-1) return nums[pos];
            else if (pos > k-1) right = pos-1;
            else left = pos+1;
        }
        return -1;
    }
}
```