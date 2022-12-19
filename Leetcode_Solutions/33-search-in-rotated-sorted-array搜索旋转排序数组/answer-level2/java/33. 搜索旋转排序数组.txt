/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/11/6
 *
 * 解题思路: mid = (start + end)/2 ==> 使用 start < num[mid]来判断前半部分为升序,否则后半部分为升序,前半部分为升序,然后判断target在前半部分还是后半部分,进行start、end的更新
 *
 * 1.前半部分为升序:  start <= target < mid 搜索区间更新为前半部分 否则为半部分
 * 2.后半部分为升序:  mid < target < end 搜索区间更新为后半部分 否则为前半部分
 */
```
public int search(int[] nums, int target) {

    int start = 0;
    int end = nums.length-1;

    while(start <= end){

        int mid = (start + end)/2;

        if(nums[mid] == target){
            return mid;
        }

        //此处是等号 因为当出现 [4,1]等两个数值情况 mid=0 只有前半部分4是有序的 后半部分4,1时无序的
        if(nums[start] <= nums[mid]){
            //前半部分有序
            if(target >= nums[start] && target < nums[mid]){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }else{
            //后半部分有序
            if(target > nums[mid] && target <= nums[end]){
                start = mid + 1;
            }else{
                end = mid - 1;
            }

        }

    }
    return -1;
}
```