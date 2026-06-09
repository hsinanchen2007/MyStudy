1. 按照普通二分找到target的下标问mid
2. 分别处理当前left～mid-1   mid+1～right这两部分
3. 左边的继续二分，但是当找到target的时候不要停止寻找，继续向左边查找
4. 右边的继续二分，但是当找到target的时候不要停止寻找，继续向右边查找

```Java
class Solution {
    private void searchOnther(int[] nums,int[] result,int left,int right,int mid,int target){
        // left ~ mid-1
        int lastFoundInLeft = -1;
        int tmpRight = mid-1;
        while(left<=tmpRight){
            int m = (left+tmpRight)/2;
            if(nums[m] == target){
                lastFoundInLeft = m;
                tmpRight = m-1;
            }else if(nums[m] > target){
                tmpRight = m-1;
            }else{
                left = m+1;
            }
        }
        if(lastFoundInLeft!=-1) result[0] = lastFoundInLeft;

        // mid+1 ~ right
        int lastFoundInRight = -1;
        int tmpLeft = mid+1;
        while(tmpLeft<=right){
            int m = (tmpLeft+right)/2;
            if(nums[m] == target){
                lastFoundInRight = m;
                tmpLeft = m+1;
            }else if(nums[m] > target){
                right = m-1;
            }else{
                tmpLeft = m+1;
            }
        }
        if(lastFoundInRight!=-1) result[1] = lastFoundInRight;
    }
    public int[] searchRange(int[] nums, int target) {
        // 1 2 2 2 2 4 5 6  target=2
        // 1 4
        // 二分查找，找到之后，继续往左，往右查找
        // corner: target不存在
        // corner: target只存在一个
        // corner: target只出现在第一次查找的位置的一边

        int left = 0;
        int right = nums.length-1;

        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid] == target){
                //处理其他target
                int[] result = new int[]{mid,mid};
                searchOnther(nums,result,left,right,mid,target);
                return result;
            }else if(nums[mid] > target){
                right=mid-1;
            }else{
                left = mid+1;
            }
        }
        return new int[]{-1,-1};
        
        

    }
}
```

