二分查找相信大家都很熟悉流程 就是细节 一定要扣准
```
public int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length-1;
        int mid = (left+right)/2;
        int count = 0;
        boolean tag = false;
        while (left<=right&& !tag){
            if (nums[mid] == target){
                tag=true;
            }else {
                if (nums[mid]>target){
                    right = mid - 1 ;
                }else {
                    left = mid + 1;
                }
                mid = (left+right)/2;
            }
        }
        if (!tag){
            return 0;
        }else {
            int i = mid;
            while (i>=left&&nums[i]==target){
                count++;
                i--;
            }
            i = mid+1;
            while (i<=right&&nums[i]==target){
                count++;
                i++;
            }
        }
        return count;
}
```
