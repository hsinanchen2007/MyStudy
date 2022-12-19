题解有很多下面的解法
```cpp
int search(vector<int>& nums, int target) {
    int left = 0;
    int right = (int)nums.size() - 1;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] >= nums[left]) {
            //为啥>=  [3 1] 1
            //只有在2个数的情况下  mid = left
            //说明左半部分是单调递增的7 8 9 0 1
            if (target >= nums[left] && target < nums[mid]) {//7 8
                right = mid - 1;
            }else{//0 1
                left = mid + 1;
            }
        }else{
            //说明右半部分是单调递增的7 8 9 0 1 2 3 4 5
            if (target > nums[mid] && target <= nums[right]) { //2 3 4 5
                left = mid + 1;
            }else{//7 8 9 0
                right = mid - 1;
            }
        }
    }
    return -1;
}
```

但是很多不明白nums[mid] >= nums[left] 而不是nums[mid] > nums[left]
上面的代码注释我也给出了解释

如果还是看不懂
换一种方法

```cpp
int search(vector<int>& nums, int target) {
    int left = 0;
    int right = (int)nums.size() - 1;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] > nums[left]) {
            //说明左半部分是单调递增的7 8 9 0 1
            if (target >= nums[left] && target < nums[mid]) {//7 8
                right = mid - 1;
            }else{//0 1
                left = mid + 1;
            }
        }else if (nums[mid] < nums[left]) {
            //说明右半部分是单调递增的7 8 9 0 1 2 3 4 5
            if (target > nums[mid] && target <= nums[right]) { //2 3 4 5
                left = mid + 1;
            }else{//7 8 9 0
                right = mid - 1;
            }
        }else{
            //[3,1] target = 1 nums[mid] = 3 不是我们需要的，且left = mid = 0，所以left也不是，所以过滤left->left++
            left++;
        }
    }
    return -1;
}
```

我们可以在最后的else里面判断nums[mid] == nums[left]的情况 也就是[3,1] target = 1
这时候nums[mid] = 3 不是我们需要的，且left = mid = 0，所以left也不是，所以过滤left,让left++

同时方法二 [通过第81题 搜索旋转排序数组 II](https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/)

最后补充一下方法二的递归解法
```cpp
int search1_(vector<int>& nums,int start,int end,int target){
    if(end < start)  return -1;

    int low = start;
    int high = end;
    int mid = low + ((high - low) >> 1);
    
    if (target == nums[mid]) {
        return mid;
    }
    
    if (nums[low] < nums[mid]) {
        if (target >= nums[low] && target < nums[mid]) {
            //单调递增区间 7,8,9,10,0,1 中的7,8,9
            return search1_(nums, low, mid - 1, target);
        }else{
            //这边无序 7,8,9,10,0,1 中的10,0,1
            return search1_(nums, mid + 1, end, target);
        }
    }else if(nums[low] > nums[mid]){
        //最小值在右边 7,8,9,0,1,2,3,4,5,6
        if (target > nums[mid] && target <= nums[end] ){
            //是个单调递增区间 7,8,9,0,1,2,3,4,5,6 中的1,2,3,4,5,6
            return search1_(nums, mid + 1, end, target);
        }else{
            //这边无序 7,8,9,0,1,2,3,4,5,6 中的7,8,9,0
            return search1_(nums, start, mid - 1, target);
        }
    }else{
        //[3,1] target = 1 nums[mid] = 3 不是我们需要的，且left = mid = 0，所以left也不是，所以过滤left->left++
        return search1_(nums, mid + 1, end, target);
    }
}

int search1(vector<int>& nums, int target) {
    return search1_(nums, 0, (int)nums.size() - 1, target);
}
    
```
