```
class Solution {
    public int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length-1;
        while(left<=right){//由边界来确定while条件
            int mid = (right+left)>>>1;
            if(nums[mid] ==target)//找到target返回索引
                return mid;
            if(nums[mid]<nums[right])//说明右半边有序
                if(nums[mid]<target&&target<=nums[right])//判断target是否在右半边区间
                    left = mid+1;//右半边查找
                else
                    right = mid -1;//左半边查找
            else//左半边有序
                if(nums[left]<=target&&target<nums[mid])//判断target是否在左半边区间
                    right = mid - 1;//左半边查找
                else
                    left = mid +1;//右半边查找
        }
        return -1;//找不到target返回-1
    }
}
```
