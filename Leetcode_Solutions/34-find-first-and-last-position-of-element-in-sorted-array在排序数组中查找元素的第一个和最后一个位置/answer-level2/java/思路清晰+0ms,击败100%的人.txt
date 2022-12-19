解题思路：首先通过二分法找到该target的位置，如果没有找到则返回-1，如果找到则再次通过二分法找target的边界值，
总共两次，一次找左边的边界值，一次找右边的边界值
```
class Solution {
    public int searchRange(int[] nums, int target,int type) {
        int start = 0,end = nums.length - 1;
        while(start <= end){
            int mid =(start + end) >> 1;
            if(nums[mid] == target){//二分法
                //type == 1代表该次寻找左边的边界值
                int val = type == 1 ? mid - 1 : mid + 1;
                //如果该值的下一个或者上一个恰好不等于该target则找到该边界值的下标，注意这里记得处理边界情况
                if(val < 0 || val >= nums.length || nums[val] != target){
                    return mid;
                }else{
                    if(type == 1)
                        end = val;
                    else
                        start = val;
                }
            }else if(nums[mid] > target){//二分法
                end = mid - 1;
            }else {//二分法
                start = mid + 1;
            }
        }
        return -1;
    }

    public int[] searchRange(int[] nums,int target){
        int[] res = new int[]{-1,-1};
        //找左边的边界值
        res[0] = searchRange(nums,target,1);
        //找右边的边界值
        res[1] = searchRange(nums,target,2);
        return res;
    }
}
```
