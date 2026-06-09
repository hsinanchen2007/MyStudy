### 解题思路
1.索引左侧值：索引到结果后，依据相邻左侧值判断是否当前值为结果值
2.索引右侧值：索引到结果后，依据相邻右侧值判断当前值是否为结果值

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        //数组无元素时直接返回结果
        if(nums.length == 0){
            return new int[]{-1,-1};
        }
        //递归索引左下标
        int left = indexLeft(nums , 0 , nums.length -1,target);

        if(left == -1){
            //左下标为-1时，意味着不存在目标值，直接返回
            return new int[]{-1,-1};
        }else{
            //递归索引右下标
            int right = indexRight(nums , left,nums.length -1,target);
            return new int[]{left,right};
        }
    }

    /**
    * left 为索引开始位置，right为索引结束位置
    **/
    private int indexLeft(int[] nums , int left , int right , int target){
        int mid = (left + right)/2 ;
        if(nums[mid] == target && (mid -1 < 0 || nums[mid -1] != target)){
            //中间值为目标值，且此时左侧没有元素或者左侧元素不等于目标值，判定mid为左侧的索引
            return mid ;
        }else if(left >= right){
            //索引起始位置交差重叠，未索引到目标值
            return -1;
        }else if(nums[mid] >= target){//等于的情况下依据第一个判断，知道mid -1索引位置也为目标值
            //目标值再中间值的右侧，向左侧递归索引
            return indexLeft(nums , left , mid -1, target);
        }else{
            //目标值再中间值的左侧，向右侧递归索引
            return indexLeft(nums , mid +1 , right , target);
        }
    }

    private int indexRight(int[] nums , int left , int right , int target){

        int mid = (left + right)/2 ;
        if(nums[mid] == target && (mid +1 > nums.length -1 || nums[mid +1] != target)){
            //中间值为目标值，且此时右侧没有元素或者右侧元素不等于目标值，判定mid为右侧的索引
            return mid ;
        }else if(left >= right){
            return -1 ;
        }else if(nums[mid] > target){
            return indexRight(nums , left , mid -1, target);
        }else{
            return indexRight(nums,mid +1,right,target);
        }
    }
}
```