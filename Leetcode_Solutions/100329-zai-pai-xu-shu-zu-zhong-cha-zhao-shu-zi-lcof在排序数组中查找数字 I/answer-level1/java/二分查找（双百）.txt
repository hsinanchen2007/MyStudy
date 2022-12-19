```
class Solution {
    public int search(int[] nums, int target) {
        return binarySearch(nums, target);
    }

    public int binarySearch(int[] nums, int target){
        int l = 0, r = nums.length-1;
        int mid = 0;
        boolean flag = false;
        while(l <= r){
            mid = (l + r) / 2;
            if (nums[mid] == target){
                flag = true;
                break;
            }else if(nums[mid] < target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        if (flag){
            int sum = 1;
            int tmp = mid - 1;
            while(tmp >= 0 && nums[tmp] == target) {
                sum++;
                tmp--;
            }
            tmp = mid + 1;
            while(tmp <= nums.length - 1 && nums[tmp] == target){
                sum++;
                tmp++;
            }
            return sum;
        }
        else return 0;
    }
}
```
