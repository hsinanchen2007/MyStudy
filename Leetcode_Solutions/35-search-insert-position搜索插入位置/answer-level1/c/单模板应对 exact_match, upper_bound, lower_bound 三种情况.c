二分查找法求解upper_bound, lower_bound查找问题, 一般用 "while(left < right)"的方式求解, 发现有很多弊端, 而且把问题复杂化.

这里给出一种用"while(left <= right)" 求解的方法.

最终, 所有的二分法问题都统一成如下简单模板.

该算法一开始令 [left, right] 为整个序列的下标区间, 注意是"[]", 而不是"[ )" 

int search(int* nums, int numsSize, int target){
    int left = 0, right = numsSize - 1;
    while(left <= right){
        int mid = (left & right) + ((left ^ right) >> 1);
        if(nums[mid] == target)
            return mid;    // target found, return the index
        else if(nums[mid] < target)
            left = mid + 1;
        else if(nums[mid] > target)
            right = mid - 1;
    }
    return -1;  // target not found
    //return right; // return the 1st value on target left side   (upper_bound) 
    // return left;  // return the 1st value on target right side  （lower_bound）
}
