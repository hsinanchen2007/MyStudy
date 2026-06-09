### 1. 题目思路
- $[start,end]$区间二分查找，得到指定元素的索引$mid$
    - 如果$mid=-1$，说明没有找到该元素，直接返回$[-1,-1]$
    - 否则，该元素在数组中，开始寻找其左边界与右边界
        - 初始化左边界$prev$，右边界$post$，值均为$mid$
        - $[start,prev-1]$区间二分查找，使用$last\_prev$记忆上一次查找得到的索引
            - $prev=-1$时，说明再也找不到了，此时$last\_prev$即为左边界
        - $[post+1,end]$区间二分查找，使用$last\_post$记忆上一次查找得到的索引
            - $post=-1$时，说明再也找不到了，此时$last\_post$即为右边界
        - 返回$[last\_prev,last\_post]$
### 2. Coding
```java
public int[] searchRange(int[] nums, int target) {
    int start = 0, end = nums.length - 1, mid = 0;
    if((mid = binarySearch(nums, start,end,target)) != -1){
        int prev = mid, post = mid, last_prev = prev, last_post = post;
        while(prev != -1){
            last_prev = prev;
            prev = binarySearch(nums, start, prev - 1, target);
        }
        while(post != -1){
            last_post = post;
            post = binarySearch(nums, post + 1, end, target);
        }
        return new int[]{last_prev, last_post};
    }
    else {
        return new int[]{-1, -1};
    }
}

private int binarySearch(int[] arr, int start, int end, int target){
    while(start <= end){
        int mid = (start + end) / 2;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] > target){
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return -1;
}
```
时间复杂度$O(logN)$，空间复杂度$O(1)$
### 3. 执行结果
![image.png](https://pic.leetcode-cn.com/09bd5e43c1d66eb8ad78c539883873adc0751ba8ea4bf7a60be4856d81137082-image.png)
