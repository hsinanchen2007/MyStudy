### 解题思路
由于数组里数据量较大，不太适合用基数排序，用快排，快排的思想大家可以百度一下，主要有单指针和
双指针两种方式，本例中使用的是单指针方式
另外，有一个算法的图解网站，对一些常见算法有图解演示，大家对哪个算法的思想不是很清楚，可以看一下
https://www.cs.usfca.edu/~galles/visualization/Algorithms.html

### 代码

```java
class Solution {
    public int[] sortArray(int[] nums) {
        if(nums == null || nums.length <= 0) return nums;

        sortHelper(nums, 0, nums.length-1);
        return nums;
    }

    private void sortHelper(int[] nums, int s, int e){
        if(s >= e){
            return;
        }
        int mid = execute(nums, s, e);
        sortHelper(nums, s, mid-1);
        sortHelper(nums, mid+1, e);
    }

    private int execute(int[] nums, int s, int e){
        int point = s+1;
        int stand = nums[s];
        for(int i=s+1; i<=e; i++){
            if(nums[i] <= stand){
                swap(nums, i, point);
                point++;
            }
        }
        swap(nums, s, point-1);
        return point-1;
    }
    private void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
```