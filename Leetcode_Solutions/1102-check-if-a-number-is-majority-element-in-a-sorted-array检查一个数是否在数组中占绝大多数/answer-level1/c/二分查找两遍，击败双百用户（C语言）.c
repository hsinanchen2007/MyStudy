// 二分查找，使用两遍分别找到该数的左边和右边匹配的位置，两数相减就可以算出来出现的个数，击败双100
int searchLeft(int * nums, int numsSize, int target)
{
    int l = 0;
    int r = numsSize - 1;
    int mid;
    
    while(l < r) {
        mid = (l + r) >> 1;
        if (nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    
    if (nums[l] == target) {
        return l;
    } else if (nums[r] == target) {
        return r;
    } 
        
    return -1;
}

int searchRight(int * nums, int numsSize, int target)
{
    int l = 0;
    int r = numsSize - 1;
    int mid;
    
    while(l < r) {
        mid = (l + r + 1) >> 1;
        if (nums[mid] > target) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }

    if (nums[l] == target) {
        return l;
    } else if (nums[r] == target) {
        return r;
    } else {
        return -1;
    }
}
bool isMajorityElement(int* nums, int numsSize, int target)
{
    int left;
    int right;
    if (numsSize == 0) {
        return false;
    }
    
    left = searchLeft(nums, numsSize, target);
    if ( left == -1) {
        return false;
    }
    right = searchRight(nums, numsSize, target);    
    
    if ((right - left + 1) > (numsSize / 2)) {
        return true;
    }
    return false;        
}